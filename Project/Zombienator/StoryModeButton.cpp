#pragma once
#include "MusicController.h"
#include "StoryModeButton.h"
#include "ScreenController.h"
#include "GameScreen.h"

StoryModeButton::StoryModeButton() : Button()
{
}

StoryModeButton::StoryModeButton(SDL_Renderer& ren, char* text, char* img_url)
	: Button(ren, text, img_url) {
	srcRect = { 0, 340, 238, 102 };
	destRect = { 515, 220, 238, 102 };
}

StoryModeButton::~StoryModeButton()
{
}

void StoryModeButton::ClickAction()
{
	MusicController::GetInstance().Stop();
	ScreenController::GetInstance().ChangeScreen(new GameScreen{ renderer, "assets/maps/map-1280x640.json" });
}

