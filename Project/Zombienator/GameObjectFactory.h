#pragma once
#include <map>
#include <memory>
#include <functional>

//containers
class DrawContainer;
class AnimateContainer;
class AnimateContainer;
class ActionContainer;
class MoveContainer;
class CollideContainer;
class GameObjectContainer;

//classes
class GameObject;
class Mike;
class Zombie;
class NormalBullet;
class PlayableCharacter;
class MachineGunBullet;

struct SDL_Renderer;

class GameObjectFactory
{
	//http://www.codeproject.com/Articles/567242/AplusC-b-bplusObjectplusFactory
private:
	GameObjectFactory() {
	};// EMPTY CONSTRUCTOR IS IMPORTANT
	static DrawContainer* drawContainer;
	static AnimateContainer* animateContainer;
	static ActionContainer* actionContainer;
	static MoveContainer* moveContainer;
	static CollideContainer* collideContainer;
	static GameObjectContainer* gameObjectContainer;
	static SDL_Renderer* renderer;
	
	static std::map<std::string, std::function<GameObject*(void)>> registry;
public:
	~GameObjectFactory();
	static GameObjectFactory* Instance() {//Singleton
		static GameObjectFactory f;
		return &f;
	}
	static GameObject* Find(std::string name);

	static void Register(std::string name, std::function<GameObject*(void)> fn);
	static void SetContainers(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, ActionContainer* actionC, CollideContainer* collideC, GameObjectContainer* gameObjectC, SDL_Renderer* ren);

	static Mike* CreateMike();
	static Zombie* CreateZombie();
	static NormalBullet* CreateNormalBullet(PlayableCharacter* obj);
	static MachineGunBullet* CreateMachineGunBullet(PlayableCharacter* obj);
};