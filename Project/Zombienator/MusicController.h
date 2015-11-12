#pragma once
#include "SDL_mixer.h"
#include <string>
class MusicController
{
private:
	MusicController() {};
	MusicController(MusicController const&) = delete;
	void operator=(MusicController const&) = delete;
	Mix_Music* currentMusic = nullptr;
	Mix_Chunk* chunk = nullptr;
	int volume;
public:
	static MusicController& GetInstance() {
		static MusicController instance;
		return instance;
	}
	~MusicController();
	void Load(const char* filename);
	void Play(int channel, int loops);
	void Pause();
	void Stop();
	void SetVolume(int volume, int channel);
	int GetVolume() { return this->volume; }
};

