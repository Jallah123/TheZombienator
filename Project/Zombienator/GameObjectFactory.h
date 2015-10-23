#pragma once
#include <map>
#include <memory>
#include <functional>
#include "GameObject.h"
#include "AbstractContainer.h"
#include "Character.h"

class GameObjectFactory
{
	//http://www.codeproject.com/Articles/567242/AplusC-b-bplusObjectplusFactory
private:
	GameObjectFactory() { }// EMPTY CONSTRUCTOR IS IMPORTANT
public:
	~GameObjectFactory();
	static GameObjectFactory* Instance() {//Singleton
		static GameObjectFactory f;
		return &f;
	}
	static void Register(std::string name, std::function<GameObject*(void)> fn);
	static Character* CreateCharacter(std::string name);
	static std::map<std::string, std::function<GameObject*(void)>> registry;
};