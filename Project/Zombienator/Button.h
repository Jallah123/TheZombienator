#pragma once
#include "AbstractUIComponent.h"
#include "string"
#include "SDL.h"

class Button : public AbstractUIComponent
{
public:
	Button(SDL_Renderer& ren, std::string text, std::string img_url);
	void Draw(SDL_Renderer & ren);
	void ClickAction();
	~Button();
private:
	SDL_Texture* Message;
	SDL_Texture* Image;
};
