#pragma once
#include "MenuScreen.h"
#include "TextureFactory.h"
#include "BackButton.h"
#include "Label.h"
#include "SwitchButton.h"
#include "Settings.h"
#include <functional>

using namespace std;
class SettingsScreen :
	public MenuScreen
{
protected:

	void initCompontents(SDL_Renderer &ren);

	SwitchButton* musicOnBtn = nullptr;
	SwitchButton* musicOffBtn = nullptr;

	SwitchButton* soundOnBtn = nullptr;
	SwitchButton* soundOffBtn = nullptr;

	SwitchButton* friendlyFireOnBtn = nullptr;
	SwitchButton* friendlyFireOffBtn = nullptr;

	Settings* Settings = &Settings::GetInstance();

public:
	SettingsScreen(SDL_Renderer* ren);
	SettingsScreen();
	~SettingsScreen();
	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;

	
	void setFriendlyFire(bool value) {
		if (Settings->getFiendlyFire() != value) {
			Settings->setFriendlyFire(value);
			friendlyFireOnBtn->toggleEnabledStatus();
			friendlyFireOffBtn->toggleEnabledStatus();
		}
	};

	void setSound(bool value) {
		if (Settings->getSound() != value) {
			Settings->setSound(value);
			soundOnBtn->toggleEnabledStatus();
			soundOffBtn->toggleEnabledStatus();
		}
	};

	void setMusic(bool value) {
		if (Settings->getMusic() != value) {
			Settings->setMusic(value);
			musicOnBtn->toggleEnabledStatus();
			musicOffBtn->toggleEnabledStatus();
		}
	};

};

