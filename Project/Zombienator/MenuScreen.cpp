#include "MenuScreen.h"
#include "iostream"

MenuScreen::MenuScreen(SDL_Renderer& ren)
{
	SDL_Surface *s = SDL_LoadBMP("assets\\images\\default_background.bmp");
	BackgroundTexture = SDL_CreateTextureFromSurface(&ren, s);
}

void MenuScreen::AddUIComponent(AbstractUIComponent& UIComponent)
{
	UIComponents.push_back(&UIComponent);
}

void MenuScreen::ClickComponents(SDL_Point MousePosition)
{
	std::vector<AbstractUIComponent*>::iterator it;
	for (it = UIComponents.begin(); it != UIComponents.end(); it++) (*it)->OnClick(MousePosition);
}

void MenuScreen::Draw(SDL_Renderer& ren)
{
	SDL_RenderCopy(&ren, BackgroundTexture, 0, 0);
	std::vector<AbstractUIComponent*>::iterator it;
	for (it = UIComponents.begin(); it != UIComponents.end(); it++) (*it)->Draw(ren);
}