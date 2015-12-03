#pragma once
#include "SDL.h"
#include "SDL_Image.h"
#include "SDL_ttf.h"
#include "Program.h"
#include <map>
#include <string>
#include <iostream>
#include "FontEnum.cpp"

class TextureFactory
{
public:
	static SDL_Texture* GenerateTextureFromImgUrl(std::string url);
	static SDL_Texture* GenerateTextureFromTextHud(std::string text, SDL_Color color = { 0,0,0 });
	static SDL_Texture* GenerateTextureFromTextMenu(std::string text, SDL_Color color = { 0,0,0 });
	static std::pair<SDL_Texture*, SDL_Rect> GenerateText(std::string text, int fontSize, int xPos, int yPos, FontEnum fontEnum, SDL_Color color = { 0,0,0 });
private:
	TextureFactory();
	static std::map<FontEnum, char*> FontMap;
	static SDL_Texture* GenerateTextureFromSurface(SDL_Surface* surface);
	SDL_Texture* FindTexture(std::string url);
	std::map<std::string, SDL_Texture*> textures;
	~TextureFactory();
};

