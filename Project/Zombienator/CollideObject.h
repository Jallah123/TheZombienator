#pragma once
#include "GameObject.h"

class CollideObject : public GameObject
{
	public:
		CollideObject();
		CollideObject(float x, float y, int w, int h);
		~CollideObject();
};

