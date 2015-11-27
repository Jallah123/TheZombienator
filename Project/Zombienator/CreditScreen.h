#pragma once
#include "MenuScreen.h"
#include "TextureFactory.h"
#include "BackButton.h"
#include <SDL_ttf.h>
#include <set>
#include <map>
#include <list>
#include <iostream>


using namespace std;
class CreditScreen :
	public MenuScreen
{
protected:
	std::list<std::pair<SDL_Texture*, SDL_Rect>> textList = {};
	TTF_Font* font = nullptr;
	SDL_Color fontColor = { 0, 0, 0 };
	int startY = 300;
	void addTextToSet(string message);
	void drawText(SDL_Renderer& ren);
	void updatePositions();
	void resetTextSet();
public:
	CreditScreen(SDL_Renderer* ren);
	~CreditScreen();
	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
};

