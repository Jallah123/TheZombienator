#pragma once
#include "MenuScreen.h"
#include "TextureFactory.h"
#include "BackButton.h"
#include "Label.h"
#include "SwitchButton.h"
#include <functional>

using namespace std;
class SettingsScreen :
	public MenuScreen
{
protected:
	bool friendlyFire = false;
	bool sound = true;
	bool music = true;
	void initCompontents(SDL_Renderer &ren);
	SwitchButton* musicOnBtn = nullptr;
	SwitchButton* musicOffBtn = nullptr;

	SwitchButton* soundOnBtn = nullptr;
	SwitchButton* soundOffBtn = nullptr;

	SwitchButton* friendlyFireOnBtn = nullptr;
	SwitchButton* friendlyFireOffBtn = nullptr;

public:
	SettingsScreen(SDL_Renderer* ren);
	SettingsScreen();
	~SettingsScreen();
	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;

	bool getFiendlyFire() { return friendlyFire; };
	void setFriendlyFire(bool value) {
		if (friendlyFire != value) {
			friendlyFire = value;
			friendlyFireOnBtn->toggleEnabledStatus();
			friendlyFireOffBtn->toggleEnabledStatus();
		}
	};

	bool getSound() { return sound; };
	void setSound(bool value) {
		if (sound != value) {
			sound = value;
			soundOnBtn->toggleEnabledStatus();
			soundOffBtn->toggleEnabledStatus();
		}
	};

	bool getMusic() { return music; };
	void setMusic(bool value) {
		if (music != value) {
			music = value;
			musicOnBtn->toggleEnabledStatus();
			musicOffBtn->toggleEnabledStatus();
		}
	};

};

#pragma once
