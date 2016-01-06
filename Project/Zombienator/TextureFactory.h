#pragma once
#include <map>
#include <string>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Program.h"
#include "FontEnum.cpp"

using std::string;

class TextureFactory
{
public:
	static std::pair<SDL_Texture*, SDL_Rect> GenerateText(std::string text, int fontSize, int xPos, int yPos, FontEnum fontEnum, SDL_Color color = { 0,0,0 }, int multipleLinesSize = 0);

	static SDL_Texture* CreateTexture(string url);
	static std::pair<SDL_Texture*, SDL_Rect> CreateText(string text, SDL_Color color = { 0,0,0 }, FontEnum font = FontEnum::ROBOTO, int fontSize = 13);
	static std::pair<SDL_Texture*, SDL_Rect> CreateText(string text, SDL_Point position, SDL_Color color = { 0,0,0 }, FontEnum font = FontEnum::ROBOTO, int fontSize = 24);
private:
	TextureFactory();
	static std::map<FontEnum, char*> FontMap;
	static SDL_Texture* GenerateTextureFromSurface(SDL_Surface* surface);
	
	~TextureFactory();
};

