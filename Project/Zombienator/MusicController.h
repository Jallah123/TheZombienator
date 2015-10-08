#pragma once
#include "SDL_mixer.h"
class MusicController
{
private:
	MusicController() {};
	MusicController(MusicController const&) = delete;
	void operator=(MusicController const&) = delete;
	Mix_Music* CurrentMusic;
	int Volume;
public:
	static MusicController& GetInstance() {
		static MusicController instance;
		return instance;
	}
	void Play();
	void Change();
	void Pause();
	void SetVolume(int V);

};

