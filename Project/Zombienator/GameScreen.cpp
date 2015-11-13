#pragma once
#include "GameScreen.h"
#include <SDL_mixer.h>
#include <iostream>

#include "Quadtree.h"
#include "BehaviourFactory.h"
#include "Map.h"
#include "Mike.h"
#include "Zombie.h"

GameScreen::GameScreen(SDL_Renderer* ren, char* path) : AbstractScreen(ren)
{
	map = new Map(path, *ren);
	tree = new Quadtree(SDL_Rect{ 0,0,1280,640 });
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

	spawnController = new SpawnController(ren, this);
	spawnController->AddLocation(500, 200);
	spawnController->AddLocation(900, 600);
	/*spawnController->AddLocation(640, 100);
	spawnController->AddLocation(1280, 340);
	spawnController->AddLocation(640, 680);
	spawnController->AddLocation(0, 340);*/

	mike = goFactory->CreateMike();
	mike->SetPosition(800, 150);
	
	spawnController->AddTarget(mike);

	//Load && play sound
	musicController->Load("assets/sounds/bgSound1.wav");
	musicController->Play(1, -1);
	musicController->SetVolume(25, 1);

}


GameScreen::~GameScreen()
{
	delete mike;
	delete spawnController;
	delete mike;
	delete tree;
}

void GameScreen::Update(float dt)
{
	tree->Clear();
	for (auto& c : characterContainer.GetCharacters()) {
		tree->AddObject(c);
	}
	
	spawnController->Update(dt);
	actionContainer.Update(dt);
	moveContainer.Move(dt);
}

void GameScreen::Draw(SDL_Renderer& ren, float dt)
{
	tree->Display(&ren);
	
	map->Draw(ren);
	collideContainer.Collide(dt);
	
	animateContainer.Animate(dt);
	drawContainer.Draw(dt, ren);
}
