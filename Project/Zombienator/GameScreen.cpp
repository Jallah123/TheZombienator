#pragma once
#include "GameScreen.h"
#include <SDL_mixer.h>
#include <iostream>

#include "Map.h"
#include "Mike.h"
#include "Zombie.h"
#include "GameObjectFactory.h"
#include "BehaviourFactory.h"
#include "AnimateContainer.h"
#include "DrawContainer.h"
#include "MoveContainer.h"
#include "ActionContainer.h"
#include "CharacterContainer.h"
#include "CollideContainer.h"
#include "SpawnController.h"

#define DEBUG false

GameObjectFactory* goFactory = GameObjectFactory::Instance();
Mike* mike = nullptr;
DrawContainer drawContainer;
AnimateContainer animateContainer;
ActionContainer actionContainer;
MoveContainer moveContainer;
CollideContainer collideContainer;
CharacterContainer characterContainer;
SpawnController* spawnController;
Map* map;
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
	characterContainer.Init();
	
	spawnController = new SpawnController(&drawContainer, &animateContainer, &moveContainer, &actionContainer, &collideContainer, &characterContainer);
	spawnController->AddLocation(640, 100);
	spawnController->AddLocation(1280, 340);
	spawnController->AddLocation(640, 680);
	spawnController->AddLocation(0, 340);
	spawnController->SetRenderer(ren);

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
	delete spawnController;
	delete mike;
}

void GameScreen::Update(float dt)
{
}

void GameScreen::Draw(SDL_Renderer& ren, float dt)
{
	map->Draw(ren);
	spawnController->Update(dt);
	actionContainer.Update(dt);
	moveContainer.Move(dt);
	collideContainer.Collide(dt);
	animateContainer.Animate(dt);
	drawContainer.Draw(dt, ren);
}
/*
void GameScreen::DrawMap(SDL_Renderer & ren)
{
	vector<SDL_Rect*> sprites = map.get()->getSprites();
	vector<MapLayer> layers = map.get()->getLayers();
	vector<CollisionLayer> collisionLayers = map.get()->getCollisionLayers();

	size_t i, x, y;
	for (i = layers.size() - 1; i >= 0; i--) {
		vector<vector<int>> ids = layers.at(i).getGIDs();
		std::cout << "layers->i.size="<< layers.at(i).getGIDs().size() << std::endl;
		for (x = 0; x < ids.size(); x++)
			for (y = 0; y < ids.at(x).size(); y++)
				DrawRect(x, y, sprites.at(y*ids.size() + x), &ren);
	}


	if (DEBUG) {
		for (int j = collisionLayers.size() - 1; j >= 0; j--)
		{
			vector<CollisionObject> collisionObjects = collisionLayers[j].getCollisionObjects();

			for (int k = collisionObjects.size() - 1; k >= 0; k--)
				DrawCollisionObject(collisionObjects[k].getY(), collisionObjects[k].getX(), collisionObjects[k].getWidth(), collisionObjects[k].getHeight(), &ren);
			
		}
	}		
}

*/