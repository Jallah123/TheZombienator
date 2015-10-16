#ifndef ABSTRACT_CONTAINER_H
#define ABSTRACT_CONTAINER_H

#pragma once
#include <vector>

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
};

#include "AnimateContainer.h"
#include "DrawContainer.h"
#endif