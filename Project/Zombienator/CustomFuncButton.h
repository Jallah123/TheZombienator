#pragma once
#include "Button.h"
#include "AbstractScreen.h"
#include <functional>

class SettingsScreen;

class CustomFuncButton
	: public Button
{
protected:
	void updateLayout();
	AbstractScreen* parentScreen = nullptr;
	std::function<void()> updateParent;

public:
	CustomFuncButton();
	CustomFuncButton(SDL_Renderer& ren, char* text, char* img_url, int posX, int posY, AbstractScreen &_parentScreen);
	~CustomFuncButton();
	virtual void ClickAction() override;
	void setUpdateFunction(std::function<void()> func);
};
