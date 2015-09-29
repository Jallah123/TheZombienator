#pragma once
#include "AbstractUIComponent.h"
class Button : public AbstractUIComponent
{
public:
	Button() : AbstractUIComponent() {};
	void Draw(SDL_Renderer & ren);
	void ClickAction();
	~Button();
};

