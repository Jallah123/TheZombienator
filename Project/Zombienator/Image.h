#pragma once
#include "AbstractUIComponent.h"
#include "string"
#include "SDL.h"

class Image :
	public AbstractUIComponent
{
public:
	Image(SDL_Renderer& ren, std::string img_url);
	void Draw(SDL_Renderer & ren);
	void ClickAction();
	~Image();
private:
	SDL_Texture* Background;
};

