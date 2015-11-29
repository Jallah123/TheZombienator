#pragma once
#include "SDL_mixer.h"
#include <string>
#include <map>

using namespace std;
class SoundController
{
private:
	SoundController();
	SoundController(SoundController const&) = delete;
	void operator=(SoundController const&) = delete;
	Mix_Music* currentMusic = nullptr;
	string currentMusicPath = "";
	map<string, Mix_Chunk*> sounds;
	Mix_Chunk* Load(string filename);
	bool Exists(string path);
	int volume = 25;
public:
	static SoundController& GetInstance() {
		static SoundController instance;
		return instance;
	}
	~SoundController();
	void PlaySound(string path, int loops = 1);
	void ChangeMusic(string path);
	void Pause();
	void StopAllSounds();
	void SetVolume(int volume);
	int GetVolume() { return this->volume; }
};

