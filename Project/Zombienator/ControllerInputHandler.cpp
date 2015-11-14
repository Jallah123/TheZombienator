#include "ControllerInputHandler.h"

void ControllerInputHandler::SetButton(SDL_ControllerButtonEvent button, bool b)
{
	switch (button.button) {
	case SDL_CONTROLLER_BUTTON_A:
		inputContainer->SetKey(' ', b);
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
	case SDL_CONTROLLER_BUTTON_START:
		inputContainer->SetKey(SDLK_ESCAPE, b);
		break;
	}
}

void ControllerInputHandler::SetAxis(SDL_ControllerAxisEvent axisEvent, bool b)
{
	switch (axisEvent.axis) {
	case SDL_CONTROLLER_AXIS_TRIGGERLEFT:
		inputContainer->SetKey('[', (axisEvent.value > 0));
		break;
	case SDL_CONTROLLER_AXIS_TRIGGERRIGHT:
		inputContainer->SetKey(']', (axisEvent.value > 0));
		break;
	}
}