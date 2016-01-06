#pragma once
#include "LoadingScreen.h"
#include "ContinueButton.h"
#include "DirectoryUtils.h"
#include "TextureFactory.h"

LoadingScreen::~LoadingScreen() {}
LoadingScreen::LoadingScreen(SDL_Renderer* ren) : AbstractScreen(ren)
{
	ChangeBackground(ren, "assets/images/bg/loading_bg.png");
	
	// Buttons
	ContinueButton* btnBack = new ContinueButton(*ren, "", "assets/images/btn/btn_continue.png");
	AddUIComponent(btnBack);

	SearchAds(ren);
}

void LoadingScreen::SearchAds(SDL_Renderer* ren)
{
	int w, h;
	vector<std::string> images = DirectoryUtils::getFilesFromDirectory("images/ads-350x150/", "png", true);
	
	if (images.size() != 0) {
		std::string url = images.at(rand() % images.size());
		SDL_Texture* test = TextureFactory::CreateTexture(url);
		SDL_QueryTexture(test, NULL, NULL, &w, &h);

		if (w == imgRect.w && h == imgRect.h) 
		{
			CreateAds(ren, url);
		} 
		else 
		{
			CreateAds(ren, placeholderUrl);
		}
	}
	else 
	{
		CreateAds(ren, placeholderUrl);
	}
}

void LoadingScreen::CreateAds(SDL_Renderer* ren, std::string url)
{
	adver = new Image(*ren, url);
	adver->SetSize(imgRect.w, imgRect.h);
	adver->SetSourceLocation(imgRect.x, imgRect.y);
	adver->SetDestLocation((windowRect.w - imgRect.w) - border, border);
}

void LoadingScreen::Update(float dt) {}
void LoadingScreen::Draw(SDL_Renderer & ren, float dt)
{
	AbstractScreen::Draw(ren, dt);
	adver->Draw(ren);
}