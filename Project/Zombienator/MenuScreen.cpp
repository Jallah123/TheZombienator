#include "MenuScreen.h"

void MenuScreen::AddUIComponent(AbstractUIComponent& UIComponent)
{
	UIComponents.push_back(&UIComponent);
}

void MenuScreen::ClickComponents(SDL_Point MousePosition)
{
	for (AbstractUIComponent &Component : UIComponents*) {
		Component.OnClick();
	}
		
	
}

void MenuScreen::Click(AbstractUIComponent& UIComponent) {
	UIComponent.OnClick();
}