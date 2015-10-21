#pragma once
#include "AbstractUIComponent.h"
#include "string"
#include "SDL.h"

class SettingsButton : public AbstractUIComponent
{
public:
	SettingsButton(SDL_Renderer& ren, std::string text, std::string img_url);
	void Draw(SDL_Renderer & ren);
	void ClickAction();
	~SettingsButton();
private:
	SDL_Texture* Message;
	SDL_Texture* Image;
};
