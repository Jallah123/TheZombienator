#pragma once
#include "Behaviour.h"

class KeyboardInputHandler;

class MoveBehaviour : public Behaviour {
	private:
	public:
		MoveBehaviour();
		~MoveBehaviour();

		void Move(float dt, int ticks, KeyboardInputHandler& iC);
};