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
	void AddCharacter(Character* character) { characters.push_back(character); };
	void RemoveCharacter(Character* character) {
		auto n = std::find(characters.begin(), characters.end(), character);
		characters.erase(n);
	};
private:
	vector<Character*> characters;
};


