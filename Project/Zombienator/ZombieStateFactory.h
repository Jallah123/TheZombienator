#pragma once
#include "Zombie.h"
#include "ZombieStateEnum.cpp"
#include "ZombieState.h"
#include <map>
#include <functional>

class ZombieStateFactory
{
public:
	static ZombieState* ZombieStateFactory::Create(ZombieStateEnum state, Zombie* owner);
private:
	static std::map<ZombieStateEnum, std::function<ZombieState*(void)>> StateMap;
};

