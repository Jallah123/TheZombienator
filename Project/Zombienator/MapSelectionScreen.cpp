#include "MapSelectionScreen.h"
#include "Map.h"
#include "DirectoryUtils.h"
#include <iostream>

MapSelectionScreen::MapSelectionScreen(SDL_Renderer* ren)
{
	vector<string> test = DirectoryUtils::getFilesFromDirectory("maps", "json", true);
	for (auto s : test)
	{
		Map* m = new Map{ s };
		m->SetTileSize(16);
		maps.push_back(m);
	}
}

void MapSelectionScreen::Update(float dt)
{

}

void MapSelectionScreen::Draw(SDL_Renderer& ren, float dt)
{
	Map* currentMap = maps[currentMapIndex];
	currentMap->Draw(ren, 200, 200);
	// 5currentMap->DrawFrontLayer(ren, 0, 0);
}

MapSelectionScreen::~MapSelectionScreen()
{
	for (auto s : maps)
	{
		delete s;
	}
}
