#include "ZombieAttackState.h"
#include "Zombie.h"
#include "ZombieStateFactory.h"

ZombieAttackState::ZombieAttackState() {}
ZombieAttackState::~ZombieAttackState() {}

void ZombieAttackState::CheckState()
{
	Zombie* z = GetOwner();
	Character* target = z->GetTarget();

	if (target->IsDeath())
	{
		z->SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::DEAD, z));
		return;
	}

	if (!z->IsInAttackRadius(target)) {
		z->SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::WALKING, z));
		return;
	}
}

void ZombieAttackState::Update(float dt)
{
	CheckState();
	PlaySound();
	DoDamage();
}

void ZombieAttackState::PlaySound() // 1 Sound per 4 seconds
{
	if (timeTillNewSound <= GetPassedTime(soundBegin)) {
		if (!timeTillNewSound)
			timeTillNewSound = GetOwner()->GetSoundSpeed();
		soundBegin = clock();
		SoundController::GetInstance().PlaySound("assets/sounds/zombie-attack.wav", 0);
	}
}

void ZombieAttackState::DoDamage() // 0.5 DPS
{
	if (timeTillNewDamage <= GetPassedTime(damageBegin)) {
		if (!timeTillNewDamage)
			timeTillNewDamage = GetOwner()->GetAttackSpeed();
		damageBegin = clock();
		GetOwner()->GetTarget()->TakeHit(GetOwner()->GetAttackDamage());
	}
}
