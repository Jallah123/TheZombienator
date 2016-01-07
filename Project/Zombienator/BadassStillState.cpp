#include "BadassStillState.h"
#include "Character.h"
#include "ZombieStateFactory.h"


BadassStillState::BadassStillState()
{
}


BadassStillState::~BadassStillState()
{
}

void BadassStillState::CheckState()
{
	Zombie* z = GetOwner();
	Character* target = z->GetTarget();
	if (z->IsDeath()) {
		z->SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::DEAD, z));
		return;
	}
	else if (target != nullptr && !target->IsDeath()) {
		z->SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::BAD_WALK, z));
		return;
	}

}

void BadassStillState::Update(float dt)
{
	CheckState();
}
