#pragma once
#include "MenuScreen.h"
#include "Image.h"
#include <string>

class SelectionScreen :
	public MenuScreen
{
private:
	int currentImageIndex = 0;
	std::vector<Image*> images;
	std::pair<SDL_Texture*, SDL_Rect> title;
	std::pair<SDL_Texture*, SDL_Rect> subTitle;
	string mapUrl = "";
	int amountOfPlayers;
	std::vector <std::string> characterImages;
public:
	SelectionScreen(SDL_Renderer* ren);
	~SelectionScreen();

	std::vector<std::string>& getCharacterImages() { return characterImages; };

	int getAmountOfPlayers() { return amountOfPlayers; };

	void setSubTitle(std::pair<SDL_Texture*, SDL_Rect> _subTitle) 
	{ 
		SDL_DestroyTexture(subTitle.first);
		subTitle = _subTitle; 
	};

	void AddImage(Image* img);
	std::vector<Image*> GetImages() { return images; };
	int GetCurrentImageIndex() { return currentImageIndex; };

	void SetCurrentImageIndex(int index) { currentImageIndex = index; };

	string getMapUrl() { return mapUrl; };
	void setMapUrl(string _mapUrl) { mapUrl = _mapUrl; };

	void setAmountOfPlayers(int _amountOfPlayers) { amountOfPlayers = _amountOfPlayers; };

	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
};

