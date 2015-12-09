#include "ZombieDeadState.h"
#include "ZombieStateFactory.h"

ZombieDeadState::ZombieDeadState()
{
}


ZombieDeadState::~ZombieDeadState()
{
}

void ZombieDeadState::CheckState()
{
	Zombie* z = GetOwner();
	Character* target = z->GetTarget();
	
	cout << "DEAD" << endl;

}

void ZombieDeadState::Update(float dt)
{
	CheckState();
}