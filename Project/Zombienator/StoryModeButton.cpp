#pragma once
#include "StoryModeButton.h"
#include "SoundController.h"
#include "ScreenController.h"
#include "GameScreen.h"
#include "ScreenFactory.h"
#include "MapFactory.h"
#include "SelectionScreen.h"

StoryModeButton::StoryModeButton() : Button()
{
}

StoryModeButton::StoryModeButton(SDL_Renderer& ren, char* text, char* img_url)
	: Button(ren, text, img_url) {
	SetSourceLocation(0, 238);
	SetSize(239, 97);
	SetDestLocation(515, 220);
	buttonText = TextureFactory::GenerateText(string(text), 24, destRect.x + (destRect.w / 2), destRect.y + (destRect.h / 2), FontEnum::CARTOON, { 248 ,248 ,255 });
}

void StoryModeButton::ClickAction()
{
	MapFactory::GetInstance()->StoryMode();
	StatsController::GetInstance()->Reset();
	SelectionScreen* selectionScreen = static_cast<SelectionScreen*>(ScreenFactory::Create(ScreenEnum::SELECTIONSCREEN));
	selectionScreen->setAmountOfPlayers(1);
	ScreenController::GetInstance().ChangeScreen(selectionScreen);
}

StoryModeButton::~StoryModeButton()
{
}
