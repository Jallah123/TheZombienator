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
TutorialController::TutorialController(BubbleVisitor* bv, Mike* m) : bubbleVisitor(bv), mike(m) { FillTaskQueue(); ResetPosition(); }
TutorialController::~TutorialController() {	/* if (bubbleVisitor) delete bubbleVisitor; */ }

void TutorialController::FillTaskQueue()
{
	for (int i = 0; i != DONE; i++)
		taskQueue.push(static_cast<TutorialEnum>(i));
}

void TutorialController::DoTask()
{
	if(taskDone)
	{
		if (taskQueue.size() > 0) {
			currentTask = taskQueue.front();
			taskQueue.pop();
		}
		else
			currentTask = DONE;

		ResetClock();
		taskDone = false;
	}
	else
	{
		switch(currentTask)
		{
			case WELCOME:		Welcome();	break;
			case WALK:		Walk();		break;
			case DONE:		Done();		break;
			default: break;
		}
	}
}

void TutorialController::Welcome()
{	
	bubbleVisitor->ChangeText("Welcome");
	CheckClock();
}

void TutorialController::Walk()
{	
	switch (walkDir) {
		case Direction::WEST:
			bubbleVisitor->ChangeText("Walk: Left");
			if ((currentPos.x - walkDist) > mike->getPosX()) {
				ResetPosition();
				walkDir = Direction::NORTH;
			}
			break;
		case Direction::NORTH:
			bubbleVisitor->ChangeText("Walk: Left -> Up");
			if ((currentPos.y - walkDist) > mike->getPosY()) {
				ResetPosition();
				walkDir = Direction::EAST;
			}
			break;
		case Direction::EAST:
			bubbleVisitor->ChangeText("Walk: Left -> Up -> Right");
			if ((currentPos.x + walkDist) < mike->getPosX()) {
				ResetPosition();
				walkDir = Direction::SOUTH;
			}
			break;
		case Direction::SOUTH:
			bubbleVisitor->ChangeText("Walk: Left -> Up -> Right -> Down");
			if ((currentPos.y + walkDist) < mike->getPosY()) {
				ResetPosition();
				walkDir = Direction::NONE;
				ResetClock();
			}
			break;
		case Direction::NONE:
			bubbleVisitor->ChangeText("Walk Challenge Completed!");
			CheckClock();
			break;
	}
}

void TutorialController::Done()
{
	bubbleVisitor->ChangeText("You're finished and will return to the menu in a few seconds");
	if (waitTime <= GetPassedTime(begin)) { // return to menu
		MapFactory::GetInstance()->EmptyQueue();
		ScreenController::GetInstance().EmptyStack();
		ScreenController::GetInstance().ChangeScreen(ScreenFactory::Create(ScreenEnum::WINSCREEN));
	}
}
