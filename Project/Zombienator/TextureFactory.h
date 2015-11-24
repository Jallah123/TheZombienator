#pragma once
#include "SDL.h"
#include "SDL_Image.h"
#include "SDL_ttf.h"
#include "Program.h"
#include <map>
#include <string>
#include <iostream>

class TextureFactory
{
public:
	static SDL_Texture* GenerateTextureFromImgUrl(std::string url);
	static SDL_Texture* GenerateTextureFromText(std::string text, SDL_Color color, int fontSize, SDL_Renderer* renderer);
private:
	TextureFactory();
	static SDL_Texture* GenerateTextureFromSurface(SDL_Surface* surface);
	SDL_Texture* FindTexture(std::string url);
	std::map<std::string, SDL_Texture*> textures;
	~TextureFactory();
};

