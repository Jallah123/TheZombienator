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
	counter--;

	Zombie* z = GetOwner();
	Character* target = z->GetTarget();

	if (counter < 1) {
		z->Remove();
	}

}

void ZombieDeadState::Update(float dt)
{
	CheckState();
}