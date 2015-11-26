#pragma once
#include <vector>
#include "Zombie.h"
#include <random>
#include <math.h>

using std::vector;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
#define xy std::pair<int, int>

class DrawContainer;
class AnimateContainer;
class ActionContainer;
class MoveContainer;
class CollideContainer;
class CharacterContainer;

class StatsController;

class SpawnController
{
private:
	vector<xy> locations;
	
	Map* map = nullptr;

	int maxWaves = 5;
	int currentWave = 0;

	int zombies = 0;
	int amountSpawned = 0;
	int amountToSpawn = 0;
	
	float spawnTime = 100;
	float elapsedtime = 0;
	float timeBetweenWaves = 500;//5 seconds
	bool waveFinished = false;

	bool completed = false;

	random_device dev;
	default_random_engine dre{ dev() };
	uniform_int_distribution<int> locationDist;

	SDL_Renderer* renderer = nullptr;
	
	Character* target = nullptr;

	StatsController* statsController = nullptr;

	bool IsFinished();
public:
	SpawnController();
	~SpawnController();

	void SetMap(Map* _map) { map = _map; };

	void Update(float dt);

	void Spawn();

	void NextWave();

	void Countdown();

	void SetRenderer(SDL_Renderer* r) { this->renderer = r; }

	void AddLocation(int x, int y);

	void AddTarget(Character* c) { this->target = c; }

	void Waves(int w) { this->maxWaves = w; }

	int Waves() { return this->maxWaves; }

	int GetAmountOfZombies() { return zombies; };
	
	int CurrentWave() { return this->currentWave; }

	int GetAmountToSpawn() { return round(pow((currentWave + 1), (3.0 / 2.0)));	};

	int GetTimeTillNextWave() { return timeBetweenWaves - elapsedtime; }

	int GetAmountSpawned() { return amountSpawned; }

	bool WaveCompleted() { return this->waveFinished; }

	bool Completed() { return completed; }
};

