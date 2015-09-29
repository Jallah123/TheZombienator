#include "Button.h"
#include <iostream>

void Button::Draw(SDL_Renderer& ren) {
	// NOPE
	// SDL_RenderFillRect(&ren, this);
	std::cout << "draw" << std::endl;
}

void Button::ClickAction() {
	std::cout << "Clicked" << std::endl;
}


Button::~Button()
{
}
