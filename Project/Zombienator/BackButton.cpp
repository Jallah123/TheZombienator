#pragma once
#include "BackButton.h"
#include "ScreenController.h"

BackButton::BackButton(SDL_Renderer& ren, char* text, char* img_url) 
	: Button(ren, text, img_url) {
	
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
