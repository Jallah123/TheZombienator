#pragma once
#include <vector>
#include "Zombie.h"
#include <random>
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
	
	int maxWaves = 3;
	int currentWave = 0;

	int zombies = 0;
	int zombiesWave = 0;
	int amountToSpawn = 3;
	
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

	void Update(float dt);

	void Spawn();

	void NextWave();

	void Countdown();

	void SetRenderer(SDL_Renderer* r) { this->renderer = r; }

	void AddLocation(int x, int y);

	void AddTarget(Character* c) { this->target = c; }

	void Waves(int w) { this->maxWaves = w; }

	int Waves() { return this->maxWaves; }

	int GetAmountToSpawn() { return amountToSpawn; };

	int GetAmountOfZombies() { return zombies; };
	
	int CurrentWave() { return this->currentWave; }

	int GetTimeTillNextWave() { return timeBetweenWaves - elapsedtime; }

	int GetAmountSpawned() { return zombiesWave; }

	bool WaveCompleted() { return this->waveFinished; }

	bool Completed() { return completed; }
};

