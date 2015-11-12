#pragma once
#include "SpawnController.h"
#include "GameObjectFactory.h"

SpawnController::SpawnController()
{
	NextWave();
}


SpawnController::~SpawnController()
{
}

void SpawnController::Update(float dt)
{
	if (completed) return;
	//std::cout << "Current wave: " << currentWave << ", zombies: " << zombies << ", amount to spawn " << amountToSpawn << std::endl;
	//std::cout << "elapsed time " << elapsedtime << std::endl;
	elapsedtime += dt;
	if (waveFinished) {
		NextWave();
		return;
	} else

	Spawn();
}

void SpawnController::Spawn()
{
	if (elapsedtime < spawnTime) return;
	if (zombies == amountToSpawn) {
		waveFinished = true;
		elapsedtime = 0;
		return;
	}
	//No points to spawn on?
	if (locations.size() == 0) return;

	int l = locationDist(dre);
	xy p = locations.at(l);

	Zombie* z = GameObjectFactory::Instance()->CreateZombie();
	z->SetTarget(target);
	z->SetPosition(p.first, p.second);
	zombies++;
	elapsedtime = 0;
}

void SpawnController::NextWave()
{
	if (elapsedtime < timeBetweenWaves) return;
	if (currentWave == maxWaves) {
		completed = true;
		return;
	}
	currentWave++;
	waveFinished = false;
	zombies = 0;
	elapsedtime = 0;
}

void SpawnController::Countdown()
{
	if (elapsedtime >= timeBetweenWaves) {
		NextWave();		
	}
}

void SpawnController::AddLocation(int x, int y)
{
	this->locations.push_back({ x,y });
	locationDist = std::uniform_int_distribution<int>(0, this->locations.size() - 1);
}
