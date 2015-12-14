#pragma once
#include "MenuScreen.h"

class Map;
class MapSelectionScreen :
	public MenuScreen
{
private:
	vector<Map*> maps;
	int currentMapIndex = 0;
public:
	MapSelectionScreen(SDL_Renderer* ren);
	void MapSelectionScreen::Update(float dt) override;
	void MapSelectionScreen::Draw(SDL_Renderer& ren, float dt) override;
	void setCurrentMapIndex(int value) { currentMapIndex = value; };
	int getCurrentMapIndex() { return currentMapIndex; };
	int getAmountOfMaps() { return maps.size(); };
	Map* getCurrentMap() { return maps.at(currentMapIndex); };
	~MapSelectionScreen();
};

