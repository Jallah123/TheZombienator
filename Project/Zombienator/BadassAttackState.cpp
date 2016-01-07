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
	z->SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::BAD_WALK, z));
	
}

void BadassAttackState::Update(float dt)
{
	
	elapsedTime += dt;
	if (elapsedTime >= this->shootDelay)
	{
		GameObjectFactory::Instance()->CreateZombieBlubber(GetOwner());
		CheckState();
		elapsedTime = 0;
	}
}
