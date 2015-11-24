#pragma once
#include "SpawnController.h"
#include "GameObjectFactory.h"
#include "StatsController.h"
bool SpawnController::IsFinished()
{
	if (!waveFinished && statsController->GetKills() == zombies) {
		waveFinished = true;
		elapsedtime = 0;
	}

	return waveFinished;
}
SpawnController::SpawnController()
{
	statsController = StatsController::Instance();
	NextWave();
}

SpawnController::~SpawnController()
{
}

void SpawnController::Update(float dt)
{
	if (completed) return;

	elapsedtime += dt;
	if (IsFinished()) {
		Countdown();
		return;
	} 
	else Spawn();
}

void SpawnController::Spawn()
{	
	if (zombiesWave == amountToSpawn) return;
	if (elapsedtime < spawnTime) return;
	//No points to spawn on?
	if (locations.size() == 0) return;

	int l = locationDist(dre);
	xy p = locations.at(l);

	Zombie* z = GameObjectFactory::Instance()->CreateZombie();
	z->SetMap(map);
	z->SetTarget(target);
	z->SetPosition(p.first, p.second);
	zombiesWave++;
	elapsedtime = 0;
}

void SpawnController::NextWave()
{
	if (currentWave == maxWaves) {
		completed = true;
		return;
	}
	currentWave++;
	waveFinished = false;
	zombiesWave = 0;//reset wave count
	zombies += amountToSpawn;
	elapsedtime = 0;
}

void SpawnController::Countdown()
{
	if (elapsedtime < timeBetweenWaves) return;

	NextWave();
}

void SpawnController::AddLocation(int x, int y)
{
	this->locations.push_back({ x,y });
	locationDist = std::uniform_int_distribution<int>(0, this->locations.size() - 1);
}
