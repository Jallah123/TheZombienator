#pragma once
#include "BackButton.h"
#include "ScreenController.h"

BackButton::BackButton(SDL_Renderer& ren, char* text, char* img_url) 
	: Button(ren, text, img_url) {
	srcRect = { 170 , 0, 110, 105 };
	destRect = { 10, 10, 110, 105 };
}


void BackButton::ClickAction() {
	ScreenController::GetInstance().Back();
}

BackButton::BackButton()
{
}

BackButton::~BackButton()
{
}
