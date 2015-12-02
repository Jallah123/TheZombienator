#pragma once
#include "AbstractScreen.h"

class GameOverScreen : public AbstractScreen
{
	public:
		GameOverScreen(SDL_Renderer* ren);
		~GameOverScreen();

		virtual void Update(float dt) override;
		virtual void Draw(SDL_Renderer& ren, float dt) override;
		void DrawStats(SDL_Renderer& ren);
};

