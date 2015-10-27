#include "ScreenController.h"

void ScreenController::ChangeMenu(AbstractScreen* NewMenu)
{
	MenuStack.push(NewMenu);
}

void ScreenController::Back()
{
	if (MenuStack.size() > 1) {
		AbstractScreen* Menu = MenuStack.top();
		delete Menu;
		MenuStack.pop();
	}
}

int ScreenController::Size()
{
	return MenuStack.size();
}
