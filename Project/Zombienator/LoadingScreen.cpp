#pragma once
#include "LoadingScreen.h"

LoadingScreen::LoadingScreen(SDL_Renderer* ren) : AbstractScreen(ren)
{
	// Background
	BackgroundTexture = TextureFactory::GenerateTextureFromImgUrl("assets/images/loading_bg.png");

}

LoadingScreen::~LoadingScreen()
{
	SDL_DestroyTexture(BackgroundTexture);
	BackgroundTexture = NULL;
}


void LoadingScreen::Update(float dt)
{
}

void LoadingScreen::Draw(SDL_Renderer & ren, float dt)
{
	SDL_RenderCopy(&ren, BackgroundTexture, 0, 0);
	for (const auto& i : UIComponents)
		i->Draw(ren);
}
