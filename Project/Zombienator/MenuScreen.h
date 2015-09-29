#pragma once
#include <vector>
#include "AbstractUIComponent.h"
#include "SDL.h"
#include "MusicController.h"
class MenuScreen
{
public:
	void AddUIComponent(AbstractUIComponent UIComponent);
	virtual int GetSomething() = 0;
private:

protected:
	std::vector<AbstractUIComponent> UIComponents;
	SDL_Texture* BackgroundTexture;
	MusicController *MusicController = & MusicController::GetInstance();
};