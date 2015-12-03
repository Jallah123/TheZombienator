#pragma once
#include "SettingsButton.h"
#include "ScreenController.h"
#include "SettingsScreen.h"
#include "ScreenFactory.h"

SettingsButton::SettingsButton() : Button()
{
}
SettingsButton::SettingsButton(SDL_Renderer& ren, char* text, char* img_url) : Button(ren, text, img_url) {
	srcRect = { 286 , 0, 82, 81 };
	destRect = { 1189, 12, 82, 81 };
}

SettingsButton::~SettingsButton()
{
}

void SettingsButton::ClickAction() 
{
	ScreenController::GetInstance().ChangeScreen(ScreenFactory::Create(ScreenEnum::SETTINGSSCREEN));
}


