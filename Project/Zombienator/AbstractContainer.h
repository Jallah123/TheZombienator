#pragma once
#include <vector>

class Behaviour;
class AbstractContainer
{
protected:
	std::vector<Behaviour*> arr = {};
	
public:
	AbstractContainer();
	~AbstractContainer();

	void Add(Behaviour* b) { arr.push_back(b); }
	std::vector<Behaviour*>::iterator Remove(Behaviour* b) {
		auto index = find(arr.begin(), arr.end(), b);
		return arr.erase(index);
	}
};