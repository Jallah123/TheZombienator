#include "Label.h"
#include "SDL.h"
#include "TextureFactory.h"

Label::Label() : AbstractUIComponent()
{
}

Label::Label(SDL_Renderer& ren, string text, int posX, int posY, int fontSize, SDL_Color color) : AbstractUIComponent(ren) {
	this->_posX = posX;
	this->_posY = posY;
	this->_fontSize = fontSize;
	this->_color = color;
	label = TextureFactory::GenerateText(text, fontSize, posX, posY, FontEnum::CARTOON, color);
}

Label::Label(SDL_Renderer& ren, int number, int posX, int posY, int fontSize, SDL_Color color) : AbstractUIComponent(ren) {
	this->_posX = posX;
	this->_posY = posY;
	this->_fontSize = fontSize;
	this->_color = color;
	label = TextureFactory::GenerateText(to_string(number), fontSize, posX, posY, FontEnum::ROBOTO, color);
}

Label::~Label()
{
}

void Label::updateText(string text) {
	label = TextureFactory::GenerateText(text, _fontSize, _posX, _posY, FontEnum::CARTOON, _color);
}

void Label::updateText(int text) {
	label = TextureFactory::GenerateText(to_string(text), _fontSize, _posX, _posY, FontEnum::ROBOTO, _color);
}

void Label::Draw(SDL_Renderer& ren) {
	SDL_RenderCopy(&ren, label.first, NULL, &label.second);
}

void Label::ClickAction() {
}

