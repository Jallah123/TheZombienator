#include "ScreenController.h"
#include "MenuScreen.h"

void ScreenController::ChangeMenu(AbstractScreen* screen)
{
	screenStack.push(screen);
}

void ScreenController::Back()
{
	if (screenStack.size() > 1) {
		AbstractScreen* screen = screenStack.top();
		delete screen;
		screenStack.pop();
	}
}

int ScreenController::Size()
{
	return screenStack.size();
}
