#pragma once
#include "MenuScreen.h"
#include "Label.h"
#include "Settings.h"
#include "SwitchButton.h"
#include "VolumeButton.h"
#include "SwitchButtonGameDifficulty.h"
#include "SwitchButtonGameSpeed.h"

class SettingsScreen :
	public MenuScreen
{
protected:

	void initCompontents(SDL_Renderer &ren);

	Label* currentVolumeLabel;

	SwitchButton* musicOnBtn = nullptr;
	SwitchButton* musicOffBtn = nullptr;

	SwitchButton* soundOnBtn = nullptr;
	SwitchButton* soundOffBtn = nullptr;

	SwitchButton* friendlyFireOnBtn = nullptr;
	SwitchButton* friendlyFireOffBtn = nullptr;

	SwitchButton* fpsOnBtn = nullptr;
	SwitchButton* fpsOffBtn = nullptr;

	VolumeButton* volumeIncBtn = nullptr;
	VolumeButton* volumeDecBtn = nullptr;

	std::list<SwitchButtonGameSpeed*> gameSpeedBtns = {};

	std::list<SwitchButtonGameDifficulty*> gameDifficultyBtns = {};

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
			SoundController->MuteUnmuteSound();
			soundOnBtn->toggleEnabledStatus();
			soundOffBtn->toggleEnabledStatus();
		}
	};

	void setMusic(bool value) {
		if (Settings->getMusic() != value) {
			Settings->setMusic(value);
			SoundController->MuteUnmuteMusic();
			musicOnBtn->toggleEnabledStatus();
			musicOffBtn->toggleEnabledStatus();
		}
	};

	void setFPS(bool value) {
		if (Settings->getShowFps() != value) {
			Settings->setShowFps(value);
			fpsOnBtn->toggleEnabledStatus();
			fpsOffBtn->toggleEnabledStatus();
		}
	};

	void setGameSpeed(GameSpeed value) {
		if (Settings->getGameSpeed() != value) {
			Settings->setGameSpeed(value);
			for (const auto& i : gameSpeedBtns)
				i->toggleEnabledStatus();
		}
	};

	void setGameDifficulty(GameDifficulty value) {
		if (Settings->getGameDifficulty() != value) {
			Settings->setGameDifficulty(value);
			for (const auto& i : gameDifficultyBtns)
				i->toggleEnabledStatus();
		}
	};

	void increaseVolume(int value) {
		if (SoundController->GetVolume() < 100) {
			SoundController->SetVolume(SoundController->GetVolume() + value);
			currentVolumeLabel->updateText(SoundController->GetVolume());
		}
		
	};

	void decreaseVolume(int value) {
		if (SoundController->GetVolume() > 0) {
			SoundController->SetVolume(SoundController->GetVolume() - value);
			currentVolumeLabel->updateText(SoundController->GetVolume());
		}
	};

	void saveSettings() {
		Settings->Save();
	}

};

