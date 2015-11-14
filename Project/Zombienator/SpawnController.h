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


class SpawnController
{
private:
	vector<xy> locations;
	int zombies = 50;
	int amountToSpawn = 10;
	float spawnTime = 100;
	float elapsedtime = 0;
	random_device dev;
	default_random_engine dre{ dev() };
	uniform_int_distribution<int> locationDist;

	SDL_Renderer* renderer = nullptr;
	
	Character* target = nullptr;

public:
	SpawnController();
	~SpawnController();

	void Update(float dt);
	void Spawn();

	void SetRenderer(SDL_Renderer* r) { this->renderer = r; }
	void AddLocation(int x, int y);
	void AddTarget(Character* c) { this->target = c; }
};

