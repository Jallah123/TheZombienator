#pragma once
#include "SwitchButtonGameSpeed.h"


SwitchButtonGameSpeed::SwitchButtonGameSpeed(SDL_Renderer& ren, char* text, char* img_url, int posX, int posY, GameSpeed value, AbstractScreen &_parentScreen)
	: Button(ren, text, img_url) {

	destRect = { posX, posY, 100, 60 };
	this->parentScreen = &_parentScreen;
	this->value = value;
	buttonText = TextureFactory::GenerateText(string(text), 18, posX + (destRect.w / 2), posY + (destRect.h / 2), true, { 248 ,248 ,255 });

	updateLayout();
}


void SwitchButtonGameSpeed::ClickAction() {
	updateParent(this->value);
}

void SwitchButtonGameSpeed::setUpdateFunction(std::function<void(const GameSpeed&)> func) {
	this->updateParent = func;
}



void SwitchButtonGameSpeed::updateLayout() {
	if (this->value == Settings->getGameSpeed()) {
		srcRect = enableRect;
	}
	else {
		srcRect = disableRect;
	}
}

SwitchButtonGameSpeed::SwitchButtonGameSpeed()
{
}

SwitchButtonGameSpeed::~SwitchButtonGameSpeed()
{
}
