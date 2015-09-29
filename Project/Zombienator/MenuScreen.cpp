#include "MenuScreen.h"

void MenuScreen::AddUIComponent(AbstractUIComponent& UIComponent)
{
	UIComponents.push_back(&UIComponent);
}

void MenuScreen::ClickComponents(SDL_Point MousePosition)
{
	//for each (AbstractUIComponent Component in UIComponents)
	//{
	//	Component.OnClick(MousePosition);
	//}
	std::vector<AbstractUIComponent*>::iterator it;
	for (it = UIComponents.begin(); it != UIComponents.end(); it++) (*it)->OnClick(MousePosition);
}