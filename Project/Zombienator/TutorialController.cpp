#include "TutorialController.h"

/*

- Welkom
- Lopen
-- Richting
--- Collision
- Schieten
- Zombie
-- Drop health kit
-- Drop ammo
- Wapens wisselen
-- Wapens oppakken (niet aanwezig)
- Save & Load (niet aanwezig)

*/

TutorialController::TutorialController() {}

TutorialController::TutorialController(BubbleVisitor* bv)
{
	bubbleVisitor = bv;
	for (int i = 0; i != DONE; i++)
		taskQueue.push(static_cast<TutorialEnum>(i));
}

TutorialController::~TutorialController()
{
	//if (bubbleVisitor) delete bubbleVisitor;
}

void TutorialController::DoTask()
{
	if(taskDone)
	{
		currentTask = taskQueue.front();
		taskQueue.pop();
		taskDone = false;
	}
	else
	{
		switch(currentTask)
		{
			case WELCOME:	Welcome();	break;
			case WALK:		Walk();		break;
			case DONE: break;
			default: break;
		}
	}
}

void TutorialController::Welcome()
{	
	bubbleVisitor->ChangeText("Welcome");
	// LOCK Mike
	if (5 <= GetPassedTime(begin)) taskDone = true;
}

void TutorialController::Walk()
{
	bubbleVisitor->ChangeText("AllahAkbar");
}
