#pragma once
#include "MenuScreen.h"
#include "AbstractUIComponent.h"

MenuScreen::MenuScreen() : AbstractScreen()
{
}

MenuScreen::MenuScreen(SDL_Renderer* ren) : AbstractScreen(ren)
{
	inputContainer = KeyboardInputHandler::GetInstance().inputContainer;
	ChangeBackground(ren, "assets/images/menu_bg.png");
}

MenuScreen::~MenuScreen()
{

}

void MenuScreen::HandleKeyboardEvents(SDL_Renderer& ren, float dt)
{
	lastHandled -= dt;
	if(!previous) previous = inputContainer->GetKeyState(SDLK_a) || inputContainer->GetKeyState(SDLK_w);
	if (!next) next = inputContainer->GetKeyState(SDLK_d) || inputContainer->GetKeyState(SDLK_s);
	if (!enter) enter = inputContainer->GetKeyState(SDLK_SPACE);
	if (lastHandled < 0)
	{
		lastHandled = 50;
		if (enter)
		{
			UIComponents.at(selectedComponent)->ClickAction();
			return;
		}
		if (next)
		{
			selectedComponent++;
			if (selectedComponent >= UIComponents.size())
			{
				selectedComponent = 0;
			}
		}
		else if (previous)
		{
			selectedComponent--;
			if (selectedComponent < 0)
			{
				selectedComponent = UIComponents.size() - 1;
			}
		}
		auto component = UIComponents.at(selectedComponent);

		selectedRect = { component->GetDestRect().x , component->GetDestRect().y + component->GetDestRect().h, component->GetDestRect().w, 5 };
		enter = false;
		next = false;
		previous = false;
	}

	SDL_SetRenderDrawColor(&ren, 0, 255, 0, 255);
	SDL_RenderFillRect(&ren, &selectedRect);
}