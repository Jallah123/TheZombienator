#include "ZombieDeadState.h"
#include "ZombieStateFactory.h"

ZombieDeadState::ZombieDeadState()
{
	SoundController->PlaySound("assets/sounds/DeathFlash.wav", 0);
}

ZombieDeadState::~ZombieDeadState()
{
}

void ZombieDeadState::CheckState()
{

}

void ZombieDeadState::Update(float dt)
{
	elapsedTime += dt;
	
	if (elapsedTime > totalTime) {

		Zombie* z = GetOwner();
		Character* target = z->GetTarget();

		z->Remove();
	}

}