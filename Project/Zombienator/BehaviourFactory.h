#ifndef BEHAVIOUR_FACTORY_H
#define BEHAVIOUR_FACTORY_H

#include <map>
#include <memory>
#include <functional>
#include "Behaviour.h"
#pragma once
class BehaviourFactory
{
private:
	BehaviourFactory() { }// EMPTY CONSTRUCTOR IS IMPORTANT
public:
	~BehaviourFactory();// Deconstructor
	static BehaviourFactory* Instance() {//Singleton
		static BehaviourFactory f;
		return &f;
	}
	static void Register(std::string name, std::function<Behaviour*(void)> fn);
	static std::shared_ptr<Behaviour> Create(std::string name, GameObject* obj);
	static std::map<std::string, std::function<Behaviour*(void)>> registry;
};

#endif