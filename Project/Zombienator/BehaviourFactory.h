#ifndef BEHAVIOUR_FACTORY
#define BEHAVIOUR_FACTORY
#pragma once
#include <map>
#include <memory>
#include <functional>

//Behaviours
class Behaviour;
class DrawBehaviour;
class AnimateBehaviour;
class MoveBehaviour;
class ActionBehaviour;
class CollideBehaviour;

class GameObject;

class BehaviourFactory
{
private:
	BehaviourFactory() {};// EMPTY CONSTRUCTOR IS IMPORTANT
public:
	~BehaviourFactory();// Deconstructor
	static BehaviourFactory* Instance() {//Singleton
		static BehaviourFactory f;
		return &f;
	}
	static Behaviour* Find(std::string name);

	static void Register(std::string name, std::function<Behaviour*(void)> fn);
	static DrawBehaviour* CreateDrawBehaviour(std::string name, GameObject* obj);
	static AnimateBehaviour* CreateAnimateBehaviour(std::string name, GameObject* obj);
	static MoveBehaviour* CreateMoveBehaviour(std::string name, GameObject* obj);
	static ActionBehaviour* CreateActionBehaviour(std::string name, GameObject* obj);
	static CollideBehaviour* CreateCollideBehaviour(std::string name, GameObject* obj);

	static std::map<std::string, std::function<Behaviour*(void)>> registry;
};
#endif