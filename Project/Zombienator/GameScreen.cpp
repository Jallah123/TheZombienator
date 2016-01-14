#pragma once
#include "SDL.h"
#include <SDL_mixer.h>
#include <iostream>
#include "GameScreen.h"
#include "Quadtree.h"
#include "NumberUtility.h"
#include "BehaviourFactory.h"
#include "Map.h"
#include "KeyBinding.h"
#include "Zombie.h"
#include "TextureFactory.h"
#include "MapFactory.h"
#include "ScreenFactory.h"
#include "TutorialMap.h"
#include "Pistol.h"
#include "MachineGun.h"
#include "PlayableCharacter.h"
#include "GameMath.h"
#include "StringUtils.h"

GameScreen::GameScreen(SDL_Renderer* ren, vector<string> characterUrls, string mapUrl) : AbstractScreen(ren)
{
	defaultKeybindings.push_back(new KeyBinding{ SDLK_w, SDLK_a, SDLK_s, SDLK_d, SDLK_SPACE, SDLK_e, SDLK_q });
	defaultKeybindings.push_back(new KeyBinding{ SDLK_UP, SDLK_LEFT, SDLK_DOWN, SDLK_RIGHT, SDLK_RCTRL, SDLK_LEFTBRACKET, SDLK_RIGHTBRACKET });
	characterImageUrls = characterUrls;

	// Get map
	if (mapUrl == "")
	{
		map = MapFactory::GetInstance()->NextMap();
	}
	else
	{
		gameType = GameType::INFINITY_MODE;
		map = new Map{ mapUrl };
	}

	tree = new Quadtree(map->GetBounds());

	gameObjectContainer = new GameObjectContainer{ map, tree };
	spawnController = SpawnController{ this };
	gameObjectContainer->SetMap(map);
	spawnController.SetMap(map);
	BehaviourFactory::Instance()->SetMap(map);

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

	for (int i = 0; i < characterImageUrls.size(); i++)
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
	hudVisitor = HudVisitor{ ren, map->GetBounds(), players.size() };

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
	vector<PlayableCharacter*> toRemove;
	for (auto& player: players)
	{
		if (player->IsDeath())
		{
			player->Remove();
			toRemove.push_back(player);
		}
	}
	for (auto& player : toRemove)
	{
		players.erase(find(players.begin(), players.end(), player));
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

	if (InputContainer::GetInstance().GetKeyState(SDLK_DELETE))
	{
		auto queue = MapFactory::GetInstance()->GetQueue();
		vector<string> mapsUrls;
		ofstream maps("assets/saves/story.save");
		// Save current map
		maps << map->GetMapPath() << ',';
		// Save all maps in the queue.
		if (queue.empty())
		{
			cout << "Queue empty, nothing to save";
		}
		else {
			for (int i = 0; i <= queue.size(); i++)
			{
				maps << queue.front()->GetMapPath() << ',';
				queue.pop();
			}
		}
		// close file
		maps.close();
	}
	else if (InputContainer::GetInstance().GetKeyState(SDLK_INSERT))
	{
		// Open save file
		ifstream save("assets/saves/story.save");
		// If opening succeeded
		if (save)
		{
			// Load all maps in this vector
			vector<string> maps;
			char urls[512];
			save.getline(urls, 512);
			string s = urls;
			StringUtils::Split(s, ',', maps);
			// Add maps to mapqueue and change to that queue
			MapFactory::GetInstance()->SetCustomQueue(maps);
			currentState = GameState::TRANSITIONING;
			save.close();
		}
		else {
			cout << "No save";
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

	hudVisitor.DrawBase();
	hudVisitor.Visit(spawnController, GetGameType());
	hudVisitor.Visit(players);

	// BUBBLE ZOOI
	if (dynamic_cast<TutorialMap*>(map) != nullptr) {
		tutorialController.DoTask();
		for (auto& player : players)
		{
			player->Accept(&bubbleVisitor);
		}
	}


	// if story mode || not infinity mode
	if (gameType == GameType::STORY_MODE)
	{
		// if maxwave completed
		if (spawnController.Completed())
		{
			currentState = GameState::TRANSITIONING;

		}
	}

	if (currentState == GameState::TRANSITIONING)
	{
		if (this->Transition(ren))
		{
			return;
		}
	}

	// FPS
	if (settings->getShowFps()) {
		std::pair<SDL_Texture*, SDL_Rect> fpsTexture = TextureFactory::GenerateText("FPS: " + to_string(this->fps), 30, 1225, 15, FontEnum::ROBOTO);
		SDL_RenderCopy(&ren, fpsTexture.first, NULL, &fpsTexture.second);
		SDL_DestroyTexture(fpsTexture.first);
	}
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
	if (players.size() == 0) return false;
	for (auto& player : players)
	{
		if (!player->IsDeath())
		{
			return false;
		}
	}
	return true;
}

bool GameScreen::Loading() 
{
	bool b = isLoading;
	isLoading = true;
	return b;
}