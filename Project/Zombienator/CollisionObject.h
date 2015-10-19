#pragma once
using namespace std;

class CollisionObject
{
public:
	CollisionObject(int _id, int _height, int _width, int _x, int _y);

private:
	int id;
	int height;
	int width;
	int x;
	int y;

protected:

};