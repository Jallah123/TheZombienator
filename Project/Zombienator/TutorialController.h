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

using namespace std;

class TutorialController
{
	private:
		Mike* mike;
		BubbleVisitor* bubbleVisitor;
		queue<TutorialEnum> taskQueue;
		TutorialEnum currentTask;
		Direction walkDir = Direction::WEST;
		SDL_Point currentPos = { 892, 320 };

		int waitTime = 5;
		int walkDist = 200;
		bool taskDone = true;

		clock_t begin = clock();
	public:
		TutorialController();
		TutorialController(BubbleVisitor* bv, Mike* mike);
		~TutorialController();
		void FillTaskQueue();
		void DoTask();

		void Welcome();
		void Walk();
		void Done();

		//void SetPosition() { currentPos = { int(mike->getPosX()), int(mike->getPosY()) }; }
		void ResetPosition() { mike->SetPosition(currentPos.x, currentPos.y); mike->SetLookDir(Direction::SOUTH); mike->SetMoveDir(Direction::SOUTH); }

		void CheckClock() { if (waitTime <= GetPassedTime(begin)) { taskDone = true; ResetPosition(); }	}
		void ResetClock() {	begin = clock(); }
		float GetPassedTime(clock_t t) { return float(clock() - t) / CLOCKS_PER_SEC; }
};