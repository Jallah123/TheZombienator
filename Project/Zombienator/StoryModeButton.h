#pragma once
#include "AbstractUIComponent.h"
#include "string"
#include "SDL.h"

class StoryModeButton : public AbstractUIComponent
{
public:
	StoryModeButton(SDL_Renderer& ren, std::string text, std::string img_url);
	void Draw(SDL_Renderer & ren);
	void ClickAction();
	~StoryModeButton();
private:
	SDL_Renderer* Sdl_Renderer;
	SDL_Texture* Message;
	SDL_Texture* Image;
};
