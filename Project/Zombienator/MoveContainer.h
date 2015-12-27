#pragma once
#include "AbstractContainer.h"

class MoveContainer : public AbstractContainer {
	public:
		MoveContainer();
		~MoveContainer();

		void Move(float dt);
};