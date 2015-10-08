#include "ControllerInputHandler.h"

void ControllerInputHandler::SetButton(SDL_ControllerButtonEvent button, bool b)
{
	switch (button.button) {
	case SDL_CONTROLLER_BUTTON_X:
		inputContainer->SetKey('x', b);
		break;
	case SDL_CONTROLLER_BUTTON_Y:
		inputContainer->SetKey('y', b);
		break;
	}
}
