#pragma once
#include "MenuScreen.h"
#include <SDL_ttf.h>
class CreditScreen :
	public MenuScreen
{
protected:
	SDL_Texture* Message;
	
	SDL_Rect Message_rect;

	TTF_Font* font = NULL;
	SDL_Color fontColor = { 255, 255, 255 };
	SDL_Texture* renderText(const std::string &message, SDL_Renderer *renderer);
public:
	CreditScreen(SDL_Renderer* ren);
	~CreditScreen();
	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
};

