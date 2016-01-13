#pragma once
#include "MenuScreen.h"
#include "MapFactory.h"
#include "SettingsScreen.h"
#include "HomeScreen.h"
#include "Label.h"
#include "CustomFuncButton.h"


using namespace std;
class PauseScreen :
	public MenuScreen
{
private:



public:
	void Resume();
	void Help();
	void Settings();
	void Quit();

	PauseScreen(SDL_Renderer* ren);
	~PauseScreen();
	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
};

