#include "MoveBehaviour.h"

MoveBehaviour::MoveBehaviour() : Behaviour() {}
MoveBehaviour::~MoveBehaviour() {}

void MoveBehaviour::SetMap(Map * m)
{
	this->map = m;
}

