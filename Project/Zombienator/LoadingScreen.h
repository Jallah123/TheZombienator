#pragma once
#include "Image.h"
#include "MenuScreen.h"
#include "TextureFactory.h"

class LoadingScreen : public AbstractScreen
{
	public:
		~LoadingScreen();
		LoadingScreen(SDL_Renderer* ren);

		void SearchAds(SDL_Renderer* ren);
		void CreateAds(SDL_Renderer* ren, std::string url);

		virtual void Update(float dt) override;
		virtual void Draw(SDL_Renderer& ren, float dt) override;
	private:
		SDL_Rect windowRect = { 0, 0, 1280, 640 };
		SDL_Rect imgRect = { 0, 0, 350, 150 };
		int border = 2;

		Image* adver = nullptr;
		string placeholderUrl = "assets/images/ads-placeholder/placeholder.png";
};