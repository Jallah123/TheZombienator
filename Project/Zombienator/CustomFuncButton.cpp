#pragma once
#include "CustomFuncButton.h"


CustomFuncButton::CustomFuncButton(SDL_Renderer& ren, char* text, char* img_url, int posX, int posY, AbstractScreen &_parentScreen)
	: Button(ren, text, img_url) {
	srcRect = { 0 , 239, 238, 102 };
	destRect = { posX, posY, 238, 102 };
	this->parentScreen = &_parentScreen;
	buttonText = TextureFactory::GenerateText(string(text), 30, posX + (destRect.w / 2), posY + (destRect.h / 2), FontEnum::ROBOTO, { 248 ,248 ,255 });
}


void CustomFuncButton::ClickAction() {
	updateParent();
}

void CustomFuncButton::setUpdateFunction(std::function<void()> func) {
	this->updateParent = func;
}


CustomFuncButton::CustomFuncButton()
{
}

CustomFuncButton::~CustomFuncButton()
{
}
