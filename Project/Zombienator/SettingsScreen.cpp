#include "SettingsScreen.h"
#include <functional>
#include <iostream>
#include <string>
#include <vector>

SettingsScreen::SettingsScreen(SDL_Renderer* ren) : MenuScreen(ren)
{
	//default background
	ChangeBackground(ren, "assets/images/default_bg.png");

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
	//Label* difficultyLabel = new Label(ren, "Difficulty", 275, 250, 30, fontUrl, { 255,50,50 });  //ren, text, xpos,ypos, fontsize, color
	//Label* gamespeedLabel = new Label(ren, "Game speed", 275, 300, 30, fontUrl, { 255,50,50 });
	Label* fpsLabel = new Label(ren, "FPS", 500, 265, 30, { 0,0,0 });
	Label* ffLabel = new Label(ren, "Friendly fire", 500, 335, 30, { 0,0,0 });
	Label* soundLabel = new Label(ren, "Sound", 500, 410, 30, { 0,0,0 });
	Label* musicLabel = new Label(ren, "Music", 500, 480, 30, { 0,0,0 });
	//AddUIComponent(difficultyLabel);
	//AddUIComponent(gamespeedLabel);
	AddUIComponent(fpsLabel);
	AddUIComponent(ffLabel);
	AddUIComponent(soundLabel);
	AddUIComponent(musicLabel);

	//buttons
	musicOnBtn = new SwitchButton(ren, "On", spriteSheet, 725, 450, true, Settings->getMusic(), *this); //renderer, text,spritesheet,posx,posy, swithvalue, switchEnabledstatus, AbstractScreen
	musicOnBtn->setUpdateFunction(std::bind(&SettingsScreen::setMusic, this, std::placeholders::_1));
	AddUIComponent(musicOnBtn);

	musicOffBtn = new SwitchButton(ren, "Off", spriteSheet, 830, 450, false, !Settings->getMusic(), *this);
	musicOffBtn->setUpdateFunction(std::bind(&SettingsScreen::setMusic, this, std::placeholders::_1));
	AddUIComponent(musicOffBtn);

	soundOnBtn = new SwitchButton(ren, "On", spriteSheet, 725, 370, true, Settings->getSound(), *this);
	soundOnBtn->setUpdateFunction(std::bind(&SettingsScreen::setSound, this, std::placeholders::_1));
	AddUIComponent(soundOnBtn);

	soundOffBtn = new SwitchButton(ren, "Off", spriteSheet, 830, 370, false, !Settings->getSound(), *this);
	soundOffBtn->setUpdateFunction(std::bind(&SettingsScreen::setSound, this, std::placeholders::_1));
	AddUIComponent(soundOffBtn);

	friendlyFireOnBtn = new SwitchButton(ren, "On", spriteSheet, 725, 300, true, Settings->getFiendlyFire(), *this);
	friendlyFireOnBtn->setUpdateFunction(std::bind(&SettingsScreen::setFriendlyFire, this, std::placeholders::_1));
	AddUIComponent(friendlyFireOnBtn);

	friendlyFireOffBtn = new SwitchButton(ren, "Off", spriteSheet, 830, 300, false, !Settings->getFiendlyFire(), *this);
	friendlyFireOffBtn->setUpdateFunction(std::bind(&SettingsScreen::setFriendlyFire, this, std::placeholders::_1));
	AddUIComponent(friendlyFireOffBtn);

	fpsOnBtn = new SwitchButton(ren, "On", spriteSheet, 725, 230, true, Settings->getShowFps(), *this);
	fpsOnBtn->setUpdateFunction(std::bind(&SettingsScreen::setFPS, this, std::placeholders::_1));
	AddUIComponent(fpsOnBtn);

	fpsOffBtn = new SwitchButton(ren, "Off", spriteSheet, 830, 230, false, !Settings->getShowFps(), *this);
	fpsOffBtn->setUpdateFunction(std::bind(&SettingsScreen::setFPS, this, std::placeholders::_1));
	AddUIComponent(fpsOffBtn);
}

SettingsScreen::~SettingsScreen()
{
	SoundController->StopAllSounds();
}



void SettingsScreen::Update(float dt)
{


}

void SettingsScreen::Draw(SDL_Renderer & ren, float dt)
{
	SDL_RenderCopy(&ren, this->backgroundTexture, 0, 0);
	for (const auto& i : UIComponents)
		i->Draw(ren);

}


