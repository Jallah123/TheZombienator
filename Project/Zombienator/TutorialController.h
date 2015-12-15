#pragma once
#include <ctime>
#include <queue>
#include "BubbleVisitor.h"
#include "TutorialEnum.cpp"


using namespace std;

class TutorialController
{
	private:
		BubbleVisitor* bubbleVisitor;
		queue<TutorialEnum> taskQueue;
		TutorialEnum currentTask;
		bool taskDone = true;

		clock_t begin = clock();
	public:
		TutorialController();
		TutorialController(BubbleVisitor* bv);
		~TutorialController();
		void DoTask();

		void Welcome();
		void Walk();

		float GetPassedTime(clock_t t) { return float(clock() - t) / CLOCKS_PER_SEC; }
};