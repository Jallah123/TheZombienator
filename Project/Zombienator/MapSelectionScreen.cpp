#include "MapSelectionScreen.h"
#include "Map.h"
#include "DirectoryUtils.h"
#include <iostream>

MapSelectionScreen::MapSelectionScreen(SDL_Renderer* ren)
{
	vector<string> test = DirectoryUtils::getFilesFromDirectory("maps", "json", true);
	for (auto s : test)
	{
		maps.push_back(new Map{ s });
	}
}

void MapSelectionScreen::Update(float dt)
{

}

void MapSelectionScreen::Draw(SDL_Renderer& ren, float dt)
{
	for (auto s : maps)
	{
		s->Draw(ren, 0, 0, 0);
	}
}

MapSelectionScreen::~MapSelectionScreen()
{
	for (auto s : maps)
	{
		delete s;
	}
}
