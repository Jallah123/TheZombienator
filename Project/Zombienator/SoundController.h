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
	bool playSounds = true;
	bool playMusic = true;
public:
	static SoundController& GetInstance() {
		static SoundController instance;
		return instance;
	}
	~SoundController();
	void PlaySound(string path, int loops = 1);
	void ChangeMusic(string path);
	void Pause();
	void StopMusic();
	void StopSounds();
	void StopAllSounds();
	void SetVolume(int volume);
	void SetPlayMusic(bool _playMusic) { playMusic = _playMusic; if (!playMusic) StopMusic(); };
	void SetPlaySounds(bool _playSounds) { playSounds = _playSounds; if (!playSounds) StopSounds(); };
	bool getPlaySounds() { return playSounds; };
	bool getPlayMusic() { return playMusic; };
	int GetVolume() { return this->volume; }
};

