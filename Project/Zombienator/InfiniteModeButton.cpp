#pragma once
#include "InfiniteModeButton.h"
#include "ScreenFactory.h"
#include "ScreenController.h"
#include "TextureFactory.h"

InfiniteModeButton::InfiniteModeButton(SDL_Renderer& ren, char* text, char* img_url) 
	: Button(ren, text, img_url) {
	srcRect = { 0 , 442, 238, 102 };
	destRect = { 515, 322, 238, 102 };
}

InfiniteModeButton::InfiniteModeButton() : Button()
{
}

InfiniteModeButton::~InfiniteModeButton()
{
}

void InfiniteModeButton::ClickAction()
{
	//std::cout << "InfiniteModeButton Clicked!" << std::endl;
	ScreenController::GetInstance().ChangeScreen(ScreenFactory::Create(ScreenEnum::MAPSELECTIONSCREEN));

}

