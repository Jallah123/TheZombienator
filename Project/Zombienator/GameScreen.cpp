#pragma once
#include "GameScreen.h"
#include <SDL_mixer.h>
#include <iostream>
#include "NumberUtility.h"
#include "Map.h"
#include "Mike.h"
#include "Zombie.h"



GameScreen::GameScreen(SDL_Renderer* ren, char* path) : AbstractScreen(ren)
{
	map = new Map(path, *ren);

	goFactory->SetLevel(map);
	goFactory->SetContainers(
		&drawContainer,
		&animateContainer,
		&moveContainer,
		&actionContainer,
		&collideContainer,
		&characterContainer,
		ren
		);
	BehaviourFactory::Instance()->SetContainers(
		&drawContainer,
		&animateContainer,
		&moveContainer,
		&actionContainer,
		&collideContainer,
		&characterContainer,
		ren
		);
	BehaviourFactory::Instance()->SetMap(map);
	characterContainer.Init();

	ObjectLayer* ol = map->GetObjectLayer("SpawnPoints");

	for each (auto spawnPoint in ol->GetRects())
	{
		spawnController.AddLocation(spawnPoint->x, spawnPoint->y);
	}

	spawnController.SetRenderer(ren);

	mike = goFactory->CreateMike();
	mike->SetPosition(800, 150);

	spawnController.AddTarget(mike);

	//Load && play sound
	musicController->Load("assets/sounds/bgSound1.wav");
	musicController->Play(1, -1);
	musicController->SetVolume(25, 1);
}

GameScreen::~GameScreen()
{
	delete mike;
}

void GameScreen::Update(float dt)
{
	if (shake > 0) {
		shake -= dt;
		XOffset = NumberUtility::RandomNumber(-shakeIntensity, shakeIntensity);
		YOffset = NumberUtility::RandomNumber(-shakeIntensity, shakeIntensity);
	}
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
	map->Draw(ren, XOffset, YOffset);
	drawContainer.Draw(dt, ren, XOffset, YOffset);
}
