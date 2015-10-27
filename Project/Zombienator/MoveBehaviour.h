#pragma once
#include "Behaviour.h"

class KeyboardInputHandler;

class MoveBehaviour : public Behaviour {
	private:
	public:
		MoveBehaviour();
		virtual ~MoveBehaviour();

		//virtual void Move(float dt, KeyboardInputHandler& iC);
		virtual void Move(float dt) = 0;
};