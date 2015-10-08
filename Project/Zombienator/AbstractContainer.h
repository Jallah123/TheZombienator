#include "Behaviour.h"
#include <vector>
#pragma once
class AbstractContainer
{
protected:
	std::vector<Behaviour*> arr;
public:
	AbstractContainer();
	~AbstractContainer();
	void Add(Behaviour* b) { arr.push_back(b); }
	void Remove(Behaviour* b) {
		std::vector<Behaviour*>::iterator it;
		for (it = arr.begin(); it != arr.end(); ){
			/*if ((*it)->ID() == b->ID()) {
				delete * it;
				it = arr.erase(it);
			} else {
			   ++it;
		   }*/
		}
	}

	virtual void Register() = 0;
};