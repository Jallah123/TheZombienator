#pragma once
#include "SpawnController.h"
#include "GameObjectFactory.h"

SpawnController::SpawnController()
{
}


SpawnController::~SpawnController()
{
}

void SpawnController::Update(float dt)
{
	if (zombies == amountToSpawn) return;
	elapsedtime += dt;
	//if (elapsedtime > spawnTime) Spawn();
}

void SpawnController::Spawn()
{
	if (locations.size() == 0) return;

	int l = locationDist(dre);
	xy p = locations.at(l);

	Zombie* z = GameObjectFactory::Instance()->CreateZombie();
	z->SetTarget(target);
	z->SetPosition(p.first, p.second);
	zombies++;
	elapsedtime = 0;
}

void SpawnController::AddLocation(int x, int y)
{
	this->locations.push_back({ x,y });
	locationDist = std::uniform_int_distribution<int>(0, this->locations.size() - 1);
}
