#include "ScreenController.h"
#include "MenuScreen.h"

void ScreenController::ChangeScreen(AbstractScreen* screen)
{
	screenStack.push(screen);
}

void ScreenController::EmptyStack()
{
	screenStack.empty();
}

void ScreenController::Back()
{
	if (screenStack.size() > 1) {
		AbstractScreen* screen = screenStack.top();
		delete screen;
		screenStack.pop();
		screenStack.top()->ReceiveFocus();
	}
}

int ScreenController::Size()
{
	return screenStack.size();
}
