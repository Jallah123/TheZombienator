#include "Settings.h"
Settings::Settings() {

}

Settings::~Settings() {

}

void Settings::Save() {
	ioC->SafeFile("settings",this);
}

void Settings::Load() {
	Settings* s = ioC->LoadFile("settings", this);
	if (s != nullptr) {
		friendlyFire = s->friendlyFire;
		sound = s->sound;
		music = s->music;
		showFps = s->showFps;
		gameSpeed = GameSpeed(s->gameSpeed);
		gameDifficulty = GameDifficulty(s->gameDifficulty);
		defaultVolume = s->defaultVolume;
		soundVolume = s->soundVolume;
		musicVolume = s->musicVolume;
	}
	
}