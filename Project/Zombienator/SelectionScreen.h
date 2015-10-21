#pragma once
#include "MenuScreen.h"
#include "Image.h"

class SelectionScreen :
	public MenuScreen
{
public:
	SelectionScreen(SDL_Renderer* ren);
	void AddImage(Image img);
	int GetCurrentImageIndex() { return currentImageIndex; };
	Image* GetCurrentImage() { return currentImage; };
	std::vector<Image> GetImages() { return images; };
	void SetCurrentImageIndex(int index) { currentImageIndex = index; };
	void SetCurrentImage(Image* image) { *currentImage = *image; };
	~SelectionScreen();
private:
	int currentImageIndex{ 0 };
	Image* currentImage{ nullptr };
	std::vector<Image> images;
};

