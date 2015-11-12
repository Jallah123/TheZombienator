#pragma once
#include "MusicController.h"
#include <iostream>

void MusicController::Load(const char* filename)
{
	chunk = Mix_LoadWAV(filename);
	if (chunk == NULL) {
		std::cout << stderr << "Unable to load WAV file: %s\n" << Mix_GetError();
	}
}

/*
 * Channel to play on which channel
 * loops, amount of times to play ( -1 = infinite )
 */
void MusicController::Play(int channel, int loops)
{
	int mix_channel = -1;

	mix_channel = Mix_PlayChannel(channel, chunk, loops);
	if (mix_channel == -1) {
		std::cout << stderr << "Unable to play WAV file: %s\n" << Mix_GetError();
	}
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
}

void MusicController::Stop()
{
	Mix_FreeChunk(chunk);
	Mix_CloseAudio();
}

void MusicController::SetVolume(int volume, int channel)
{
	this->volume = volume; 
	Mix_Volume(channel, this->volume);
}

MusicController::~MusicController()
{
}
