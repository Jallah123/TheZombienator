#pragma once
#include "SwitchButtonGameDifficulty.h"
#include "TextureFactory.h"

SwitchButtonGameDifficulty::SwitchButtonGameDifficulty(SDL_Renderer& ren, char* text, char* img_url, int posX, int posY, GameDifficulty value, AbstractScreen &_parentScreen)
	: Button(ren, text, img_url) {

	destRect = { posX, posY, 100, 60 };
	this->parentScreen = &_parentScreen;
	this->value = value;
	buttonText = TextureFactory::GenerateText(string(text), 18, posX + (destRect.w / 2), posY + (destRect.h / 2), FontEnum::CARTOON, { 248 ,248 ,255 });

	updateLayout();
}


void SwitchButtonGameDifficulty::ClickAction() {
	updateParent(this->value);
}

void SwitchButtonGameDifficulty::setUpdateFunction(std::function<void(const GameDifficulty&)> func) {
	this->updateParent = func;
}



void SwitchButtonGameDifficulty::updateLayout() {
	if (this->value == Settings->getGameDifficulty()) {
		srcRect = enableRect;
	}
	else {
		srcRect = disableRect;
	}
}

SwitchButtonGameDifficulty::SwitchButtonGameDifficulty()
{
}

SwitchButtonGameDifficulty::~SwitchButtonGameDifficulty()
{
}
