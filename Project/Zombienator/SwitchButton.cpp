#pragma once
#include "SwitchButton.h"


SwitchButton::SwitchButton(SDL_Renderer& ren, char* text, char* img_url, int posX, int posY, bool value, bool _enableStatus, AbstractScreen &_parentScreen)
	: Button(ren, text, img_url) {

	destRect = { posX, posY, 100, 60 };
	this->parentScreen = &_parentScreen;
	this->enableStatus = _enableStatus;
	this->value = value;
	buttonText = TextureFactory::GenerateText(string(text), 24, posX + (destRect.w / 2), posY + (destRect.h / 2), { 248 ,248 ,255 });
	updateLayout();
}


void SwitchButton::ClickAction() {
	updateParent(this->value);
}

void SwitchButton::setUpdateFunction(std::function<void(const bool&)> func) {
	this->updateParent = func;
}



void SwitchButton::updateLayout() {
	if (enableStatus) {
		srcRect = enableRect;
	}
	else {
		srcRect = disableRect;
	}
}

SwitchButton::SwitchButton()
{
}

SwitchButton::~SwitchButton()
{
}
