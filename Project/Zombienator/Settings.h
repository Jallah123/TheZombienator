#pragma once
#include "GameSpeed.cpp"
#include "GameDifficulty.cpp"

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

	GameSpeed gameSpeed = GameSpeed::NORMAL;
	GameDifficulty gameDifficulty = GameDifficulty::MEDIUM;

public:
	static Settings& GetInstance() {
		static Settings instance;
		return instance;
	}

	bool getFiendlyFire() { return friendlyFire; };
	void setFriendlyFire(bool value) {friendlyFire = value;};

	bool getSound() { return sound; };
	void setSound(bool value) {	sound = value; };

	bool getMusic() { return music; };
	void setMusic(bool value) {	music = value; };

	bool getShowFps() { return showFps; };
	void setShowFps(bool value) { showFps = value; };

	GameSpeed getGameSpeed() { return gameSpeed; };
	void setGameSpeed(GameSpeed value) { gameSpeed = value; };

	GameDifficulty getGameDifficulty() { return gameDifficulty; };
	void setGameDifficulty(GameDifficulty value) { gameDifficulty = value; };

};

