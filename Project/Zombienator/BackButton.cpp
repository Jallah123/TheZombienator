#pragma once
#include "BackButton.h"
#include "ScreenController.h"

BackButton::BackButton(SDL_Renderer& ren, char* text, char* img_url) 
	: Button(ren, text, img_url) {
	srcRect = { 87 , 160, 82, 81 };
	destRect = { 10, 10, 82, 82 };
}

void BackButton::setUpdateParentFunction(std::function<void()> func) {
	this->updateParent = func;
}


void BackButton::ClickAction() {
	if (updateParent != nullptr) {
		updateParent();
	}
	ScreenController::GetInstance().Back();
}

BackButton::BackButton()
{
}

BackButton::~BackButton()
{
}
