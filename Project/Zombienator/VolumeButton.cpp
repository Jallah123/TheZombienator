#pragma once
#include "VolumeButton.h"


VolumeButton::VolumeButton(SDL_Renderer& ren, char* text, char* img_url, int posX, int posY, int value, AbstractScreen &_parentScreen)
	: Button(ren, text, img_url) {
	srcRect = { 0 , 239, 130, 95 };
	destRect = { posX, posY, 70, 60 };
	this->parentScreen = &_parentScreen;
	this->value = value;
	buttonText = TextureFactory::GenerateText(string(text), 24, posX + (destRect.w / 2), posY + (destRect.h / 2), FontEnum::ROBOTO, { 248 ,248 ,255 });
}


void VolumeButton::ClickAction() {
	updateParent(this->value);
}

void VolumeButton::setUpdateFunction(std::function<void(const int&)> func) {
	this->updateParent = func;
}


VolumeButton::VolumeButton()
{
}

VolumeButton::~VolumeButton()
{
}
