#pragma once
#include "StatsScreen.h"

class GameOverScreen : public StatsScreen
{
	public:
		GameOverScreen(SDL_Renderer* ren);
		~GameOverScreen();

		virtual void Update(float dt) override;
		virtual void Draw(SDL_Renderer& ren, float dt) override;
};

