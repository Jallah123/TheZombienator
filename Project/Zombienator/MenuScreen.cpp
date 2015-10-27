#include "MenuScreen.h"
#include <iostream>

SDL_Texture* texture = nullptr;

MenuScreen::MenuScreen(SDL_Renderer* ren) : AbstractScreen(ren)
{
	SDL_Surface *s = IMG_Load("assets/images/menu_bg.png");

	BackgroundTexture = SDL_CreateTextureFromSurface(ren, s);

	//Load && play sound
	loadSounds();
	playSound();
}

void MenuScreen::AddUIComponent(AbstractUIComponent* UIComponent)
{
	UIComponents.push_back(UIComponent);
}

void MenuScreen::ClickComponents(SDL_Point MousePosition)
{
	MenuScreen::stopSound();

	std::vector<AbstractUIComponent*>::iterator it;
	for (it = UIComponents.begin(); it != UIComponents.end(); it++) (*it)->OnClick(MousePosition);
}

void MenuScreen::Draw(SDL_Renderer& ren, float dt)
{	//Draw background
	SDL_RenderCopy(&ren, BackgroundTexture, 0, 0);

	std::vector<AbstractUIComponent*>::iterator it;
	for (it = UIComponents.begin(); it != UIComponents.end(); it++) (*it)->Draw(ren);
}

void MenuScreen::ChangeBackground(SDL_Renderer* ren, std::string img_url)
{
	char tab2[1024];
	SDL_Surface *s = IMG_Load(strcpy(tab2, img_url.c_str()));
	BackgroundTexture = SDL_CreateTextureFromSurface(ren, s);
}


void MenuScreen::loadSounds() {

	//more info : http://content.gpwiki.org/index.php/SDL_mixer:Tutorials:Playing_a_WAV_Sound_File
	//todo dit dynamische maken -> kan pas bij levelfactory
	sound = Mix_LoadWAV("assets/sounds/Undead-Rising.wav");
	if (sound == NULL) {
		std::cout << stderr << "Unable to load WAV file: %s\n" << Mix_GetError();
	}
}

void MenuScreen::playSound() {
	int channel;
	// first -1 will cause Mix_PlayChannel to play our sample on the first available sound channel.This is probably what you'll want to do, in most cases. If for some reason you wish to specify a certain channel for playback, you may pass an integer designating the desired channel.
	//sound for the sound chunk
	// Second -1 to play soundchunk only once. Passing -1 plays the sample on an infinite loop.
	channel = Mix_PlayChannel(-1, sound, -1);
	if (channel == -1) {
		std::cout << stderr << "Unable to play WAV file: %s\n" << Mix_GetError();
	}

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

}

void MenuScreen::stopSound() {
	Mix_FreeChunk(sound);
	Mix_CloseAudio();
}