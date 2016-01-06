#pragma once
#include "SpawnController.h"
#include "GameObjectFactory.h"
#include "GameScreen.h"
#include "Quadtree.h"
#include "NumberUtility.h"
#include "Map.h"
#include "StatsController.h"

bool SpawnController::IsFinished()
{
	int kills = statsController->GetKills();
	if (!waveFinished && kills == zombies) {
		waveFinished = true;
		elapsedtime = 0;
	}
	
	return waveFinished;
}

SpawnController::SpawnController()
{	
	NextWave();
}

SpawnController::SpawnController(GameScreen * gs) : gameScreen(gs)
{	
	statsController->SetKills(0);
	NextWave();
}

SpawnController::~SpawnController()
{
}

void SpawnController::SetMap(Map * m)
{
	map = m;
	ObjectLayer* ol = map->GetObjectLayer("SpawnPoints");
	for (auto& spawnPoint : ol->GetRects())
	{
		AddLocation(spawnPoint->x, spawnPoint->y);
	}
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
	if (amountSpawned == amountToSpawn) return;
	if (elapsedtime < spawnTime) return;
	//No points to spawn on?
	if (locations.size() == 0) return;

	int l = NumberUtility::RandomNumber(0, locations.size() - 1);
	xy p = locations.at(l);

	Zombie* z = GameObjectFactory::Instance()->CreateZombie();
	z->SetTarget(target);
	z->SetPosition(p.first, p.second);
	zombiesVector.push_back(z);
	amountSpawned++;
	elapsedtime = 0;
}

void SpawnController::NextWave()
{
	currentWave++;
	waveFinished = false;
	amountSpawned = 0;//reset wave count
	amountToSpawn = GetAmountToSpawn();
	zombies += amountToSpawn;

	waveFinished = false;
	elapsedtime = 0;
}

void SpawnController::Countdown()
{
	if (elapsedtime < timeBetweenWaves) return;

	NextWave();
	StatsController::GetInstance()->AddWaveDefeated();
}

void SpawnController::AddLocation(int x, int y)
{
	this->locations.push_back({ x,y });
}
