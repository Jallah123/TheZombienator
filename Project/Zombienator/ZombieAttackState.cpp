#include "ZombieAttackState.h"
#include "Zombie.h"
#include "ZombieStateFactory.h"

ZombieAttackState::ZombieAttackState()
{
}


ZombieAttackState::~ZombieAttackState()
{
}

void ZombieAttackState::CheckState()
{
	Zombie* z = GetOwner();
	Character* target = z->GetTarget();

	if (!z->IsInAttackRadius(target)) {
		z->SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::WALKING, z));
		return;
	}
}

void ZombieAttackState::Update(float dt)
{
	CheckState();
}
