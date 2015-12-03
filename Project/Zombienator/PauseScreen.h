#pragma once
#include "MenuScreen.h"
#include "SettingsScreen.h"
#include "Label.h"
#include "CustomFuncButton.h"
#include "TextureFactory.h"
#include <SDL_ttf.h>
#include <set>
#include <map>
#include <list>
#include <iostream>


using namespace std;
class PauseScreen :
	public MenuScreen
{
private:



public:
	void Resume();
	void Settings();
	void Quit();

	PauseScreen(SDL_Renderer* ren);
	~PauseScreen();
	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
};

