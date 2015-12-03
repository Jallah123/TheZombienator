#pragma once
#include "BackToMenuButton.h"
#include "ScreenController.h"
#include "ScreenFactory.h"
#include "StatsController.h"
#include "MapFactory.h"

BackToMenuButton::BackToMenuButton(SDL_Renderer& ren, char* text, char* img_url) : Button(ren, text, img_url) 
{
	srcRect = { 0, 0, 196, 18 };
	destRect = { 542, 500, 196, 18 };
}

void BackToMenuButton::ClickAction() 
{
	StatsController::GetInstance()->Reset();
	MapFactory::GetInstance()->EmptyQueue();
	SoundController::GetInstance().StopAllSounds();
	ScreenController::GetInstance().Back();
}

BackToMenuButton::BackToMenuButton() {}
BackToMenuButton::~BackToMenuButton() {}