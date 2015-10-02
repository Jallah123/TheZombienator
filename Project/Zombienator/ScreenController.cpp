#include "ScreenController.h"

void ScreenController::ChangeMenu(MenuScreen NewMenu)
{
	MenuStack.push(NewMenu);
}

void ScreenController::Back()
{
	MenuStack.pop();
}

int ScreenController::Size()
{
	return MenuStack.size();
}
