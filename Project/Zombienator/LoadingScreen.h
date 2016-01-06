#pragma once
#include "MenuScreen.h"
#include "TextureFactory.h"
#include "Image.h"
#include "LabelEndScreen.h"
#include "MiniGameButton.h"

class LoadingScreen : public AbstractScreen
{
	public:
		~LoadingScreen();
		LoadingScreen(SDL_Renderer* ren);

		void SearchAds(SDL_Renderer* ren);
		void CreateAds(SDL_Renderer* ren, std::string url);
		void UpdateCounterLbl(SDL_Renderer& ren);
		void UpCounter();

		virtual void Update(float dt) override;
		virtual void Draw(SDL_Renderer& ren, float dt) override;
	private:
		SDL_Rect windowRect = { 0, 0, 1280, 640 };
		SDL_Rect imgRect = { 0, 0, 350, 150 };
		int counter = 0;
		int border = 2;

		Image* adver = nullptr;
		LabelEndScreen* counterLbl = nullptr;
		MiniGameButton* zombieBtn = nullptr;
		string placeholderUrl = "assets/images/ads-placeholder/placeholder.png";
};