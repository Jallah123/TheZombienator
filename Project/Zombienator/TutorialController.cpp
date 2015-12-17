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

TutorialController::TutorialController()
{
}

TutorialController::TutorialController(BubbleVisitor* bv, Mike* m) : bubbleVisitor(bv), mike(m)
{
	FillTaskQueue();
	ResetPosition();
}

TutorialController::~TutorialController() 
{
	/* if (bubbleVisitor) delete bubbleVisitor; */
}

void TutorialController::ResetPosition()
{
	mike->SetPosition(currentPos.x, currentPos.y);
	mike->SetLookDir(Direction::SOUTH);
	mike->SetMoveDir(Direction::SOUTH);
}

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
			case WELCOME:	Welcome();	break;
			case WALK:		Walk();		break;
			case DONE:		Done();		break;
			default: break;
		}
	}
}

void TutorialController::Welcome()
{	
	bubbleVisitor->ChangeText("Welcome to The Zombienator!");
	CheckClock();
}

void TutorialController::Walk()
{	
	switch (walkDir) {
		case Direction::NORTH:
			bubbleVisitor->ChangeText("Use your arrow keys to move around. Walk in the north direction.");
			if ((currentPos.y - walkDist) > mike->getPosY()) {
				walkDir = Direction::EAST;
			}
			break;
		case Direction::EAST:
			bubbleVisitor->ChangeText("Use your arrow keys to move around. Walk in the east direction.");
			if ((currentPos.x + walkDist) < mike->getPosX()) {
				walkDir = Direction::SOUTH;
			}
			break;
		case Direction::SOUTH:
			bubbleVisitor->ChangeText("Use your arrow keys to move around. Walk in the south direction.");
			if ((currentPos.y + walkDist) < mike->getPosY()) {
				walkDir = Direction::WEST;
			}
			break;
		case Direction::WEST:
			bubbleVisitor->ChangeText("Use your arrow keys to move around. Walk in the west direction.");
			if ((currentPos.x - walkDist) > mike->getPosX()) {
				walkDir = Direction::NONE;
				ResetClock();
			}
			break;
		case Direction::NONE:
			bubbleVisitor->ChangeText("Walk challenge completed!");
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
