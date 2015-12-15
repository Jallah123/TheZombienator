#pragma once
#include "GameScreen.h"
#include <SDL_mixer.h>
#include <iostream>
#include "Quadtree.h"
#include "NumberUtility.h"
#include "BehaviourFactory.h"
#include "Map.h"
#include "Mike.h"
#include "Zombie.h"
#include "TextureFactory.h"
#include "MapFactory.h"
#include "ScreenFactory.h"
#include "TutorialMap.h"
#include "Pistol.h"
#include "MachineGun.h"

GameScreen::GameScreen(SDL_Renderer* ren, string char_img_url) : AbstractScreen(ren)
{

	// Get map
	map = MapFactory::GetInstance()->NextMap();
	tree = new Quadtree(map->GetBounds());

	gameObjectContainer = new GameObjectContainer{ map, tree };
	spawnController = SpawnController{ this };
	gameObjectContainer->SetMap(map);
	spawnController.SetMap(map);
	BehaviourFactory::Instance()->SetMap(map);

	hudVisitor = HudVisitor{ ren };

	if (dynamic_cast<TutorialMap*>(map) != nullptr) {
		bubbleVisitor = BubbleVisitor{ ren };
	}

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
	
	mike = goFactory->CreateMike(char_img_url);
	mike->SetPosition(800, 300);

	spawnController.AddTarget(mike);

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
	dt *= (float)settings->getGameSpeed() / 10;

	XOffset = 0;
	YOffset = 0;
	if (shake > 0) {
		shake -= dt;
		XOffset = NumberUtility::RandomNumber(-shakeIntensity, shakeIntensity);
		YOffset = NumberUtility::RandomNumber(-shakeIntensity, shakeIntensity);
	}
	HandleInput(dt);

	if (currentState == GameState::RUNNING) {
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
	}

	timeLastStateChange -= dt;
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
			mike->AddWeapon(new Pistol);
			mike->AddWeapon(new MachineGun);
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
	mike->GetWeapon()->Accept(&hudVisitor);

	// BUBBLE ZOOI
	if (dynamic_cast<TutorialMap*>(map) != nullptr) {
			
		mike->Accept(&bubbleVisitor);

	}

	// If all waves defeated
	if (spawnController.Completed())
		this->Transition(ren);

	int zombiesOnScreen = spawnController.GetAmountSpawned();
	int zombiesLeft = spawnController.GetAmountToSpawn() - zombiesOnScreen;
	string s = "Zombies left to spawn : " + std::to_string(zombiesLeft);
	if (zombiesLeft == 0) {
		s = "Kill all zombies";
		if (spawnController.AllWavesCompleted()) {
			s = "Next map in: " + std::to_string(spawnController.GetTimeTillNextWave() / 100);
		}
		else if (spawnController.WaveCompleted()) {
			s = "Next wave in: " + std::to_string(spawnController.GetTimeTillNextWave() / 100);
		}
		
	}
	auto* text = TextureFactory::GenerateTextureFromTextHud(s);
	SDL_Rect r{ 0,0,200,40 };
	SDL_RenderCopy(&ren, text, 0, &r);
	SDL_DestroyTexture(text);

	// FPS
	if (settings->getShowFps()) {
		std::pair<SDL_Texture*, SDL_Rect> fpsTexture = TextureFactory::GenerateText("FPS: " + to_string(this->fps), 30, 1225, 15, FontEnum::ROBOTO);
		SDL_RenderCopy(&ren, fpsTexture.first, NULL, &fpsTexture.second);
		SDL_DestroyTexture(fpsTexture.first);
	}

}

void GameScreen::Transition(SDL_Renderer& ren) {

	mike->Teleport(&ren);

	// Draw on top off everything
	SDL_RenderCopy(&ren, mike->GetTexture(), &mike->GetSourceRect(), mike->GetDestinationRect());

	if (mike->getPosY() < -mike->GetHeight()) {

		ScreenController::GetInstance().PopLatestScreen();

		// Check if final map
		if (MapFactory::GetInstance()->IsQueueEmpty()) {
			ScreenController::GetInstance().ChangeScreen(ScreenFactory::Create(ScreenEnum::WINSCREEN));
		}
		else {
			// Set next screen
			ScreenController::GetInstance().ChangeScreen(ScreenFactory::Create(ScreenEnum::GAMESCREEN));
		}

	}

}
