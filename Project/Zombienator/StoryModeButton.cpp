#pragma once
#include "StoryModeButton.h"
#include "SoundController.h"
#include "ScreenController.h"
#include "GameScreen.h"
#include "ScreenFactory.h"
#include "MapFactory.h"

StoryModeButton::StoryModeButton() : Button()
{
}

StoryModeButton::StoryModeButton(SDL_Renderer& ren, char* text, char* img_url)
	: Button(ren, text, img_url) {
	srcRect = { 0, 340, 238, 102 };
	destRect = { 515, 220, 238, 102 };
}

void StoryModeButton::ClickAction()
{
	ScreenController::GetInstance().ChangeScreen(ScreenFactory::Create(ScreenEnum::SELECTIONSCREEN, "assets/maps/landscape-1280x640.json"));
	SoundController::GetInstance().StopAllSounds();
	MapFactory::GetInstance()->StoryMode();
	StatsController::GetInstance()->StartTime();
}

StoryModeButton::~StoryModeButton()
{
}
