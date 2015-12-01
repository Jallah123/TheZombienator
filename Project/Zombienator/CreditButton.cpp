#include "CreditButton.h"
#include "SoundController.h"
#include "ScreenController.h"
#include "CreditScreen.h"



CreditButton::CreditButton(SDL_Renderer& ren, char* text, char* img_url)
	: Button(ren, text, img_url) {
	srcRect = { 286 , 160, 82, 81 };
	destRect = { 1189, 100, 82, 81 };
}

CreditButton::CreditButton()
{
}


CreditButton::~CreditButton()
{
}

void CreditButton::ClickAction()
{
	SoundController::GetInstance().StopAllSounds();
	ScreenController::GetInstance().ChangeScreen(new CreditScreen{ renderer});
}

