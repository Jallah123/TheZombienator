#pragma once
#include "AbstractContainer.h"
#include "KeyboardInputHandler.h"


class MoveContainer : public AbstractContainer {
	public:
		KeyboardInputHandler& inputContainer = KeyboardInputHandler::GetInstance();

		MoveContainer();
		~MoveContainer();

		void Move(float dt);
};