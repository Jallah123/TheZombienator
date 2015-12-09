#include "MapSelectionScreen.h"
#include "Map.h"
#include "DirectoryUtils.h"
#include <iostream>

MapSelectionScreen::MapSelectionScreen(SDL_Renderer* ren)
{
	vector<string> test = DirectoryUtils::getFilesFromDirectory("maps", "json");
	for (auto s : test)
	{
		std::cout << s << '\n';
	}
}

void MapSelectionScreen::Update(float dt)
{

}

void MapSelectionScreen::Draw(SDL_Renderer& ren, float dt)
{

}

MapSelectionScreen::~MapSelectionScreen()
{
}
