#pragma once
#include "MenuScreen.h"
#include "HighScores.h"
#include "ioController.h"

class HighScores;
class StatsScreen 
	: public AbstractScreen
{
private:
	void AddHighScores(SDL_Renderer* ren);
	HighScores* highScores = nullptr;
	ioController* ioC = &ioController::GetInstance();
public:
	StatsScreen(SDL_Renderer* ren);
	~StatsScreen();

	virtual void Update(float dt) = 0;
	virtual void Draw(SDL_Renderer& ren, float dt) = 0;

	void AddStats(SDL_Renderer* ren);
};