#pragma once
#include "Button.h"
#include "AbstractScreen.h"
#include "TextureFactory.h"
#include <map>
#include <functional>

class SettingsScreen;

class SwitchButton
	: public Button
{
protected:
	void updateLayout();
	SDL_Rect disableRect = { 0 , 239, 130, 95 };
	SDL_Rect enableRect = { 137 , 239, 130, 95 };
	bool value = false;
	bool enableStatus = false;
	AbstractScreen* parentScreen = nullptr;
	std::function<void(const bool&)> updateParent;
	
public:
	SwitchButton();
	SwitchButton(SDL_Renderer& ren, char* text, char* img_url, int posX, int posY, bool value, bool _enableStatus, AbstractScreen &_parentScreen);
	~SwitchButton();
	void toggleEnabledStatus() {updateLayout(); };
	virtual void ClickAction() override;
	void setUpdateFunction(std::function<void(const bool&)> func);
};
