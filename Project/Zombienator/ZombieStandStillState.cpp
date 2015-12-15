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

	if (!stateChanged) {
		stateChanged = true;
		z->SetTexture(z->GetNormalTexture());
	}

	if (z->IsDeath()) {
		z->SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::DEAD, z));
		return;
	}
	else if (target != nullptr && !target->IsDeath()) {
		z->SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::WALKING, z));
		return;
	}
}

void ZombieStandStillState::Update(float dt)
{
	CheckState();
}