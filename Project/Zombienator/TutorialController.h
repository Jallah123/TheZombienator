#pragma once
#include <ctime>
#include <queue>
#include "Direction.cpp"
#include "SDL_rect.h"
#include "TutorialEnum.cpp"
#include "PlayableCharacter.h"

class PlayableCharacter;
class BubbleVisitor;
class SpawnController;

class TutorialController
{
	private:
		PlayableCharacter* player = nullptr;
		BubbleVisitor* bubbleVisitor = nullptr;
		SpawnController* spawnController = nullptr;
		int amountOfZombies;

		std::queue<TutorialEnum> taskQueue;
		TutorialEnum currentTask;
		Direction walkDir = Direction::NORTH;
		SDL_Point currentPos = { 892, 320 };

		int waitTime = 5;
		int walkDist = 150;
		
		bool taskDone = true;
		bool collisionDone = false;
		bool swapDone = false;
		
		bool weaponAdded = false;
		bool waveStarted = false;
		int shotsAmount = 5;

		clock_t begin = clock();
	public:
		TutorialController();
		TutorialController(BubbleVisitor* bv, SpawnController* s, PlayableCharacter* m);
		~TutorialController();
		void Init();
		void FillTaskQueue();
		void DoTask();

		void Welcome();
		void Walk();
		void Collision();
		void Shoot();
		void Swap();
		void Kill();
		void Done();

		void SetPosition();
		void ResetPosition();

		void CheckClock() { if (waitTime <= GetPassedTime(begin)) { taskDone = true; }	}
		void ResetClock() {	begin = clock(); }
		float GetPassedTime(clock_t t) { return float(clock() - t) / CLOCKS_PER_SEC; }
};