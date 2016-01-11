#pragma once
#include "Button.h"
#include "GameSpeed.cpp"
#include "AbstractScreen.h"
#include "Settings.h"
#include <functional>

class SettingsScreen;

class SwitchButtonGameSpeed
	: public Button
{
private:
	void updateLayout();
	SDL_Rect disableRect = { 0 , 239, 130, 95 };
	SDL_Rect enableRect = { 137 , 239, 130, 95 };
	GameSpeed value;
	AbstractScreen* parentScreen = nullptr;
	std::function<void(const GameSpeed&)> updateParent;
	Settings* Settings = &Settings::GetInstance();
public:
	SwitchButtonGameSpeed();
	SwitchButtonGameSpeed(SDL_Renderer& ren, char* text, char* img_url, int posX, int posY, GameSpeed value,  AbstractScreen &_parentScreen);
	~SwitchButtonGameSpeed();
	void toggleEnabledStatus() { updateLayout(); };
	virtual void ClickAction() override;
	void setUpdateFunction(std::function<void(const GameSpeed&)> func);
};
