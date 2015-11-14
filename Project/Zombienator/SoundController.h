#pragma once
#include "SDL_mixer.h"
#include <string>
#include <map>

using namespace std;
class MusicController
{
private:
	MusicController();
	MusicController(MusicController const&) = delete;
	void operator=(MusicController const&) = delete;
	Mix_Music* currentMusic = nullptr;
	map<string, Mix_Chunk*> sounds;
	Mix_Chunk* Load(string filename);
	bool Exists(string path);
	int volume = 25;
public:
	static MusicController& GetInstance() {
		static MusicController instance;
		return instance;
	}
	~MusicController();
	void PlaySound(string path, int loops = 1);
	void ChangeMusic(string path);
	void Pause();
	void StopAllSounds();
	void SetVolume(int volume);
	int GetVolume() { return this->volume; }
};

