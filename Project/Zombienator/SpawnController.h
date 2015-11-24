#pragma once
#include <vector>
#include "Zombie.h"
#include <random>
using std::vector;
#define xy std::pair<int, int>

class Map;
class StatsController;

class SpawnController
{
private:
	vector<xy> locations;
	
	int maxWaves = 3;
	int currentWave = 0;

	int zombies = 0;
	int zombiesWave = 0;
	int zombiesPlus = 2;
	int amountToSpawn = 1;
	
	float spawnTime = 200;
	float elapsedtime = 0;
	float timeBetweenWaves = 500;//5 seconds
	bool waveFinished = false;

	bool completed = false;
	
	SDL_Renderer* renderer = nullptr;
	
	Character* target = nullptr;

	StatsController* statsController = nullptr;

	bool IsFinished();
	Map* map;
public:
	SpawnController();
	~SpawnController();

	void SetMap(Map* m);
	
	void Update(float dt);

	void Spawn();

	void NextWave();

	void Countdown();

	void SetRenderer(SDL_Renderer* r) { this->renderer = r; }

	void AddLocation(int x, int y);

	void AddTarget(Character* c) { this->target = c; }

	void Waves(int w) { this->maxWaves = w; }

	int Waves() { return this->maxWaves; }
	
	int CurrentWave() { return this->currentWave; }

	bool WaveCompleted() { return this->waveFinished; }

	bool Completed() { return completed; }
};

