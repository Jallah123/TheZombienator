#pragma once
#include <map>
#include <iostream>
#include <memory>
#include <functional>

//containers
class DrawContainer;
class AnimateContainer;
class AnimateContainer;
class ActionContainer;
class MoveContainer;
class CollideContainer;
class CharacterContainer;

//classes
class GameObject;
class Mike;
class Zombie;
class Map;
class NormalBullet;
class PlayableCharacter;
class MachineGunBullet;

class GameObjectFactory
{
	//http://www.codeproject.com/Articles/567242/AplusC-b-bplusObjectplusFactory
private:
	GameObjectFactory() {
		std::cout << "Init Factory" << std::endl;
	};// EMPTY CONSTRUCTOR IS IMPORTANT
	static DrawContainer* drawContainer;
	static AnimateContainer* animateContainer;
	static ActionContainer* actionContainer;
	static MoveContainer* moveContainer;
	static CollideContainer* collideContainer;
	static CharacterContainer* characterContainer;
	static SDL_Renderer* renderer;
	
	static std::map<std::string, std::function<GameObject*(void)>> registry;
	static Map* mapLevel;
public:
	~GameObjectFactory();
	static GameObjectFactory* Instance() {//Singleton
		static GameObjectFactory f;
		return &f;
	}
	static GameObject* Find(std::string name);

	static void Register(std::string name, std::function<GameObject*(void)> fn);
	static void SetLevel(Map* l);
	static Map* GetLevel();
	static void SetContainers(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, ActionContainer* actionC, CollideContainer* collideC, CharacterContainer* characterC, SDL_Renderer* ren);

	static Mike* CreateMike();
	static Zombie* CreateZombie();
	static NormalBullet* CreateNormalBullet(PlayableCharacter* obj);
	static MachineGunBullet* CreateMachineGunBullet(PlayableCharacter* obj);
};