#pragma once
#include <vector>
#include "AbstractUIComponent.h"
#include "SDL.h"
#include "MusicController.h"
#include <algorithm>

class MenuScreen
{
public:
	MenuScreen(SDL_Renderer& ren);
	void AddUIComponent(AbstractUIComponent* UIComponent);
	void SetBackgroundTexture(SDL_Texture& Texture) { BackgroundTexture = &Texture; }
	SDL_Texture* const GetBackgroundTexture() { return BackgroundTexture; }
	void ClickComponents(SDL_Point MousePosition);
	void Draw(SDL_Renderer& ren);
private:
	SDL_Texture* BackgroundTexture;
protected:
	std::vector<AbstractUIComponent*> UIComponents;
	MusicController *MusicController = & MusicController::GetInstance();
};