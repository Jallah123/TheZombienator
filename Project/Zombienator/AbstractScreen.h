#pragma once
#include "AbstractUIComponent.h"
#include "MusicController.h"
#include <vector>
#include <SDL_render.h>


class AbstractScreen
{
public:
	AbstractScreen();
	AbstractScreen(SDL_Renderer* ren);
	virtual ~AbstractScreen();

	virtual void Update(float dt) = 0;
	virtual void Draw(SDL_Renderer& ren, float dt) = 0;
	virtual void AddUIComponent(AbstractUIComponent* UIComponent);
	virtual void ClickComponents(SDL_Point MousePosition);
	
protected:
	std::vector<AbstractUIComponent*> UIComponents;
	MusicController* musicController = &MusicController::GetInstance();
};

