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

GameScreen::GameScreen(SDL_Renderer* ren) : AbstractScreen(ren)
{

	// Get map
	map = MapFactory::Instance()->NextMap();

	tree = new Quadtree(map->GetBounds());

	gameObjectContainer = GameObjectContainer{ map, tree };
	spawnController = SpawnController{ this };
	gameObjectContainer.SetMap(map);
	spawnController.SetMap(map);
	BehaviourFactory::Instance()->SetMap(map);

	hudVisitor = HudVisitor{ ren };

	goFactory->SetContainers(
		&drawContainer,
		&animateContainer,
		&moveContainer,
		&actionContainer,
		&collideContainer,
		&gameObjectContainer,
		ren
	);

	BehaviourFactory::Instance()->SetContainers(
		&drawContainer,
		&animateContainer,
		&moveContainer,
		&actionContainer,
		&collideContainer,
		&gameObjectContainer,
		ren
	);
	
	// Create character(s)
	mike = goFactory->CreateMike();
	mike->SetPosition(600, 250);

	spawnController.AddTarget(mike);

	//Load && play sound
	SoundController->ChangeMusic("assets/sounds/bgSound1.wav");
	
}

GameScreen::~GameScreen()
{
	delete mike;
	delete tree;
}

void GameScreen::Update(float dt)
{
	tree->Clear();

	XOffset = 0;
	YOffset = 0;
	/*if (shake > 0) {
		shake -= dt;
		XOffset = NumberUtility::RandomNumber(-shakeIntensity, shakeIntensity);
		YOffset = NumberUtility::RandomNumber(-shakeIntensity, shakeIntensity);
	}*/
	if (InputContainer::GetInstance().GetKeyState('['))
	{
		speed += 0.1;
	}
	else if (InputContainer::GetInstance().GetKeyState(']'))
	{
		speed -= 0.1;
		if (speed < 0)
			speed = 0;
	}
	else if (InputContainer::GetInstance().GetKeyState('\\'))
	{
		speed = 1.0;
	}
	dt *= speed;

	for (auto& g : gameObjectContainer.GetGameObjects()) {
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
		std::pair<SDL_Texture*, SDL_Rect> fpsTexture = TextureFactory::GenerateText("FPS: " + to_string(this->fps), 30, 1225, 15, false);
		SDL_RenderCopy(&ren, fpsTexture.first, NULL, &fpsTexture.second);
		SDL_DestroyTexture(fpsTexture.first);
	}

}

void GameScreen::Transition(SDL_Renderer& ren) {

	mike->Teleport(&ren);

	// Draw on top off everything
	SDL_RenderCopy(&ren, mike->GetTexture(), &mike->GetSourceRect(), mike->GetDestinationRect());

	if (mike->getPosY() < -mike->GetHeight()) {

		/*// Check if final map
		if (MapFactory::Instance()->IsQueueEmpty()) {
			// Return to menu
			ScreenController::GetInstance().Back();
		}*/

		// Remove this screen
		//ScreenController::GetInstance().Back();

		// Set next screen
		ScreenController::GetInstance().ChangeScreen(ScreenFactory::Create(ScreenEnum::GAMESCREEN));

	}

}
