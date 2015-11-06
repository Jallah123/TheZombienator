#pragma once
#include "SDL.h"
#include "Program.h"
#include <map>
#include <string>
#include <iostream>

class TextureFactory
{
public:
	static SDL_Texture* GenerateTexture(std::string url);
private:
	TextureFactory();
	SDL_Texture* FindTexture(std::string url);
	void SetRenderer(SDL_Renderer* _renderer) { renderer = _renderer; }
	SDL_Renderer* renderer;
	std::map<std::string, SDL_Texture*> textures;
	~TextureFactory();
};

