#include "ZombieStateFactory.h"
#include "ZombieWalkingState.h"
#include "ZombieStandStillState.h"
#include "ZombieAttackState.h"

std::map<ZombieStateEnum, std::function<ZombieState*(void)>> fillMap()
{
	std::map<ZombieStateEnum, std::function<ZombieState*(void)>> map;
	map[ZombieStateEnum::WALKING] = [](void) -> ZombieState * { return new ZombieWalkingState; };
	map[ZombieStateEnum::STANDSTILL] = [](void) -> ZombieState * { return new ZombieStandStillState; };
	map[ZombieStateEnum::ATTACKING] = [](void) -> ZombieState * { return new ZombieAttackState; };
	return map;
}

std::map<ZombieStateEnum, std::function<ZombieState*(void)>> ZombieStateFactory::StateMap = fillMap();

ZombieState* ZombieStateFactory::Create(ZombieStateEnum state, Zombie* owner)
{
	ZombieState* zombieState = nullptr;
	auto it = StateMap.find(state);
	if (it != StateMap.end())
	{
		zombieState = it->second();
		zombieState->SetOwner(owner);
	}
	return zombieState;
}