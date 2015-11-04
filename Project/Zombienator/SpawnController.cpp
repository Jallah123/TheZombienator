#pragma once
#include "SpawnController.h"
#include "GameObjectFactory.h"
#include "ContainerContainer.h"
#include "AnimateContainer.h"
#include "DrawContainer.h"
#include "MoveContainer.h"
#include "ActionContainer.h"
#include "CharacterContainer.h"
#include "CollideContainer.h"
#include "ContainerContainer.h"
#include <iostream>
SpawnController::SpawnController()
{
	drawContainer = ContainerContainer::GetInstance().GetDrawContainer();
	animateContainer = ContainerContainer::GetInstance().GetAnimateContainer();
	actionContainer = ContainerContainer::GetInstance().GetActionContainer();
	moveContainer = ContainerContainer::GetInstance().GetMoveContainer();
	collideContainer = ContainerContainer::GetInstance().GetCollideContainer();
	characterContainer = ContainerContainer::GetInstance().GetCharacterContainer();
}


SpawnController::~SpawnController()
{
}

void SpawnController::Update(float dt)
{
	if (zombies == amountToSpawn) return;
	elapsedtime += dt;
	if (elapsedtime > spawnTime) Spawn();
}

void SpawnController::Spawn()
{
	if (locations.size() == 0) return;

	int l = locationDist(dre);
	xy p = locations.at(l);

	Zombie* z = GameObjectFactory::Instance()->CreateZombie();
	z->SetTarget(target);
	z->SetPosition(p.first, p.second);
	std::cout << p.first << "  ; " << p.second << std::endl;
	z->Init(drawContainer, animateContainer, moveContainer, actionContainer, collideContainer, characterContainer, renderer);
	zombies++;
	elapsedtime = 0;
}

void SpawnController::AddLocation(int x, int y)
{
	this->locations.push_back({ x,y });
	locationDist = std::uniform_int_distribution<int>(0, this->locations.size() - 1);
}
