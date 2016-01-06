#pragma once
#include "LoadingScreen.h"
#include "ContinueButton.h"
#include "DirectoryUtils.h"
#include "TextureFactory.h"
#include "LabelEndScreen.h"
#include "Button.h"

LoadingScreen::~LoadingScreen() {}
LoadingScreen::LoadingScreen(SDL_Renderer* ren) : AbstractScreen(ren)
{
	ChangeBackground(ren, "assets/images/bg/loading_bg.png");
	
	// Buttons
	ContinueButton* btnBack = new ContinueButton(*ren, "", "assets/images/btn/btn_continue.png");
	AddUIComponent(btnBack);

	// Mini Game Counter
	counterLbl = new LabelEndScreen(*ren, "Counter: " + std::to_string(counter), 100, 200);
	AddUIComponent(counterLbl);

	// Zombie Button
	zombieBtn = new MiniGameButton(*ren, "", "assets/images/mini-game/zombie.png", this);
	AddUIComponent(zombieBtn);

	// Search/Create Ads
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
	AddUIComponent(adver);
}

void LoadingScreen::UpCounter()
{
	counter++;
	zombieBtn->ChangePos();
	counterLbl->ChangeText("Counter: " + std::to_string(counter));
}

void LoadingScreen::Update(float dt) {}
void LoadingScreen::Draw(SDL_Renderer & ren, float dt)
{
	AbstractScreen::Draw(ren, dt);
}