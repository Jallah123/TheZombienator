#pragma once
#include <vector>
#include <math.h>
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
	
	Map* map = nullptr;

	int maxWaves = 5;
	int currentWave = 0;

	int zombies = 0;
	int amountSpawned = 0;
	int amountToSpawn = 0;

	float spawnTime = 200;
	float elapsedtime = 0;
	float timeBetweenWaves = 500;//5 seconds
	float maxElapsedTime = 1000;

	bool waveFinished = false;
	bool completed = false;
	bool allWavesCompleted = false;
	
	GameScreen* gameScreen = nullptr;
	Character* target = nullptr;

	StatsController* statsController = StatsController::GetInstance();

	bool IsFinished();
public:
	SpawnController();
	SpawnController(GameScreen* gs);
	~SpawnController();

	vector<Zombie*> zombiesVector;

	void SetMap(Map* m);
	
	void Update(float dt);

	void Spawn();

	void NextWave();

	void Countdown();
	
	void AddLocation(int x, int y);

	void AddTarget(Character* c) { this->target = c; }

	void Waves(int w) { this->maxWaves = w; }

	int Waves() { return this->maxWaves; }

	int GetAmountOfZombies() { return zombies; };
	
	int CurrentWave() { return this->currentWave; }

	int GetAmountToSpawn() { return round(pow((currentWave + 1), (3.0 / 2.0))); };

	int GetTimeTillNextWave() { return timeBetweenWaves - elapsedtime; }

	int GetAmountSpawned() { return amountSpawned; }

	bool WaveCompleted() { return this->waveFinished; }

	bool AllWavesCompleted() { return this->allWavesCompleted; }

	bool Completed() { return completed; }

	int TutorialReset() { int temp = amountToSpawn; amountToSpawn = 0; return temp; }
	void TutorialRevertReset(int i) { amountToSpawn = i; }
};

