#pragma once
#include "SDL.h"
#include "GameScreen.h"
#include <SDL_mixer.h>
#include <iostream>
#include "Quadtree.h"
#include "NumberUtility.h"
#include "BehaviourFactory.h"
#include "Map.h"
#include "KeyBinding.h"
#include "Zombie.h"
#include "TextureFactory.h"
#include "MapFactory.h"
#include "ScreenFactory.h"
#include <map>
#include "TutorialMap.h"
#include "Pistol.h"
#include "MachineGun.h"
#include "PlayableCharacter.h"
#include "GameMath.h"

GameScreen::GameScreen(SDL_Renderer* ren, vector<string> characterUrls, string mapUrl) : AbstractScreen(ren)
{
	defaultKeybindings.push_back(new KeyBinding{ SDLK_w, SDLK_a, SDLK_s, SDLK_d, SDLK_SPACE, SDLK_e, SDLK_q });
	defaultKeybindings.push_back(new KeyBinding{ SDLK_UP, SDLK_LEFT, SDLK_DOWN, SDLK_RIGHT, SDLK_RCTRL, SDLK_PAGEDOWN, SDLK_DELETE });
	characterImageUrls = characterUrls;

	// Get map
	if (mapUrl == "") 
	{
		map = MapFactory::GetInstance()->NextMap();
	}
	else 
	{
		isInfinityMode = true;
		map = new Map{ mapUrl };
	}

	tree = new Quadtree(map->GetBounds());

	gameObjectContainer = new GameObjectContainer{ map, tree };
	spawnController = SpawnController{ this };
	gameObjectContainer->SetMap(map);
	spawnController.SetMap(map);
	BehaviourFactory::Instance()->SetMap(map);

	hudVisitor = HudVisitor{ ren, map->GetBounds() };
	goFactory->SetContainers(
		&drawContainer,
		&animateContainer,
		&moveContainer,
		&actionContainer,
		&collideContainer,
		gameObjectContainer,
		ren
		);

	BehaviourFactory::Instance()->SetContainers(
		&drawContainer,
		&animateContainer,
		&moveContainer,
		&actionContainer,
		&collideContainer,
		gameObjectContainer,
		ren
		);

	for (int i = 0; i < characterImageUrls.size();i++)
	{
		players.push_back(goFactory->CreatePlayableCharacter(characterImageUrls.at(i), defaultKeybindings.at(i)));
	}

	int x = 500;
	int y = 200;
	for (auto& player : players)
	{
		player->SetGameScreen(this);
		player->SetPosition(x, y);
		spawnController.AddTarget(player);
		x += 100;
	}

	if (dynamic_cast<TutorialMap*>(map) != nullptr) {
		bubbleVisitor = BubbleVisitor{ ren };
		
		for (auto& player : players)
		{
			tutorialController = TutorialController(&bubbleVisitor, &spawnController, player);
		}
		
	}

	//Load && play sound
	map->PlaySounds();
	currentState = GameState::RUNNING;
}

GameScreen::~GameScreen()
{
	delete tree;
	delete gameObjectContainer;
}

void GameScreen::ReceiveFocus()
{
	currentState = GameState::RUNNING;
}

void GameScreen::Update(float dt)
{
	if (currentState == GameState::RUNNING)
	{
		RemoveDeadPlayers();
		SetZombieTargets();
		
		dt *= (float)settings->getGameSpeed() / 10;

		ShakeScreen(dt);
		HandleInput(dt);

		UpdateZombies(dt);
		spawnController.Update(dt);
		actionContainer.Update(dt);
		collideContainer.Collide(dt);
		moveContainer.Move(dt);
		animateContainer.Animate(dt);
		tree->Clear();

		timeLastStateChange -= dt;
	}
}

void GameScreen::ShakeScreen(float dt)
{
	XOffset = 0;
	YOffset = 0;
	if (shake > 0) {
		shake -= dt;
		XOffset = NumberUtility::RandomNumber(-shakeIntensity, shakeIntensity);
		YOffset = NumberUtility::RandomNumber(-shakeIntensity, shakeIntensity);
	}
}

void GameScreen::UpdateZombies(float dt)
{
	for (auto& g : gameObjectContainer->GetGameObjects()) {
		tree->AddObject(g);
		if (Zombie* z = dynamic_cast<Zombie*>(g))
		{
			z->Update(dt);
		}
	}
}

void GameScreen::RemoveDeadPlayers()
{
	vector<int> toRemove;
	for (int i = 0; i < players.size(); i++)
	{
		if (players.at(i)->IsDeath())
		{
			players.at(i)->Remove();
			toRemove.push_back(i);
		}
	}
	for (auto& i : toRemove)
	{
		players.erase(find(players.begin(), players.end(), players.at(i)));
	}

	toRemove.clear();
}

void GameScreen::SetZombieTargets()
{
	for (auto& gameObject: gameObjectContainer->GetGameObjects())
	{
		if (Zombie* z = dynamic_cast<Zombie*>(gameObject))
		{
			Character* closestTarget = nullptr;
			float closest = INT_MAX;
			for (auto& target : players)
			{
				float distance = GameMath::Distance(*z, *target);
				if (distance < closest)
				{
					closest = distance;
					closestTarget = target;
				}
			}
			z->SetTarget(closestTarget);
		}
	}
}

void GameScreen::HandleInput(float dt)
{

	if (InputContainer::GetInstance().GetKeyState(SDLK_ESCAPE))
	{
		if (timeLastStateChange <= 0) {
			if (currentState == GameState::PAUSE)
			{
				currentState = GameState::RUNNING;
			}
			else {
				currentState = GameState::PAUSE;
				ScreenController::GetInstance().ChangeScreen(ScreenFactory::Create(ScreenEnum::PAUSESCREEN));
			}
			timeLastStateChange = stateChangeDelay;
		}
	}
	if (timeCheatActivated <= 0) {
		if (inputContainer->GetKeyState(SDLK_F3))
		{
			cout << "Toggle godmode\n";
			settings->toggleGodMode();
			timeCheatActivated = cheatDelay;
		}
		else if (inputContainer->GetKeyState(SDLK_F4))
		{
			cout << "Toggle infiniteammo\n";
			settings->toggleInfiniteAmmo();
			timeCheatActivated = cheatDelay;
		}
		else if (inputContainer->GetKeyState(SDLK_F5))
		{
			cout << "Gave all weapons\n";
			for (auto& player : players)
			{
				player->AddWeapon(new Pistol);
				player->AddWeapon(new MachineGun);
			}
			timeCheatActivated = cheatDelay;
		}
	}
	timeCheatActivated -= dt;
}

void GameScreen::Shake(float time, int intensity) {
	shake = time;
	shakeIntensity = intensity;
}

void GameScreen::Draw(SDL_Renderer& ren, float dt)
{
	//tree->Display(&ren);
	map->Draw(ren, XOffset, YOffset);
	drawContainer.Draw(dt, ren, XOffset, YOffset);

	map->DrawFrontLayer(ren, XOffset, YOffset);

	hudVisitor.DrawBase(players.size());

	// BUBBLE ZOOI
	if (dynamic_cast<TutorialMap*>(map) != nullptr) {
		tutorialController.DoTask();
		for (auto& player : players)
		{
			player->Accept(&bubbleVisitor);
		}
	}

	// If all waves defeated
	if (spawnController.Completed())
		this->Transition(ren);

	hudVisitor.Visit(spawnController);

	hudVisitor.Visit(players);

	// if story mode || not infinity mode
	if (!isInfinityMode) 
	{
		// if maxwave completed
		if (spawnController.CurrentWave() == 5) 
		{
			currentState = GameState::TRANSITIONING;
			if (this->Transition(ren))
			{
				return;
			}
		}
	}

	// FPS
	if (settings->getShowFps()) {
		std::pair<SDL_Texture*, SDL_Rect> fpsTexture = TextureFactory::GenerateText("FPS: " + to_string(this->fps), 30, 1225, 15, FontEnum::ROBOTO);
		SDL_RenderCopy(&ren, fpsTexture.first, NULL, &fpsTexture.second);
		SDL_DestroyTexture(fpsTexture.first);
	}

	//DEBUG: draw waypoints
	SDL_SetRenderDrawColor(&ren, 0, 0, 0, 255);
	for (Node* node : map->GetGraph()->GetNodes())
	{
		SDL_Rect& wp1 = node->getDestRect();
		for (Node* wp2 : node->Adjacent())
		{
			SDL_RenderDrawLine(&ren, wp1.x, wp1.y, wp2->getDestRect().x, wp2->getDestRect().y);
		}
	}

	//DEBUG: draw collision
	/*
	vector<SDL_Rect*> collision = map->GetObjectLayer("Collision")->GetRects();
	SDL_SetRenderDrawColor(&ren, 255, 255, 255, 255);
	for (auto& rect : collision)
	{
		SDL_RenderDrawRect(&ren, rect);
	}

	//DEBUG: draw zombie path
	for (Zombie* z: spawnController.zombiesVector)
	{
		deque<Node*> path = z->GetPathCopy();
		while (!path.empty())
		{
			SDL_RenderDrawRect(&ren, &path.front()->getDestRect());
			path.pop_front();
		}
	}
	*/
}

// returns if done transitioning
bool GameScreen::Transition(SDL_Renderer& ren)
{
	for (auto& player : players)
	{
		player->Teleport(&ren);
		// Draw on top off everything
		SDL_RenderCopy(&ren, player->GetTexture(), player->GetSourceRect(), player->GetDestinationRect());

		if (player->getPosY() < -player->GetHeight())
		{
			string texturePath = player->getImgUrl();
			vector<string> tempCharacterImageUrls = characterImageUrls;
			ScreenController::GetInstance().Back();

			// Check if final map
			if (MapFactory::GetInstance()->IsQueueEmpty())
			{
				ScreenController::GetInstance().ChangeScreen(ScreenFactory::Create(ScreenEnum::WINSCREEN));
			}
			else
			{
				// Set next screen
				ScreenController::GetInstance().ChangeScreen(ScreenFactory::CreateGameScreen(tempCharacterImageUrls));
			}
			return true;
		}
		return false;
	}
}

bool GameScreen::IsGameOver()
{
	for (auto& player : players)
	{
		if (!player->IsDeath())
		{
			return false;
		}
	}
	return true;
}
