#pragma once
#include "MenuScreen.h"
#include "Image.h"

class SelectionScreen :
	public MenuScreen
{
public:
	SelectionScreen(SDL_Renderer* ren);
	void AddImage(Image img);
	void Next();
	void Previous();
	~SelectionScreen();
	int currentImageIndex{ 0 };
	Image* currentImage{ nullptr };
	std::vector<Image> images;
private:
};

