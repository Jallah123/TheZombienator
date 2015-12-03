#pragma once
#include "MenuScreen.h"
#include "Image.h"

class SelectionScreen :
	public MenuScreen
{
private:
	int currentImageIndex = 0;
	std::vector<Image*> images;
	std::pair<SDL_Texture*, SDL_Rect> title;
public:
	SelectionScreen(SDL_Renderer* ren);
	~SelectionScreen();

	void AddImage(Image* img);
	std::vector<Image*> GetImages() { return images; };
	int GetCurrentImageIndex() { return currentImageIndex; };
	
	void SetCurrentImageIndex(int index) { currentImageIndex = index; };

	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
};

