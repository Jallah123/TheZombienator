#pragma once
#include <vector>
#include "AbstractUIComponent.h"
#include "SDL.h"
#include "MusicController.h"
#include <algorithm>

class MenuScreen
{
public:
	void AddUIComponent(AbstractUIComponent& UIComponent);
	void SetBackgroundTexture(SDL_Texture& Texture) { BackgroundTexture = &Texture; }
	SDL_Texture* const GetBackgroundTexture() { return BackgroundTexture; }
	void ClickComponents(SDL_Point MousePosition);
private:
	SDL_Texture* BackgroundTexture;
protected:
	std::vector<AbstractUIComponent*> UIComponents;
	MusicController *MusicController = & MusicController::GetInstance();
};