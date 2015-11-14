#pragma once
#include <map>
#include <memory>
#include <functional>
#include <SDL_render.h>

//containers
class DrawContainer;
class AnimateContainer;
class AnimateContainer;
class ActionContainer;
class MoveContainer;
class CollideContainer;
class CharacterContainer;

//Behaviours
class Behaviour;
class DrawBehaviour;
class AnimateBehaviour;
class MoveBehaviour;
class ActionBehaviour;
class CollideBehaviour;

class Map;
class GameObject;

class BehaviourFactory
{
private:
	BehaviourFactory() {};// EMPTY CONSTRUCTOR IS IMPORTANT
	static DrawContainer* drawContainer;
	static AnimateContainer* animateContainer;
	static ActionContainer* actionContainer;
	static MoveContainer* moveContainer;
	static CollideContainer* collideContainer;
	static CharacterContainer* characterContainer;
	static SDL_Renderer* renderer;
	static Map* map;
	static std::map<std::string, std::function<Behaviour*(void)>> registry;
public:
	~BehaviourFactory();// Deconstructor
	static BehaviourFactory* Instance() {//Singleton
		static BehaviourFactory f;
		return &f;
	}
	static Behaviour* Find(std::string name);

	static void Register(std::string name, std::function<Behaviour*(void)> fn);
	static void SetContainers(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, ActionContainer* actionC, CollideContainer* collideC, CharacterContainer* characterC, SDL_Renderer* ren);
	static void SetMap(Map* m);

	static DrawBehaviour* CreateDrawBehaviour(std::string name, GameObject* obj);
	static AnimateBehaviour* CreateAnimateBehaviour(std::string name, GameObject* obj);
	static MoveBehaviour* CreateMoveBehaviour(std::string name, GameObject* obj);
	static ActionBehaviour* CreateActionBehaviour(std::string name, GameObject* obj);
	static CollideBehaviour* CreateCollideBehaviour(std::string name, GameObject* obj);
};
