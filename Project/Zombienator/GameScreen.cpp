#pragma once
#include "GameScreen.h"
#include <SDL_mixer.h>
#include <iostream>

#include "Map.h"
#include "Mike.h"
#include "Zombie.h"



GameScreen::GameScreen(SDL_Renderer* ren, char* path) : AbstractScreen(ren)
{
	map = new Map(path, *ren);

	goFactory->SetLevel( map );
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
}

void GameScreen::Draw(SDL_Renderer& ren, float dt)
{
	map->Draw(ren);
	spawnController.Update(dt);
	actionContainer.Update(dt);
	collideContainer.Collide(dt);
	moveContainer.Move(dt);
	animateContainer.Animate(dt);
	drawContainer.Draw(dt, ren);
}
