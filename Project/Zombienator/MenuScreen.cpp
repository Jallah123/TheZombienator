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

void MenuScreen::HandleKeyboardEvents(SDL_Renderer& ren, float dt)
{
	if (buttons.empty())
	{
		for (auto component : UIComponents)
		{
			if (Button* b = dynamic_cast<Button*>(component))
			{
				buttons.push_back(b);
			}
		}
	}
	lastHandled -= dt;
	if (!previous) previous = inputContainer->GetKeyState(SDLK_w) || inputContainer->GetKeyState(SDLK_a);
	if (!next) next = inputContainer->GetKeyState(SDLK_s) || inputContainer->GetKeyState(SDLK_d);
	if (!enter) enter = inputContainer->GetKeyState(SDLK_SPACE) || inputContainer->GetKeyState(SDLK_RETURN);
	if (lastHandled <= 0)
	{
		lastHandled = 50;
		if (enter)
		{
			buttons.at(selectedComponent)->ClickAction();
		}
		else if (next)
		{
			selectedComponent++;
			if (selectedComponent >= buttons.size())
			{
				selectedComponent = 0;
			}
		}
		else if (previous)
		{
			selectedComponent--;
			if (selectedComponent < 0)
			{
				selectedComponent = buttons.size() - 1;
			}
		}
		auto component = buttons.at(selectedComponent);

		selectedRect = { component->GetDestRect().x , component->GetDestRect().y + component->GetDestRect().h, component->GetDestRect().w, 5 };
		enter = false;
		next = false;
		previous = false;
	}

	SDL_SetRenderDrawColor(&ren, 0, 255, 0, 255);
	SDL_RenderFillRect(&ren, &selectedRect);
}