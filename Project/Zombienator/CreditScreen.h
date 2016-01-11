#pragma once
#include "MenuScreen.h"
#include <set>
#include <list>

using std::list;
using std::pair;

class CreditScreen :
	public MenuScreen
{
protected:
	list<pair<SDL_Texture*, SDL_Rect>> textList = {};
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

