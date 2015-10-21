#pragma once
using namespace std;

class CollisionObject
{
public:
	CollisionObject(int _id, int _x, int _y, int _width, int _height);
	int getId() { return id; };
	int getHeight() { return height; };
	int getWidth() { return width; };
	int getX() { return x; };
	int getY() { return y; };

private:
	int id;
	int height;
	int width;
	int x;
	int y;

protected:

};