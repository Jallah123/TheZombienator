#include "ControllerInputHandler.h"

void ControllerInputHandler::SetButton(SDL_ControllerButtonEvent button, bool b)
{
	switch (button.button) {
	case SDL_CONTROLLER_BUTTON_A:
		inputContainer->SetKey(' ', b);
		break;
	case SDL_CONTROLLER_BUTTON_Y:
		inputContainer->SetKey('y', b);
		break;
	case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
		inputContainer->SetKey('q', b);
		break;
	case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:
		inputContainer->SetKey('e', b);
		break;
	case SDL_CONTROLLER_BUTTON_DPAD_UP:
		inputContainer->SetKey('w', b);
		break;
	case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
		inputContainer->SetKey('s', b);
		break;
	case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
		inputContainer->SetKey('a', b);
		break;
	case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
		inputContainer->SetKey('d', b);
		break;
	}
}
