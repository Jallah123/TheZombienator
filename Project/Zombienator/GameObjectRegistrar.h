#include "GameObjectFactory.h"
#pragma once

template<class T>
class GameObjectRegistrar
{
public:
	GameObjectRegistrar(std::string classname) {
		GameObjectFactory::Instance()->Register("name", [](void) -> GameObject* {return new T(); });
	}
};