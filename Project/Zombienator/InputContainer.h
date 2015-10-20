#pragma once
#include <map>
#include <iostream>

class InputContainer
{
public:
	static InputContainer& GetInstance() {
		static InputContainer instance;
		return instance;
	}

	std::map<char, bool> GetKeys() { return keys; };
	void SetKey(char c, bool b) { keys[c] = b; };
	bool GetKeyState(char c) { return keys[c]; };

private:
	InputContainer() {};
	~InputContainer() {};
	InputContainer(InputContainer const&) = delete;
	void operator=(InputContainer const&) = delete;
	std::map<char, bool> keys;
};