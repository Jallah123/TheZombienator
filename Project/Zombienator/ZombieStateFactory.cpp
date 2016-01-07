#include "ZombieStateFactory.h"
#include "ZombieWalkingState.h"
#include "ZombieStandStillState.h"
#include "ZombieAttackState.h"
#include "ZombieDeadState.h"

#include "BadassAttackState.h"
#include "BadassStillState.h"
#include "BadassWalkingState.h"

std::map<ZombieStateEnum, std::function<ZombieState*(void)>> fillMap()
{
	std::map<ZombieStateEnum, std::function<ZombieState*(void)>> map;
	map[ZombieStateEnum::WALKING] = [](void) -> ZombieState * { return new ZombieWalkingState; };
	map[ZombieStateEnum::STANDSTILL] = [](void) -> ZombieState * { return new ZombieStandStillState; };
	map[ZombieStateEnum::ATTACKING] = [](void) -> ZombieState * { return new ZombieAttackState; };
	map[ZombieStateEnum::DEAD] = [](void) -> ZombieState * { return new ZombieDeadState; };

	map[ZombieStateEnum::BAD_WALK] = [](void) -> ZombieState * { return new BadassWalkingState; };
	map[ZombieStateEnum::BAD_STILL] = [](void) -> ZombieState * { return new BadassStillState; };
	map[ZombieStateEnum::BAD_ATTACK] = [](void) -> ZombieState * { return new BadassAttackState; };

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