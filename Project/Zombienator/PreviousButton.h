/*
#pragma once
#include "AbstractUIComponent.h"
#include "string"
#include "SDL.h"
#include "functional"
#include "SelectionScreen.h"

class PreviousButton : public AbstractUIComponent
{
public:
	PreviousButton(SDL_Renderer& ren, std::string text, std::string img_url, SelectionScreen& s);
	SelectionScreen* SelectionScreen{ nullptr };
	void Draw(SDL_Renderer & ren);
	void ClickAction();
	~PreviousButton();
private:
	SDL_Texture* Message;
	SDL_Texture* Image;
};
*/