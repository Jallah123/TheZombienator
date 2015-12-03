#pragma once
#include "Button.h"
#include "AbstractScreen.h"
#include "TextureFactory.h"
#include <map>
#include <functional>

class SettingsScreen;

class VolumeButton
	: public Button
{
protected:
	void updateLayout();
	int value;
	AbstractScreen* parentScreen = nullptr;
	std::function<void(const int&)> updateParent;

public:
	VolumeButton();
	VolumeButton(SDL_Renderer& ren, char* text, char* img_url, int posX, int posY, int value, AbstractScreen &_parentScreen);
	~VolumeButton();
	virtual void ClickAction() override;
	void setUpdateFunction(std::function<void(const int&)> func);
};
