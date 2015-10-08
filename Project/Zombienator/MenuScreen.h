#pragma once
#include <vector>
#include "AbstractUIComponent.h"
#include "SDL.h"
#include "MusicController.h"
#include <algorithm>
#include "SDL_image.h"

class MenuScreen
{
public:
	MenuScreen(SDL_Renderer* ren);
	void AddUIComponent(AbstractUIComponent* UIComponent);
	void SetBackgroundTexture(SDL_Texture& Texture) { BackgroundTexture = &Texture; }
	SDL_Texture* const GetBackgroundTexture() { return BackgroundTexture; }
	void ClickComponents(SDL_Point MousePosition);
	void Draw(SDL_Renderer& ren);
private:
protected:
	std::vector<AbstractUIComponent*> UIComponents;
	SDL_Texture* BackgroundTexture;
	MusicController *MusicController = &MusicController::GetInstance();
	void ChangeBackground(SDL_Renderer* ren, std::string img_url);
};