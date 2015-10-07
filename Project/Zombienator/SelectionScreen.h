#pragma once
#include "MenuScreen.h"
#include "Image.h"

class SelectionScreen :
	public MenuScreen
{
public:
	SelectionScreen(SDL_Renderer* ren);
	void AddImage(Image* img);
	void Next();
	void Previous();
	~SelectionScreen();
private:
	int currentImage = 0;
	std::vector<Image*> images;
};

