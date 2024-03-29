#include "SettingsScreen.h"
#include <vector>
#include "BackButton.h"
#include <functional>

SettingsScreen::SettingsScreen(SDL_Renderer* ren) : MenuScreen(ren)
{
	//default background
	ChangeBackground(ren, "assets/images/bg/default_bg.png");

	initCompontents(*ren);
}


void SettingsScreen::initCompontents(SDL_Renderer &ren)
{
	//load settings from file
	Settings->Load();

	char* spriteSheet = "assets/images/button_spritesheet_settings.png";

	//back button
	BackButton* b = new BackButton(ren, "", "assets/images/button_spritesheet.png");
	b->setUpdateParentFunction(std::bind(&SettingsScreen::saveSettings, this));
	AddUIComponent(b);

	//labels:
	//Label* difficultyLabel = new Label(ren, "Difficulty", 500, 120, 30, { 0,0,0 });  //ren, text, xpos,ypos, fontsize, color
	Label* gamespeedLabel = new Label(ren, "Game speed", 500, 190, 30, { 0,0,0 });
	Label* fpsLabel = new Label(ren, "FPS", 500, 265, 30, { 0,0,0 });
	Label* ffLabel = new Label(ren, "Friendly fire", 500, 335, 30, { 0,0,0 });
	Label* soundLabel = new Label(ren, "Sound", 500, 410, 30, { 0,0,0 });
	Label* musicLabel = new Label(ren, "Music", 500, 480, 30, { 0,0,0 });
	Label* volumeLabel = new Label(ren, "Volume", 500, 550, 30, { 0,0,0 });
	currentVolumeLabel = new Label(ren, SoundController->GetVolume(), 825, 545, 30, { 248 ,248 ,255 });

	//AddUIComponent(difficultyLabel);
	AddUIComponent(gamespeedLabel);
	AddUIComponent(fpsLabel);
	AddUIComponent(ffLabel);
	AddUIComponent(soundLabel);
	AddUIComponent(musicLabel);
	AddUIComponent(volumeLabel);
	AddUIComponent(currentVolumeLabel);

	//musicbtns
	musicOnBtn = new SwitchButton(ren, "On", spriteSheet, 725, 445, true, Settings->getMusic(), *this); //renderer, text,spritesheet,posx,posy, swithvalue, switchEnabledstatus, AbstractScreen
	musicOnBtn->setUpdateFunction(std::bind(&SettingsScreen::setMusic, this, std::placeholders::_1));

	musicOffBtn = new SwitchButton(ren, "Off", spriteSheet, 830, 445, false, !Settings->getMusic(), *this);
	musicOffBtn->setUpdateFunction(std::bind(&SettingsScreen::setMusic, this, std::placeholders::_1));
	//soundbtns
	soundOnBtn = new SwitchButton(ren, "On", spriteSheet, 725, 370, true, Settings->getSound(), *this);
	soundOnBtn->setUpdateFunction(std::bind(&SettingsScreen::setSound, this, std::placeholders::_1));

	soundOffBtn = new SwitchButton(ren, "Off", spriteSheet, 830, 370, false, !Settings->getSound(), *this);
	soundOffBtn->setUpdateFunction(std::bind(&SettingsScreen::setSound, this, std::placeholders::_1));
	//friendlyfirebtns
	friendlyFireOnBtn = new SwitchButton(ren, "On", spriteSheet, 725, 300, true, Settings->getFiendlyFire(), *this);
	friendlyFireOnBtn->setUpdateFunction(std::bind(&SettingsScreen::setFriendlyFire, this, std::placeholders::_1));

	friendlyFireOffBtn = new SwitchButton(ren, "Off", spriteSheet, 830, 300, false, !Settings->getFiendlyFire(), *this);
	friendlyFireOffBtn->setUpdateFunction(std::bind(&SettingsScreen::setFriendlyFire, this, std::placeholders::_1));

	//fpsbtns
	fpsOnBtn = new SwitchButton(ren, "On", spriteSheet, 725, 230, true, Settings->getShowFps(), *this);
	fpsOnBtn->setUpdateFunction(std::bind(&SettingsScreen::setFPS, this, std::placeholders::_1));

	fpsOffBtn = new SwitchButton(ren, "Off", spriteSheet, 830, 230, false, !Settings->getShowFps(), *this);
	fpsOffBtn->setUpdateFunction(std::bind(&SettingsScreen::setFPS, this, std::placeholders::_1));

	//Volume btns
	volumeDecBtn = new VolumeButton(ren, "-", spriteSheet, 725, 515, 1, *this);
	volumeDecBtn->setUpdateFunction(std::bind(&SettingsScreen::decreaseVolume, this, std::placeholders::_1));

	volumeIncBtn = new VolumeButton(ren, "+", spriteSheet, 858, 515, 1, *this);
	volumeIncBtn->setUpdateFunction(std::bind(&SettingsScreen::increaseVolume, this, std::placeholders::_1));

	//gamespeedbtns
	SwitchButtonGameSpeed* gameSpeedSlowBtn = new SwitchButtonGameSpeed(ren, "Slow", spriteSheet, 725, 160, GameSpeed::SLOW, *this);
	gameSpeedSlowBtn->setUpdateFunction(std::bind(&SettingsScreen::setGameSpeed, this, std::placeholders::_1));
	gameSpeedBtns.push_back(gameSpeedSlowBtn);

	SwitchButtonGameSpeed* gameSpeedNormalBtn = new SwitchButtonGameSpeed(ren, "Normal", spriteSheet, 830, 160, GameSpeed::NORMAL, *this);
	gameSpeedNormalBtn->setUpdateFunction(std::bind(&SettingsScreen::setGameSpeed, this, std::placeholders::_1));
	gameSpeedBtns.push_back(gameSpeedNormalBtn);

	SwitchButtonGameSpeed* gameSpeedFastBtn = new SwitchButtonGameSpeed(ren, "Fast", spriteSheet, 935, 160, GameSpeed::FAST, *this);
	gameSpeedFastBtn->setUpdateFunction(std::bind(&SettingsScreen::setGameSpeed, this, std::placeholders::_1));
	gameSpeedBtns.push_back(gameSpeedFastBtn);

	//gamedifficulty buttons
	/*
	SwitchButtonGameDifficulty* gameDiffEasy = new SwitchButtonGameDifficulty(ren, "Easy", spriteSheet, 725, 85, GameDifficulty::EASY, *this);
	gameDiffEasy->setUpdateFunction(std::bind(&SettingsScreen::setGameDifficulty, this, std::placeholders::_1));
	gameDifficultyBtns.push_front(gameDiffEasy);

	SwitchButtonGameDifficulty* gameDiffMedium = new SwitchButtonGameDifficulty(ren, "Medium", spriteSheet, 830, 85, GameDifficulty::MEDIUM, *this);
	gameDiffMedium->setUpdateFunction(std::bind(&SettingsScreen::setGameDifficulty, this, std::placeholders::_1));
	gameDifficultyBtns.push_front(gameDiffMedium);

	SwitchButtonGameDifficulty* gameDiffhard = new SwitchButtonGameDifficulty(ren, "Hard", spriteSheet, 935, 85, GameDifficulty::HARD, *this);
	gameDiffhard->setUpdateFunction(std::bind(&SettingsScreen::setGameDifficulty, this, std::placeholders::_1));
	gameDifficultyBtns.push_front(gameDiffhard);
	for (const auto& g : gameDifficultyBtns)
		AddUIComponent(g);
	*/

	//add gameSpeed buttons && gameDifficulty buttons
	for (const auto& i : gameSpeedBtns)
		AddUIComponent(i);

	AddUIComponent(fpsOnBtn);
	AddUIComponent(fpsOffBtn);
	AddUIComponent(friendlyFireOnBtn);
	AddUIComponent(friendlyFireOffBtn);
	AddUIComponent(soundOnBtn);
	AddUIComponent(soundOffBtn);
	AddUIComponent(musicOnBtn);
	AddUIComponent(musicOffBtn);
	AddUIComponent(volumeDecBtn);
	AddUIComponent(volumeIncBtn);
}

SettingsScreen::~SettingsScreen()
{
}

void SettingsScreen::Update(float dt)
{
}

void SettingsScreen::Draw(SDL_Renderer & ren, float dt)
{
	AbstractScreen::Draw(ren, dt);
	SDL_RenderCopy(&ren, this->backgroundTexture, 0, 0);
	for (const auto& i : UIComponents)
		i->Draw(ren);

	HandleKeyboardEvents(ren, dt);
}


