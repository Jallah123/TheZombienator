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
		if(taskQueue.size() > 0){
			currentTask = taskQueue.front();
			taskQueue.pop();
		}
		else
			currentTask = DONE;

		begin = clock();
		taskDone = false;
	}
	else
	{
		switch(currentTask)
		{
			case WELCOME:	Welcome();	break;
			case WALK:		Walk();		break;
			default:		Done();		break;
		}
	}
}

void TutorialController::Welcome()
{	
	bubbleVisitor->ChangeText("Welcom");
	if (5 <= GetPassedTime(begin)) taskDone = true;
}

void TutorialController::Walk()
{
	bubbleVisitor->ChangeText("Walk");
	if (5 <= GetPassedTime(begin)) taskDone = true;
}

void TutorialController::Done()
{
	bubbleVisitor->ChangeText("You're finished and will return to the menu in a few seconds");


	if (4 <= GetPassedTime(begin)) {
		// return to menu

		MapFactory::GetInstance()->EmptyQueue();
		ScreenController::GetInstance().EmptyStack();
		ScreenController::GetInstance().ChangeScreen(ScreenFactory::Create(ScreenEnum::HOMESCREEN));
	}
}