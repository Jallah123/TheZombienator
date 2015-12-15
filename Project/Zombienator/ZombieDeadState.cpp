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
	// On first frame
	if (elapsedTime == 0) {
		Zombie* z = GetOwner();
		z->SetFrames(16);
		z->SetSize(64, 64);
		z->SetTexture(z->GetDeadTexture());
		z->SetSpeed(0.2f);
		z->SetMoveDir(Direction::SOUTH);
		z->SetLookDir(Direction::SOUTH);
		z->CanMove(false);
		z->SetPosition(z->getPosX() - 16, z->getPosY() - 14);
	}

	elapsedTime += dt;
	
	if (elapsedTime > totalTime) {

		Zombie* z = GetOwner();
		Character* target = z->GetTarget();

		z->Remove();
	}

}