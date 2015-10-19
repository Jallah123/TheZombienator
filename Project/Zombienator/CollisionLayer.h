#pragma once
#include <vector>
#include "CollisionObject.h"
using namespace std;

class CollisionLayer
{
public:
	CollisionLayer();
	void addCollisionObject(CollisionObject collisionObject);
	vector<CollisionObject> getCollisionObjects() { return collisionObjects; };

private:
	vector<CollisionObject> collisionObjects;

protected:

};