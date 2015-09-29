#pragma once
#include "AbstractUIComponent.h"
#include "string"

class Button : public AbstractUIComponent
{
public:
	Button(SDL_Renderer& ren, std::string text);
	void Draw(SDL_Renderer & ren);
	void ClickAction();
	~Button();
private:
	SDL_Texture* Message;
};

