#include "CollideObject.h"

CollideObject::CollideObject() {}

CollideObject::CollideObject(float x, float y, int w, int h)
{
	SetSize(w, h);
	SetPosition(x, y);
	collRect.h = h;
	collRect.y = y;
}

CollideObject::~CollideObject() {}