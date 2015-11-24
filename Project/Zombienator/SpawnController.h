#pragma once
#include <vector>
#include "Zombie.h"
#include "StatsController.h"
using std::vector;
#define xy std::pair<int, int>

class GameScreen;
class Map;


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
	float maxElapsedTime = 1000;
	
	bool waveFinished = false;
	bool completed = false;
	
	GameScreen* gameScreen = nullptr;
	Character* target = nullptr;

	StatsController* statsController = StatsController::Instance();

	bool IsFinished();
	Map* map;
public:
	SpawnController();
	SpawnController(GameScreen* gs);
	~SpawnController();

	void SetMap(Map* m);
	
	void Update(float dt);

	void Spawn();

	void NextWave();

	void Countdown();
	
	void AddLocation(int x, int y);

	void AddTarget(Character* c) { this->target = c; }

	void Waves(int w) { this->maxWaves = w; }

	int Waves() { return this->maxWaves; }
	
	int CurrentWave() { return this->currentWave; }

	bool WaveCompleted() { return this->waveFinished; }

	bool Completed() { return completed; }
};

