#pragma once
#include <map>
#include <memory>
#include <functional>

class GameObject;
class Mike;
class Zombie;

class GameObjectFactory
{
	//http://www.codeproject.com/Articles/567242/AplusC-b-bplusObjectplusFactory
private:
	GameObjectFactory() { }// EMPTY CONSTRUCTOR IS IMPORTANT
	
public:
	~GameObjectFactory();
	static std::map<std::string, std::function<GameObject*(void)>> registry;

	static GameObjectFactory* Instance() {//Singleton
		static GameObjectFactory f;
		return &f;
	}
	static void Register(std::string name, std::function<GameObject*(void)> fn);
	static GameObject* Find(std::string name);
	
	

	static Mike* CreateMike();
	static Zombie* CreateZombie(std::string name);
};