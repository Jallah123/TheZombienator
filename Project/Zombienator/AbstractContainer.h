#ifndef ABSTRACT_CONTAINER_H
#define ABSTRACT_CONTAINER_H
#include "Behaviour.h"
#include <vector>
#pragma once

class Behaviour;

class AbstractContainer
{
protected:
	std::vector<Behaviour*> arr;
	
public:
	AbstractContainer();
	~AbstractContainer();

	void Add(Behaviour* b) { arr.push_back(b); }
	void Remove(Behaviour* b) {}
	virtual void Register() = 0;
};
#endif