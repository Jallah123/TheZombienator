#pragma once
#include "AbstractUIComponent.h"
#include "TextureFactory.h"
#include <SDL_ttf.h>

class Label : public AbstractUIComponent
{
protected:
	SDL_Color color = { 255, 255, 255 };
	std::pair<SDL_Texture*, SDL_Rect> label = {};
public:
	Label();
	Label(SDL_Renderer& ren, char* text, int posX, int posY, int fontSize, std::string fontUrl, SDL_Color color = { 0,0,0 });
	~Label();
	void Draw(SDL_Renderer& ren);
	virtual void ClickAction() override;
};

