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
	~MapSelectionScreen();
};

