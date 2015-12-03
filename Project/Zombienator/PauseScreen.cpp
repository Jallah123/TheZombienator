#include "PauseScreen.h"

PauseScreen::PauseScreen(SDL_Renderer* ren) : MenuScreen(ren)
{
	char* spriteSheet = "assets/images/button_spritesheet.png";
	//default background
	ChangeBackground(ren, "assets/images/default_bg.png");

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
	CustomFuncButton* quitBtn = new CustomFuncButton(*ren, "Quit", spriteSheet, 540, 420, *this);
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
	ScreenController::GetInstance().ChangeScreen(new SettingsScreen{ renderer });

}

void PauseScreen::Quit()
{
	exit(EXIT_SUCCESS);
}


void PauseScreen::Update(float dt)
{


}

void PauseScreen::Draw(SDL_Renderer & ren, float dt)
{
	SDL_RenderCopy(&ren, backgroundTexture, 0, 0);
	for (const auto& i : UIComponents)
		i->Draw(ren);

}

