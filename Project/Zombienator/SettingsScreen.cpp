#include "SettingsScreen.h"
#include <functional>
#include <iostream>
#include <string>
#include <vector>

SettingsScreen::SettingsScreen(SDL_Renderer* ren) : MenuScreen(ren)
{

	//stop sound:
	//SoundController->StopAllSounds();

	initCompontents(*ren);

}


void SettingsScreen::initCompontents(SDL_Renderer &ren)
{
	char* spriteSheet = "assets/images/button_spritesheet_settings.png";

	//back button
	BackButton* b = new BackButton(ren, "", "assets/images/button_spritesheet.png");
	AddUIComponent(b);

	//labels:
	//Label* difficultyLabel = new Label(ren, "Difficulty", 275, 250, 30, { 255,50,50 });  //ren, text, xpos,ypos, fontsize, color
	//Label* gamespeedLabel = new Label(ren, "Game speed", 275, 300, 30, { 255,50,50 });
	Label* ffLabel = new Label(ren, "Friendly fire", 375, 435, 30, { 255,50,50 });
	Label* soundLabel = new Label(ren, "Sound", 375, 510, 30, { 255,50,50 });
	Label* musicLabel = new Label(ren, "Music", 375, 580, 30, { 255,50,50 });
	//AddUIComponent(difficultyLabel);
	//AddUIComponent(gamespeedLabel);
	AddUIComponent(ffLabel);
	AddUIComponent(soundLabel);
	AddUIComponent(musicLabel);

	//buttons
	musicOnBtn = new SwitchButton(ren, "On", spriteSheet ,600, 550, true, music, *this); //renderer, text,spritesheet,posx,posy, swithvalue, switchEnabledstatus, update void,AbstractScreen
	musicOnBtn->setUpdateFunction(std::bind(&SettingsScreen::setMusic, this, std::placeholders::_1));
	AddUIComponent(musicOnBtn);

	musicOffBtn = new SwitchButton(ren, "Off", spriteSheet, 705, 550, false, !music, *this);
	musicOffBtn->setUpdateFunction(std::bind(&SettingsScreen::setMusic, this, std::placeholders::_1));
	AddUIComponent(musicOffBtn);

	soundOnBtn = new SwitchButton(ren, "On", spriteSheet, 600, 470, true, sound, *this);
	soundOnBtn->setUpdateFunction(std::bind(&SettingsScreen::setSound, this, std::placeholders::_1));
	AddUIComponent(soundOnBtn);

	soundOffBtn = new SwitchButton(ren, "Off", spriteSheet, 705, 470, false, !sound, *this);
	soundOffBtn->setUpdateFunction(std::bind(&SettingsScreen::setSound, this, std::placeholders::_1));
	AddUIComponent(soundOffBtn);

	friendlyFireOnBtn = new SwitchButton(ren, "On", spriteSheet, 600, 400, true, friendlyFire, *this);
	friendlyFireOnBtn->setUpdateFunction(std::bind(&SettingsScreen::setFriendlyFire, this, std::placeholders::_1));
	AddUIComponent(friendlyFireOnBtn);

	friendlyFireOffBtn = new SwitchButton(ren, "Off", spriteSheet, 705, 400, false, !friendlyFire, *this);
	friendlyFireOffBtn->setUpdateFunction(std::bind(&SettingsScreen::setFriendlyFire, this, std::placeholders::_1));
	AddUIComponent(friendlyFireOffBtn);
}

SettingsScreen::~SettingsScreen()
{

}



void SettingsScreen::Update(float dt)
{


}

void SettingsScreen::Draw(SDL_Renderer & ren, float dt)
{
	SDL_RenderCopy(&ren, BackgroundTexture, 0, 0);
	for (const auto& i : UIComponents)
		i->Draw(ren);

}


