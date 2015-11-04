#pragma once
#include <vector>
#include <algorithm>
#include "Character.h"
using std::vector;

class CharacterContainer
{
public:
	CharacterContainer();
	~CharacterContainer();
	void Init();
	vector<Character*> GetCharacters() { return characters; };
	void AddCharacter(Character* c) { characters.push_back(c); };
	void Remove(Character* c) {
		auto n = std::find(characters.begin(), characters.end(), c);
		characters.erase(n);
	};
	void RemoveAll() {
		if (arrRemove.size() == 0) return;
		for (const auto& c : arrRemove)
		{
			Remove(c);
		}
		arrRemove.clear();
	}
private:
	vector<Character*> characters;
	vector<Character*> arrRemove;
};


