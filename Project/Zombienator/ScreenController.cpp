#include "ScreenController.h"
#include "MenuScreen.h"

void ScreenController::ChangeMenu(AbstractScreen* NewMenu)
{
	MenuStack.push(NewMenu);
}

void ScreenController::Back()
{
	if (MenuStack.size() > 1) {
		AbstractScreen* Menu = MenuStack.top();
		if (MenuScreen* screen = dynamic_cast<MenuScreen*>(Menu))
		{
			delete screen;
		}
		else {
			delete Menu;
		}
		MenuStack.pop();
	}
}

int ScreenController::Size()
{
	return MenuStack.size();
}
