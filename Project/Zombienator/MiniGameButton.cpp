#pragma once
#include "MiniGameButton.h"
#include "LoadingScreen.h"

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
	int x = rand() % spawnRect.w;
	int y = rand() % spawnRect.h;
	destRect = { x, y, 32, 36 };
}