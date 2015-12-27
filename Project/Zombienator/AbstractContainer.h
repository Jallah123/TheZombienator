#pragma once
#include <vector>

class Behaviour;
class AbstractContainer
{
protected:
	std::vector<Behaviour*> arr = {};
	std::vector<Behaviour*> arrRemove = {};
	
public:
	AbstractContainer();
	~AbstractContainer();

	void Add(Behaviour* b) { arr.push_back(b); }
	void RemoveAll() {
		if (arrRemove.size() == 0) return;
		for (const auto& b : arrRemove)
		{
			Remove(b);
		}
		arrRemove.clear();
	}
	void Remove(Behaviour* b) {
		if (b == nullptr) return;
		auto index = find(arr.begin(), arr.end(), b);
		arr.erase(index);
	}
};