#include "CreditButton.h"
#include "SoundController.h"
#include "ScreenController.h"
#include "CreditScreen.h"



CreditButton::CreditButton(SDL_Renderer& ren, char* text, char* img_url)
	: Button(ren, text, img_url) {
	srcRect = { 0 , 238, 238, 102 };
	destRect = { 515, 500, 238, 102 };
}

CreditButton::CreditButton()
{
}


CreditButton::~CreditButton()
{
}

void CreditButton::ClickAction()
{
	// SoundController::GetInstance().StopAllSounds();
	ScreenController::GetInstance().ChangeScreen(new CreditScreen{ renderer});
}

