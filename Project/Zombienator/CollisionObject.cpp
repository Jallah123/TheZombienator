#include <iostream>
#include "CollisionObject.h"
using namespace std;

CollisionObject::CollisionObject(int _id, int _height, int _width, int _x, int _y)
{
	id = _id;
	height = _height;
	width = _width;
	x = _x;
	y = _y;
}
