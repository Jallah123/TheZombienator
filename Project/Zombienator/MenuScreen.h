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
	void SetBackgroundTexture(SDL_Texture& Texture) { BackgroundTexture = &Texture; }
	SDL_Texture* const GetBackgroundTexture() { return BackgroundTexture; }
private:
	SDL_Texture* BackgroundTexture;
protected:
	std::vector<AbstractUIComponent> UIComponents;
	MusicController *MusicController = & MusicController::GetInstance();
};