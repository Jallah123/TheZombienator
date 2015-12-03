
#pragma once
#include "Button.h"
#include "GameSpeed.cpp"
#include "AbstractScreen.h"
#include "Settings.h"
#include "TextureFactory.h"
#include <map>
#include <functional>

class SettingsScreen;

class SwitchButtonGameDifficulty
	: public Button
{
private:
	void updateLayout();
	SDL_Rect disableRect = { 0 , 239, 130, 95 };
	SDL_Rect enableRect = { 137 , 239, 130, 95 };
	GameDifficulty value;
	AbstractScreen* parentScreen = nullptr;
	std::function<void(const GameDifficulty&)> updateParent;
	Settings* Settings = &Settings::GetInstance();
public:
	SwitchButtonGameDifficulty();
	SwitchButtonGameDifficulty(SDL_Renderer& ren, char* text, char* img_url, int posX, int posY, GameDifficulty value, AbstractScreen &_parentScreen);
	~SwitchButtonGameDifficulty();
	void toggleEnabledStatus() { updateLayout(); };
	virtual void ClickAction() override;
	void setUpdateFunction(std::function<void(const GameDifficulty&)> func);
};
