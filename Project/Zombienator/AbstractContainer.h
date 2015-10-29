#pragma once
#include <vector>
#include "Behaviour.h"

class AbstractContainer
{
protected:
	std::vector<Behaviour*> arr;
	
public:
	AbstractContainer();
	~AbstractContainer();

	void Add(Behaviour* b) { arr.push_back(b); }
	void Remove(Behaviour* b) {
		auto index = find(arr.begin(), arr.end(), b);
		arr.erase(index);
	}
};