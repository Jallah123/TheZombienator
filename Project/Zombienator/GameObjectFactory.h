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
class PlayableCharacter;
class Character;
class Zombie;
class BadassZombie;
//Bullets
class NormalBullet;
class PlayableCharacter;
class MachineGunBullet;
class KeyBinding;
class BazookaBullet;
class MineBullet;
class ZombieBlubberBullet;
//Pickups
class Pickup;
class Medkit;
class AmmoBox;

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

	static PlayableCharacter* CreatePlayableCharacter(std::string img_url, KeyBinding* keyBinding);
	static Zombie* CreateZombie();
	static BadassZombie* CreateBadassZombie();
	static NormalBullet* CreateNormalBullet(PlayableCharacter* obj);
	static MachineGunBullet* CreateMachineGunBullet(PlayableCharacter* obj);
	static BazookaBullet* CreateBazookaBullet(PlayableCharacter* obj);
	static MineBullet* CreateMineBullet(PlayableCharacter* obj);
	static ZombieBlubberBullet* CreateZombieBlubber(Zombie* obj);

	static Medkit* CreateMedkit(Character* obj);
	static AmmoBox* CreateAmmoBox(Character* obj);
	static Pickup* CreateRandomPickup(Character* obj);
};