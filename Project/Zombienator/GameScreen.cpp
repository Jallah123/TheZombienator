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
#include "Pistol.h"
#include "MachineGun.h"
#include "PlayableCharacter.h"

GameScreen::GameScreen(SDL_Renderer* ren, vector<string> characterUrls, string mapUrl) : AbstractScreen(ren)
{
	defaultKeybindings.push_back(new KeyBinding{ SDLK_w, SDLK_a, SDLK_s, SDLK_d, SDLK_SPACE, SDLK_q ,SDLK_e });
	defaultKeybindings.push_back(new KeyBinding{ SDLK_UP, SDLK_LEFT, SDLK_DOWN, SDLK_RIGHT, SDLK_RCTRL, SDLK_DELETE ,SDLK_PAGEDOWN });
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
		player->SetPosition(x, y);
		spawnController.AddTarget(player);
		x += 100;
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
		dt *= (float)settings->getGameSpeed() / 10;

		XOffset = 0;
		YOffset = 0;
		if (shake > 0) {
			shake -= dt;
			XOffset = NumberUtility::RandomNumber(-shakeIntensity, shakeIntensity);
			YOffset = NumberUtility::RandomNumber(-shakeIntensity, shakeIntensity);
		}
		HandleInput(dt);

		for (auto& g : gameObjectContainer->GetGameObjects()) {
			tree->AddObject(g);
			if (Zombie* z = dynamic_cast<Zombie*>(g))
			{
				z->Update(dt);
			}
		}
		spawnController.Update(dt);
		actionContainer.Update(dt);
		collideContainer.Collide(dt);
		moveContainer.Move(dt);
		animateContainer.Animate(dt);
		tree->Clear();

		timeLastStateChange -= dt;
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

	hudVisitor.DrawBase();

	// if story mode || not infinity mode
	if (!isInfinityMode) {
		// if maxwave completed
		if (spawnController.CurrentWave() == 5) {
			currentState = GameState::TRANSITIONING;
			if (this->Transition(ren))
			{
				return;
			}
			for (auto& player: players)
			{
				hudVisitor.Visit(*player);
			}

			hudVisitor.Visit(spawnController);
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
			ScreenController::GetInstance().Back();

			// Check if final map
			if (MapFactory::GetInstance()->IsQueueEmpty())
			{
				ScreenController::GetInstance().ChangeScreen(ScreenFactory::Create(ScreenEnum::WINSCREEN));
			}
			else
			{
				// Set next screen
				ScreenController::GetInstance().ChangeScreen(ScreenFactory::CreateGameScreen(characterImageUrls));
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
