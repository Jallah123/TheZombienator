#pragma once
#include "AbstractButton.h"
#include "MusicController.h"
#include "SDL.h"
#include <vector>


class AbstractScreen
{
public:
	AbstractScreen(SDL_Renderer* ren);
	virtual void Draw(SDL_Renderer& ren, float dt) {};
	virtual void ClickComponents(SDL_Point MousePosition) {};
	~AbstractScreen();
protected:
	std::vector<AbstractUIComponent*> UIComponents;
private:
	MusicController *MusicController = &MusicController::GetInstance();
};

