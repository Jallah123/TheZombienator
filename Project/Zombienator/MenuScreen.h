#pragma once
#include <vector>
#include "AbstractUIComponent.h"
#include "SDL.h"
#include "MusicController.h"
#include <algorithm>
#include "SDL_image.h"
#include "AbstractScreen.h"

class MenuScreen : public AbstractScreen
{
public:
	MenuScreen(SDL_Renderer* ren);
	void AddUIComponent(AbstractUIComponent* UIComponent);
	void SetBackgroundTexture(SDL_Texture& Texture) { BackgroundTexture = &Texture; }
	SDL_Texture* const GetBackgroundTexture() { return BackgroundTexture; }
	void ClickComponents(SDL_Point MousePosition);
	void Draw(SDL_Renderer& ren, float dt);
	~MenuScreen();
protected:
	SDL_Texture* BackgroundTexture;
	void ChangeBackground(SDL_Renderer* ren, std::string img_url);
};