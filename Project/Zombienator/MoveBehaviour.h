#pragma once
#include "Behaviour.h"

class KeyboardInputHandler;

class MoveBehaviour : public Behaviour {
	public:
		MoveBehaviour();
		~MoveBehaviour();

		void Move(float dt, int ticks, KeyboardInputHandler& iC);
};