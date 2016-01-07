#pragma once
#include "BadassAttackState.h"
#include "GameObjectFactory.h"
#include "Zombie.h"
#include "Character.h"
#include "GameMath.h"
#include "ZombieStateFactory.h"

BadassAttackState::BadassAttackState()
{
}


BadassAttackState::~BadassAttackState()
{
}

void BadassAttackState::CheckState()
{
	Zombie* z = GetOwner();
	Character* target = z->GetTarget();

	if (z->IsDeath()) {
		z->SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::DEAD, z));
		return;
	}
	
}

void BadassAttackState::Update(float dt)
{
	
	elapsedTime += dt;
	if (elapsedTime >= this->shootDelay)
	{
		GetOwner()->SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::BAD_WALK, GetOwner()));

		GameObjectFactory::Instance()->CreateZombieBlubber(GetOwner());
		elapsedTime = 0;
	}
	CheckState();

}
