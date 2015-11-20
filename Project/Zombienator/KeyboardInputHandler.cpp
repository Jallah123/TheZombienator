#include "KeyboardInputHandler.h"

void KeyboardInputHandler::SetKey(SDL_Keycode button, bool b)
{
	inputContainer->SetKey(button, b);
}
