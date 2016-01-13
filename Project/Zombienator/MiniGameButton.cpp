#pragma once
#include "MiniGameButton.h"
#include "LoadingScreen.h"
#include "NumberUtility.h"

MiniGameButton::MiniGameButton(SDL_Renderer& ren, char* text, char* img_url, LoadingScreen* loadingScreen) : Button(ren, text, img_url), ls(loadingScreen)
{
	srcRect = { 0, 0, 32, 36 };
	destRect = { 623, 286, 32, 36 };
}

void MiniGameButton::ClickAction()
{
	ls->UpCounter();
}

MiniGameButton::MiniGameButton() {}
MiniGameButton::~MiniGameButton() {}

void MiniGameButton::ChangePos()
{
	int x = NumberUtility::RandomNumber(0, spawnRect.w);
	int y = NumberUtility::RandomNumber(0, spawnRect.h);
	destRect = { x, y, 32, 36 };
}