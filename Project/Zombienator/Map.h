#pragma once
using namespace std;

class Map
{
public:
	Map();
	void setImage(char* _img_path);
	char* getImage() { return img_path; };
private:
	char* img_path;
protected:

};