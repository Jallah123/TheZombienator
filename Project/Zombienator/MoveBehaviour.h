#pragma once
#include "Behaviour.h"
class Map;

class MoveBehaviour 
	: public Behaviour 
{
protected:
	Map* map = nullptr;
public:
	MoveBehaviour();
	virtual ~MoveBehaviour();

	void SetMap(Map* m);

	virtual void Move(float dt) = 0;
};