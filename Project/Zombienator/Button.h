#pragma once
#include "AbstractUIComponent.h"
#include <SDL_ttf.h>

class Button : public AbstractUIComponent
{
protected:
	SDL_Color color = { 255, 255, 255 };
	SDL_Texture* message = nullptr;
	SDL_Texture* image = nullptr;
	
public:
	Button();
	Button(SDL_Renderer& ren, char* text, char* img_url);
	virtual ~Button();
	
	void Draw(SDL_Renderer& ren);
	virtual void ClickAction() = 0;
};
