#include "MultiplayerButton.h"
#include "ScreenFactory.h"
#include "ScreenController.h"
#include "MapSelectionScreen.h"
#include "TextureFactory.h"

MultiplayerButton::MultiplayerButton()
{
}


MultiplayerButton::~MultiplayerButton()
{
}

MultiplayerButton::MultiplayerButton(SDL_Renderer& ren, char* text, char* img_url)
	: Button(ren, text, img_url) {
	SetSourceLocation(0, 238);
	SetSize(239, 97);
	SetDestLocation(515, 420);
	buttonText = TextureFactory::GenerateText(string(text), 24, destRect.x + (destRect.w / 2), destRect.y + (destRect.h / 2), FontEnum::CARTOON, { 248 ,248 ,255 });
}

void MultiplayerButton::ClickAction()
{
	MapSelectionScreen* mapSelectionScreen = static_cast<MapSelectionScreen*>(ScreenFactory::Create(ScreenEnum::MAPSELECTIONSCREEN));
	mapSelectionScreen->setAmountOfPlayers(2);
	ScreenController::GetInstance().ChangeScreen(mapSelectionScreen);
}