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

GameScreen::GameScreen(SDL_Renderer* ren, string char_img_url, string mapUrl) : AbstractScreen(ren)
{

	// Get map
	if (mapUrl == "") {
		map = MapFactory::GetInstance()->NextMap();
	}
	else {
		isInfinityMode = true;
		map = new Map{ mapUrl };
	}

	tree = new Quadtree(map->GetBounds());

	gameObjectContainer = new GameObjectContainer{ map, tree };
	spawnController = SpawnController{ this };
	gameObjectContainer->SetMap(map);
	spawnController.SetMap(map);
	BehaviourFactory::Instance()->SetMap(map);

	hudVisitor = HudVisitor{ ren };

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
	SoundController->ChangeMusic("assets/sounds/bgSound1.wav");
	currentState = GameState::RUNNING;
}

GameScreen::~GameScreen()
{
	StatsController::Reset();
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
		if (!inTransistion) {
			spawnController.Update(dt);
		}
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

	// if story mode || not infinity mode
	if (!isInfinityMode) {
		// if maxwave completed
		if (spawnController.CurrentWave() == 5) {
			inTransistion = true;
			if (this->Transition(ren))
			{
				return;
			}
			
		}
	}

	int zombiesOnScreen = spawnController.GetAmountSpawned();
	int zombiesLeft = spawnController.GetAmountToSpawn() - zombiesOnScreen;
	string s = "Zombies left to spawn : " + std::to_string(zombiesLeft);
	if (zombiesLeft == 0) {
		s = "Kill all zombies";
		if (spawnController.CurrentWave() == 4 && spawnController.WaveCompleted()) {
			s = "Next map in: " + std::to_string(spawnController.GetTimeTillNextWave() / 100);
		}
		else if(spawnController.WaveCompleted()) {
			s = "Next wave in: " + std::to_string(spawnController.GetTimeTillNextWave() / 100);
		}
		if (inTransistion) {
			s = "Transitioning to next level";
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

// returns if done transitioning
bool GameScreen::Transition(SDL_Renderer& ren) {

	mike->Teleport(&ren);

	// Draw on top off everything
	SDL_RenderCopy(&ren, mike->GetTexture(), &mike->GetSourceRect(), mike->GetDestinationRect());

	if (mike->getPosY() < -mike->GetHeight()) {

		string imgUrl = mike->getImgUrl();
		inTransistion = false;
		ScreenController::GetInstance().Back();

		// Check if final map
		if (MapFactory::GetInstance()->IsQueueEmpty()) {
			ScreenController::GetInstance().ChangeScreen(ScreenFactory::Create(ScreenEnum::WINSCREEN));
		}
		else {
			// Set next screen
			ScreenController::GetInstance().ChangeScreen(ScreenFactory::CreateGameScreen(imgUrl));
		}
		return true;
	}
	return false;
}
