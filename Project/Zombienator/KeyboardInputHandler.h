#pragma once
#include "InputContainer.h"
#include <SDL.h>
class KeyboardInputHandler
{
public:
	static KeyboardInputHandler& GetInstance() {
		static KeyboardInputHandler instance;
		return instance;
	}
	void SetKey(SDL_Keycode button, bool b);

	InputContainer* inputContainer = &InputContainer::GetInstance();
private:
	KeyboardInputHandler() {};
	~KeyboardInputHandler() {};
	KeyboardInputHandler(KeyboardInputHandler const&) = delete;
	void operator=(KeyboardInputHandler const&) = delete;
};

