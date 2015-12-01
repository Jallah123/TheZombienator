#pragma once
#include "AbstractUIComponent.h"
#include "SoundController.h"
#include <vector>
#include <SDL_render.h>
#include <SDL_image.h>


class AbstractScreen
{
protected:
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* backgroundTexture = nullptr;
	std::vector<AbstractUIComponent*> UIComponents;
	SoundController* SoundController = &SoundController::GetInstance();

	void ChangeBackground(SDL_Renderer* ren, char* img_url);

public:
	AbstractScreen();
	AbstractScreen(SDL_Renderer* ren);
	virtual ~AbstractScreen();

	virtual void Update(float dt) = 0;
	virtual void Draw(SDL_Renderer& ren, float dt) = 0;
	virtual void AddUIComponent(AbstractUIComponent* UIComponent);
	virtual void ClickComponents(SDL_Point MousePosition);
	virtual void ReceiveFocus() {};
protected:
	void SetBackgroundTexture(SDL_Texture& Texture) { backgroundTexture = &Texture; }
	SDL_Texture* const GetBackgroundTexture() { return backgroundTexture; }
};

