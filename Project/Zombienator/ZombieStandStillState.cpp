#include "ZombieStandStillState.h"
#include "ZombieStateFactory.h"

ZombieStandStillState::ZombieStandStillState()
{
}


ZombieStandStillState::~ZombieStandStillState()
{
}

void ZombieStandStillState::CheckState()
{
	Zombie* z = GetOwner();
	Character* target = z->GetTarget();
	if (target != nullptr && !target->IsDeath()) {
		z->SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::WALKING, z));
		return;
	}
}

void ZombieStandStillState::Update(float dt)
{
	CheckState();
	Zombie* z = GetOwner();
	z->SetMoveDir(Direction::NONE);
}