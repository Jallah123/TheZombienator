#pragma once
#include "GameSpeed.cpp"
#include "ioController.h"
#include "GameDifficulty.cpp"

#include <cereal/types/map.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/complex.hpp>

// for doing the actual serialization
#include <cereal/archives/json.hpp>
#include <iostream>
#include <fstream>

class Settings
{
private:
	Settings();
	Settings(Settings const&) = delete;
	~Settings();


	bool friendlyFire = false;
	bool sound = true;
	bool music = true;
	bool showFps = true;
	int defaultVolume = 25;
	int musicVolume = 25;
	int soundVolume = 25;
	bool godmode = false;
	bool infiniteAmmo = false;

	GameSpeed gameSpeed = GameSpeed::NORMAL;
	GameDifficulty gameDifficulty = GameDifficulty::MEDIUM;

	
	friend class cereal::access;
	template <class Archive>
	void serialize(Archive & ar)
	{
		ar(CEREAL_NVP(friendlyFire), CEREAL_NVP(sound), CEREAL_NVP(music), CEREAL_NVP(showFps), CEREAL_NVP(gameSpeed), CEREAL_NVP(gameDifficulty), CEREAL_NVP(defaultVolume), CEREAL_NVP(musicVolume), CEREAL_NVP(soundVolume), CEREAL_NVP(godmode), CEREAL_NVP(infiniteAmmo));
	}

	ioController* ioC = &ioController::GetInstance();

public:
	static Settings& GetInstance() {
		static Settings instance;
		return instance;
	}

	void Save();
	void Load();


	bool getFiendlyFire() { return friendlyFire; };
	void setFriendlyFire(bool value) {friendlyFire = value;};

	bool getSound() { return sound; };
	void setSound(bool value) {	sound = value; };

	int getDefaultVolume() { return defaultVolume; };
	void setDefaultVolume(int value) { defaultVolume = value; };

	int getSoundVolume() { return soundVolume; };
	void setSoundVolume(int value) { soundVolume = value; };

	int getMusicVolume() { return musicVolume; };
	void setMusicVolume(int value) { musicVolume = value; };

	bool getMusic() { return music; };
	void setMusic(bool value) {	music = value; };

	bool getShowFps() { return showFps; };
	void setShowFps(bool value) { showFps = value; };

	bool getGodMode() { return godmode; };
	void toggleGodMode() { godmode = !godmode; };

	bool getInfiniteAmmo() { return infiniteAmmo; };
	void toggleInfiniteAmmo() { infiniteAmmo = !infiniteAmmo; };

	GameSpeed getGameSpeed() { return gameSpeed; };
	void setGameSpeed(GameSpeed value) { gameSpeed = value; };

	GameDifficulty getGameDifficulty() { return gameDifficulty; };
	void setGameDifficulty(GameDifficulty value) { gameDifficulty = value; };

};

