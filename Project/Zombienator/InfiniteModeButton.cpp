#pragma once
#include "InfiniteModeButton.h"
#include "ScreenFactory.h"
#include "ScreenController.h"
#include "TextureFactory.h"

InfiniteModeButton::InfiniteModeButton(SDL_Renderer& ren, char* text, char* img_url) 
	: Button(ren, text, img_url) {
	SetSourceLocation(0, 238);
	SetSize(239, 97);
	SetDestLocation(515, 325);
	buttonText = TextureFactory::GenerateText(string(text), 24, destRect.x + (destRect.w / 2), destRect.y + (destRect.h / 2), FontEnum::CARTOON, { 248 ,248 ,255 });
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

