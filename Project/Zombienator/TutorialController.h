#pragma once
#include <ctime>
#include <queue>
#include "BubbleVisitor.h"
#include "Mike.h"
#include "MapFactory.h"
#include "ScreenFactory.h"
#include "TutorialEnum.cpp"
#include "MapFactory.h"
#include "ScreenFactory.h"
#include "SpawnController.h"
#include "GameObject.h"
#include "GameObjectContainer.h"
#include "MachineGun.h"

using namespace std;

class TutorialController
{
	private:
		Mike* mike;
		BubbleVisitor* bubbleVisitor;
		SpawnController* spawnController;
		int amountOfZombies;

		queue<TutorialEnum> taskQueue;
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
		TutorialController(BubbleVisitor* bv, SpawnController* s, Mike* m);
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

		void SetPosition() { currentPos = { int(mike->getPosX()), int(mike->getPosY()) }; }
		void ResetPosition() { mike->SetPosition(currentPos.x, currentPos.y); }

		void CheckClock() { if (waitTime <= GetPassedTime(begin)) { taskDone = true; }	}
		void ResetClock() {	begin = clock(); }
		float GetPassedTime(clock_t t) { return float(clock() - t) / CLOCKS_PER_SEC; }
};