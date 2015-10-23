#pragma once
#include "AbstractContainer.h"
#include "KeyboardInputHandler.h"


class MoveContainer : public AbstractContainer {
	public:
		MoveContainer();
		~MoveContainer();

		void Move(float dt);
};