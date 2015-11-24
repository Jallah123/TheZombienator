#pragma once
#include "MenuScreen.h"
#include <SDL_ttf.h>
#include <set>
#include <map>

using namespace std;
class CreditScreen :
	public MenuScreen
{
protected:
	map<SDL_Texture*, SDL_Rect> textSet;
	TTF_Font* font = NULL;
	SDL_Color fontColor = { 0, 0, 0 };
	int startY = 300;
	void addTextToSet(string message, SDL_Renderer* ren);
	void drawText(SDL_Renderer& ren);
	void updatePositions();
	void resetTextSet();
public:
	CreditScreen(SDL_Renderer* ren);
	~CreditScreen();
	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
};

