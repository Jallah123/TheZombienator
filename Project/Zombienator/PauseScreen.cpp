#include "PauseScreen.h"
#include "ScreenFactory.h"
#include "Label.h"
#include "CustomFuncButton.h"
#include "MapFactory.h"

PauseScreen::PauseScreen(SDL_Renderer* ren) : MenuScreen(ren)
{
	char* spriteSheet = "assets/images/button_spritesheet.png";
	//default background
	ChangeBackground(ren, "assets/images/bg/default_bg.png");

	Label* pauseLabel = new Label(*ren, "Game paused", 655, 100, 44, { 255,255,240 });  //ren, text, xpos,ypos, fontsize, color
	AddUIComponent(pauseLabel);


	//resume button
	CustomFuncButton* resumebtn = new CustomFuncButton(*ren, "Resume", spriteSheet, 540, 200, *this);
	resumebtn->setUpdateFunction(std::bind(&PauseScreen::Resume, this));
	AddUIComponent(resumebtn);

	//resume button
	CustomFuncButton* settingsBtn = new CustomFuncButton(*ren, "Settings", spriteSheet, 540, 310, *this);
	settingsBtn->setUpdateFunction(std::bind(&PauseScreen::Settings, this));
	AddUIComponent(settingsBtn);

	//quit button
	CustomFuncButton* quitBtn = new CustomFuncButton(*ren, "Quit game", spriteSheet, 540, 420, *this);
	quitBtn->setUpdateFunction(std::bind(&PauseScreen::Quit, this));
	AddUIComponent(quitBtn);


}

PauseScreen::~PauseScreen()
{

}

void PauseScreen::Resume()
{
	ScreenController::GetInstance().Back();
}

void PauseScreen::Settings()
{
	ScreenController::GetInstance().ChangeScreen(ScreenFactory::Create(ScreenEnum::SETTINGSSCREEN));
}

void PauseScreen::Quit()
{
	MapFactory::GetInstance()->EmptyQueue();
	ScreenController::GetInstance().EmptyStack();
	ScreenController::GetInstance().ChangeScreen(ScreenFactory::Create(ScreenEnum::HOMESCREEN));
}


void PauseScreen::Update(float dt)
{


}

void PauseScreen::Draw(SDL_Renderer & ren, float dt)
{
	AbstractScreen::Draw(ren, dt);
	SDL_RenderCopy(&ren, backgroundTexture, 0, 0);
	for (const auto& i : UIComponents)
		i->Draw(ren);
	HandleKeyboardEvents(ren, dt);
}

