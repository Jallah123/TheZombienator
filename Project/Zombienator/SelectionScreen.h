#pragma once
#include "MenuScreen.h"
#include "Image.h"

class SelectionScreen :
	public MenuScreen
{
private:
	int currentImageIndex = 0;
	Image* currentImage = nullptr;
	std::vector<Image> images;

public:
	SelectionScreen();
	SelectionScreen(SDL_Renderer* ren);
	~SelectionScreen();

	
	void AddImage(Image img);

	std::vector<Image> GetImages() { return images; };
	int GetCurrentImageIndex() { return currentImageIndex; };
	Image* GetCurrentImage() { return currentImage; };
	
	void SetCurrentImageIndex(int index) { currentImageIndex = index; };
	void SetCurrentImage(Image* image) { *currentImage = *image; };
};

