#include "KeyboardInputHandler.h"

void KeyboardInputHandler::SetKey(SDL_Keycode button, bool b)
{
	switch (button) {
	case SDLK_DOWN:
	case SDLK_s:
		inputContainer->SetKey('s', b);
		break;
	case SDLK_UP:
	case SDLK_w:
		inputContainer->SetKey('w', b);
		break;
	case SDLK_LEFT:
	case SDLK_a:
		inputContainer->SetKey('a', b);
		break;
	case SDLK_RIGHT:
	case SDLK_d:
		inputContainer->SetKey('d', b);
		break;
	case SDLK_SPACE:
		inputContainer->SetKey(' ', b);
		break;
	case SDLK_e:
		inputContainer->SetKey('e', b);
		break;
	case SDLK_q:
		inputContainer->SetKey('q', b);
		break;
	case SDLK_ESCAPE:
		inputContainer->SetKey(SDLK_ESCAPE, b);
		break;
	}
}
