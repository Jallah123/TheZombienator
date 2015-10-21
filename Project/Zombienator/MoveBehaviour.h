#pragma once
#include "Behaviour.h"

class KeyboardInputHandler;

class MoveBehaviour : public Behaviour {
	private:
		float spriteDstY = 0.0f;
		float spriteDstX = 0.0f;
	public:
		MoveBehaviour();
		~MoveBehaviour();

		void Move(float dt, int ticks, KeyboardInputHandler& iC);
};