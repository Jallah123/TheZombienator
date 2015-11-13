#pragma once
#include <vector>
#include <algorithm>
#include "Character.h"
#include "Zombie.h"
#include "StatsController.h"
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
		if (dynamic_cast<Zombie*>(c)) StatsController::Instance()->AddKill();
		characters.erase(std::remove(characters.begin(),characters.end(),c),characters.end());
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


