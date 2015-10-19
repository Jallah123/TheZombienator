#include <iostream>
#include "CollisionLayer.h"
using namespace std;

CollisionLayer::CollisionLayer() {

}

void CollisionLayer::addCollisionObject(CollisionObject collisionObject)
{
	collisionObjects.push_back(collisionObject);
}
