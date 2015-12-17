#include "TutorialController.h"

TutorialController::TutorialController() 
{
}

TutorialController::TutorialController(BubbleVisitor* bv, SpawnController* s, Mike* m) : bubbleVisitor(bv), spawnController(s), mike(m) 
{ 
	Init(); 
}

TutorialController::~TutorialController() 
{
}

void TutorialController::Init()
{
	FillTaskQueue(); 
	ResetPosition();
	amountOfZombies = spawnController->TutorialReset();
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
			case WELCOME:		Welcome();		break;
			case WALK:			Walk();			break;
			case COLLISION:		Collision();	break;
			case SHOOT:			Shoot();		break;
			case SWAP:			Swap();		break;
			case KILL:			Kill();			break;
			case DONE:			Done();			break;
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
				SetPosition();
				walkDir = Direction::EAST;
			}
			break;
		case Direction::EAST:
			bubbleVisitor->ChangeText("Use your arrow keys to move around. Walk in the east direction.");
			if ((currentPos.x + walkDist) < mike->getPosX()) {
				SetPosition();
				walkDir = Direction::SOUTH;
			}
			break;
		case Direction::SOUTH:
			bubbleVisitor->ChangeText("Use your arrow keys to move around. Walk in the south direction.");
			if ((currentPos.y + walkDist) < mike->getPosY()) {
				SetPosition();
				walkDir = Direction::WEST;
			}
			break;
		case Direction::WEST:
			bubbleVisitor->ChangeText("Use your arrow keys to move around. Walk in the west direction.");
			if ((currentPos.x - walkDist) > mike->getPosX()) {
				SetPosition();
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

void TutorialController::Collision()
{
	if(!collisionDone){
		bubbleVisitor->ChangeText("Walk now against the tree");
		SDL_Rect mikeCollision = SDL_Rect{ mike->GetCollideRect()->x - 2, mike->GetCollideRect()->y - 2, mike->GetCollideRect()->w + 4, mike->GetCollideRect()->h + 4 };
		for (auto &go : mike->GetGameObjectContainer()->GetGameObjects()) {
			if (dynamic_cast<Mike*>(go)) continue;
			if (SDL_HasIntersection(&mikeCollision, go->GetDestinationRect()) == SDL_TRUE) {
				collisionDone = true;
				ResetClock();
				break;
			}
		}
	}
	else {
		bubbleVisitor->ChangeText("Collision challenge completed!");
		CheckClock();
	}
}

void TutorialController::Shoot() {

	if (shotsAmount < 6) shotsAmount += StatsController::GetInstance()->GetTotalBullets();
	if (shotsAmount > StatsController::GetInstance()->GetTotalBullets()) {
		bubbleVisitor->ChangeText("Shoot 5 times with the spacebar");
		ResetClock();
	}
	else {
		bubbleVisitor->ChangeText("Shoot challenge completed!");
		CheckClock();
	}
}

void TutorialController::Swap() {

	if (!weaponAdded) mike->AddWeapon(new MachineGun()); weaponAdded = true;
	if (!dynamic_cast<MachineGun*>(mike->GetWeapon()) && !swapDone) {
		bubbleVisitor->ChangeText("Press Q or E to swap weapon");
		ResetClock();
	}
	else {
		bubbleVisitor->ChangeText("Swap weapon challenge completed!");
		swapDone = true;
		CheckClock();
	}
}

void TutorialController::Kill() {

	if (!waveStarted) spawnController->TutorialRevertReset(amountOfZombies); waveStarted = true;
	if (amountOfZombies > StatsController::GetInstance()->GetKills()) {
		bubbleVisitor->ChangeText("Kill all zombies");
		ResetClock();
	}
	else {
		bubbleVisitor->ChangeText("Kill zombie challenge completed!");
		if (amountOfZombies == spawnController->GetAmountSpawned()) {
			StatsController::GetInstance()->AddWaveDefeated();
			spawnController->NextWave();
			spawnController->TutorialReset();
		}
		CheckClock();
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
