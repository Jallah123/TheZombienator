#include "AbstractScreen.h"


AbstractScreen::AbstractScreen(SDL_Renderer* ren)
{
}


AbstractScreen::~AbstractScreen()
{
	for each (auto component in UIComponents)
	{
		delete component;
	}
	UIComponents.clear();
}

void AbstractScreen::AddUIComponent(AbstractUIComponent* UIComponent)
{
	UIComponents.push_back(UIComponent);
}

void AbstractScreen::ClickComponents(SDL_Point MousePosition)
{
	for (const auto& i : UIComponents)
		i->OnClick(MousePosition);
}
