#pragma once
#include "AbstractUIComponent.h"
#include "TextureFactory.h"
#include <SDL_ttf.h>

class Label : public AbstractUIComponent
{
protected:
	SDL_Color color = { 255, 255, 255 };
	std::pair<SDL_Texture*, SDL_Rect> label = {};
	int _posX;
	int _posY;
	int _fontSize;
	SDL_Color _color;
public:
	Label();
	Label(SDL_Renderer& ren, string text, int posX, int posY, int fontSize, SDL_Color color = { 0,0,0 });
	Label(SDL_Renderer& ren, int number, int posX, int posY, int fontSize, SDL_Color color = { 0,0,0 });
	void updateText(string text);
	void updateText(int text);
	~Label();
	void Draw(SDL_Renderer& ren);
	virtual void ClickAction() override;
};

