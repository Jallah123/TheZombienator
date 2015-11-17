#pragma once
#include "InputContainer.h"
#include <SDL.h>
#include <iostream>
class ControllerInputHandler
{
public:
	static ControllerInputHandler& GetInstance() {
		static ControllerInputHandler instance;
		return instance;
	}

	void SetButton(SDL_ControllerButtonEvent button, bool b);
	void ControllerInputHandler::SetAxis(SDL_ControllerAxisEvent axisEvent, bool b);

	InputContainer* inputContainer = &InputContainer::GetInstance();

private:
	ControllerInputHandler() {};
	~ControllerInputHandler() {};
	ControllerInputHandler(ControllerInputHandler const&) = delete;
	void operator=(ControllerInputHandler const&) = delete;
};

