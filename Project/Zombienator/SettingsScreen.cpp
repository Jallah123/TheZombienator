#include "SettingsScreen.h"
#include <functional>
#include <iostream>
#include <string>
#include <vector>

SettingsScreen::SettingsScreen(SDL_Renderer* ren) : MenuScreen(ren)
{

	//stop sound:
	SoundController->StopAllSounds();

	initCompontents(*ren);

}


void SettingsScreen::initCompontents(SDL_Renderer &ren)
{
	char* spriteSheet = "assets/images/button_spritesheet_settings.png";

	//back button
	BackButton* b = new BackButton(ren, "", "assets/images/button_spritesheet.png");
	AddUIComponent(b);

	//labels:
	Label* difficultyLabel = new Label(ren, "Difficulty", 275, 250, 30, { 255,50,50 });  //ren, text, xpos,ypos, fontsize, color
	Label* gamespeedLabel = new Label(ren, "Game speed", 275, 300, 30, { 255,50,50 });
	Label* ffLabel = new Label(ren, "Friendly fire", 275, 350, 30, { 255,50,50 });
	Label* soundLabel = new Label(ren, "Sound", 275, 400, 30, { 255,50,50 });
	Label* musicLabel = new Label(ren, "Music", 275, 450, 30, { 255,50,50 });
	AddUIComponent(difficultyLabel);
	AddUIComponent(gamespeedLabel);
	AddUIComponent(ffLabel);
	AddUIComponent(soundLabel);
	AddUIComponent(musicLabel);

	//buttons
	SwitchButton* musicOnBtn = new SwitchButton(ren, "On", spriteSheet ,500, 400, true, true, *this); //renderer, text,spritesheet,posx,posy, swithvalue, switchEnabledstatus, update void,AbstractScreen
	musicOnBtn->setUpdateFunction(std::bind(&SettingsScreen::setSound, this, std::placeholders::_1));
	AddUIComponent(musicOnBtn);

	SwitchButton* musicOffBtn = new SwitchButton(ren, "Off", spriteSheet, 605, 400, false, false, *this);
	musicOffBtn->setUpdateFunction(std::bind(&SettingsScreen::setSound, this, std::placeholders::_1));
	AddUIComponent(musicOffBtn);
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


