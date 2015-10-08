#pragma once
#include <map>
#include <iostream>
class InputContainer
{
public:
	InputContainer();
	std::map<char, bool> GetKeys() { return keys; };
	void SetKey(char c, bool b) { keys[c] = b; };
	bool GetKeyState(char c) { return keys[c]; };
	~InputContainer();
private:
	std::map<char, bool> keys;
};

