#include <map>
#include <memory>
#include <functional>
#include "GameObject.h"
#pragma once

class GameObjectFactory
{
	//http://www.codeproject.com/Articles/567242/AplusC-b-bplusObjectplusFactory
//private:
	//
private:
	GameObjectFactory();
public:
	~GameObjectFactory();
	static GameObjectFactory* Instance() {
		static GameObjectFactory f;
		return &f;
	}
	static void Register(std::string name, std::function<GameObject*(void)> fn);
	static std::shared_ptr<GameObject> Create(std::string name);
	static std::map<std::string, std::function<GameObject*(void)>> registry;
};

