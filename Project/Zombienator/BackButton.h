#pragma once
#include "AbstractUIComponent.h"
#include "string"
#include "SDL.h"

class BackButton : public AbstractUIComponent
{
public:
	BackButton(SDL_Renderer& ren, std::string text, std::string img_url);
	void Draw(SDL_Renderer & ren);
	void ClickAction();
	~BackButton();
private:
	SDL_Texture* Message;
	SDL_Texture* Image;
};
