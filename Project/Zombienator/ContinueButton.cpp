#pragma once
#include "ContinueButton.h"
#include "ScreenController.h"
#include "ScreenFactory.h"

ContinueButton::ContinueButton(SDL_Renderer& ren, char* text, char* img_url) : Button(ren, text, img_url)
{
	srcRect = { 0, 0, 196, 18 };
	destRect = { 542, 500, 196, 18 };
}

void ContinueButton::ClickAction()
{
	ScreenController::GetInstance().Back();
}

ContinueButton::ContinueButton() {}
ContinueButton::~ContinueButton() {}