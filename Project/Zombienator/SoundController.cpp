#pragma once
#include "SoundController.h"
#include <iostream>

SoundController::SoundController()
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
	{
		cout << "Mix_OpenAudio error: " << Mix_GetError() << endl;
		return;
	}
	Mix_VolumeMusic(this->musicVolume);
	Mix_AllocateChannels(64);
}

Mix_Chunk* SoundController::Load(string path)
{
	if (Exists(path))
	{
		return sounds.at(path);
	}

	Mix_Chunk* chunk = Mix_LoadWAV(path.c_str());
	if (chunk == NULL) {
		std::cout << stderr << "Unable to load WAV file: %s\n" << Mix_GetError();
	}
	
	Mix_VolumeChunk(chunk, this->soundVolume);
	sounds.insert({ path, chunk });
	return chunk;
}

bool SoundController::Exists(string path)
{
	return sounds.find(path) != sounds.end();
}

/*
 * Channel to play on which channel
 * loops, amount of times to play ( -1 = infinite ) default = 1 time
 */
void SoundController::PlaySound(string path, int loops)
{
	Mix_Chunk* sound = Load(path);
	if (Mix_PlayChannel(-1, sound, loops) == -1) {
		std::cout << "Unable to play WAV file: %s\n" << Mix_GetError();
	}
}

void SoundController::ChangeMusic(string path)
{
	if (path == currentMusicPath)
	{
		return;
	}

	if (currentMusic != nullptr)
	{
		Mix_FreeMusic(currentMusic);
	}

	// Load music
	Mix_Music* music = Mix_LoadMUS(path.c_str());
	if (!music)
	{
		cout << "Mix_LoadMUS error: " << Mix_GetError() << endl;
		return;
	}

	// Play music
	if (Mix_PlayMusic(music, -1) == -1)
	{
		cout << "Mix_PlayMusic error : " << Mix_GetError() << endl;
	}

	currentMusic = music;
	currentMusicPath = path;
}

void SoundController::StopAllSounds()
{
	StopMusic();
	StopSounds();
}

void SoundController::StopMusic()
{
	Mix_FreeMusic(currentMusic);
	currentMusic = nullptr;
}

void SoundController::StopSounds()
{
	Mix_HaltChannel(-1);
}

void SoundController::MuteUnmuteMusic()
{
	int volume = (settings->getMusic() ? defaultVolume : 0);
	Mix_VolumeMusic(volume);
	this->musicVolume = volume;
}

void SoundController::MuteUnmuteSound()
{
	int volume = (settings->getSound() ? defaultVolume : 0);
	for each (auto& sound in sounds)
	{
		Mix_VolumeChunk(sound.second, volume);
	}
	this->soundVolume = volume;

}

void SoundController::SetVolume(int volume)
{
	if(this->soundVolume != 0){
		for each (auto& sound in sounds)
		{
			Mix_VolumeChunk(sound.second, volume);
		}
		this->soundVolume = volume;
	}

	if (this->musicVolume != 0) {
		Mix_VolumeMusic(volume);
		this->musicVolume = volume;
	}
	
	this->defaultVolume = volume;
}

SoundController::~SoundController()
{
	StopAllSounds();
	Mix_CloseAudio();
}
