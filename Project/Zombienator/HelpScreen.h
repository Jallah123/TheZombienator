#pragma once
#include "MenuScreen.h"
class BackButton;

class HelpScreen :
	public MenuScreen
{
private:
	BackButton* backButton = nullptr;
public:
	HelpScreen(SDL_Renderer* ren);
	~HelpScreen();

	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
};

