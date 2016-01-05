#include "SelectionScreen.h"
#include <iostream>
#include <time.h>
#include "Button.h"
#include "TextureFactory.h"
#include "ScreenFactory.h"
#include "ScreenController.h"
#include "BackButton.h"

struct PreviousButton : Button {
	SelectionScreen* _ss;

	PreviousButton(SDL_Renderer& ren, char* text, char* img_url, SelectionScreen* ss)
		: Button(ren, text, img_url) {
		_ss = ss;
	}

	void ClickAction() {
		_ss->SetCurrentImageIndex(_ss->GetCurrentImageIndex() - 1);
		if (_ss->GetCurrentImageIndex() < 0)
		{
			_ss->SetCurrentImageIndex(_ss->GetImages().size() - 1);
		}
	}
};

struct NextButton : Button {
	SelectionScreen* _ss;

	NextButton(SDL_Renderer& ren, char* text, char* img_url, SelectionScreen* ss)
		: Button(ren, text, img_url) {
		_ss = ss;
	}

	void ClickAction() {
		_ss->SetCurrentImageIndex(_ss->GetCurrentImageIndex() + 1);
		if (_ss->GetCurrentImageIndex() >= _ss->GetImages().size())
		{
			_ss->SetCurrentImageIndex(0);
		}
	}
};

struct SelectButton : Button {
	SelectionScreen* _ss;

	SelectButton(SDL_Renderer& ren, char* text, char* img_url, SelectionScreen* ss)
		: Button(ren, text, img_url) {
		_ss = ss;
		SetSourceLocation(0, 238);
		SetSize(239, 97);
		SetDestLocation(500, 500);
		buttonText = TextureFactory::GenerateText(string(text), 24, destRect.x + (destRect.w / 2), destRect.y + (destRect.h / 2), FontEnum::CARTOON, { 248 ,248 ,255 });
	}

	void ClickAction() {
		_ss->getCharacterImages().push_back(_ss->GetImages().at(_ss->GetCurrentImageIndex())->GetImageUrl());
		if (_ss->getCharacterImages().size() == _ss->getAmountOfPlayers())
		{
			string mapPath = _ss->getMapUrl();
			vector<string> imageUrls = _ss->getCharacterImages();
			ScreenController::GetInstance().Back();
			ScreenController::GetInstance().ChangeScreen(ScreenFactory::CreateGameScreen(imageUrls, mapPath));
		}
		else 
		{
			_ss->setSubTitle(TextureFactory::GenerateText("Player" + to_string(_ss->getCharacterImages().size() + 1), 32, 550, 150, FontEnum::OCR, { 248 ,248 ,255 }));
		}
	}
};

SelectionScreen::SelectionScreen(SDL_Renderer* ren) : MenuScreen(ren)
{
	std::cout << "Made SelectionScreen" << std::endl;
	backgroundTexture = TextureFactory::CreateTexture("assets/images/default_bg.png");
	images.push_back(new Image(*ren, "assets/images/spritesheets/Boy1.png"));
	images.push_back(new Image(*ren, "assets/images/spritesheets/Boy2.png"));
	images.push_back(new Image(*ren, "assets/images/spritesheets/Boy3.png"));
	images.push_back(new Image(*ren, "assets/images/spritesheets/Boy4.png"));
	images.push_back(new Image(*ren, "assets/images/spritesheets/Girl1.png"));
	images.push_back(new Image(*ren, "assets/images/spritesheets/Girl2.png"));
	//Init buttons
	char* ssUrl = "assets/images/button_spritesheet.png";

	title = TextureFactory::GenerateText("Character selection", 32, 625, 100, FontEnum::CARTOON, { 248 ,248 ,255 });
	subTitle = TextureFactory::GenerateText("Player" + to_string(getCharacterImages().size()+1), 32, 550, 150, FontEnum::OCR, { 248 ,248 ,255 });

	PreviousButton* pbtn = new PreviousButton(*ren, "Previous", ssUrl, this);
	pbtn->SetSourceLocation(0, 0);
	pbtn->SetSize(83, 76);
	pbtn->SetDestLocation(100, 282);
	AddUIComponent(pbtn);

	NextButton* nbtn = new NextButton(*ren, "Next", ssUrl, this);
	nbtn->SetSourceLocation(86, 0);
	nbtn->SetSize(83, 76);
	nbtn->SetDestLocation(1080, 282);
	AddUIComponent(nbtn);

	SelectButton* sbtn = new SelectButton(*ren, "Select", ssUrl, this);
	AddUIComponent(sbtn);

	BackButton* b = new BackButton(*ren, "", "assets/images/button_spritesheet.png");
	AddUIComponent(b);

	for (auto& image : images)
	{
		image->SetSourceLocation(0, 0);
		image->SetSize(36, 38);
		image->SetDestLocation(600, 282);
	}
}

void SelectionScreen::Update(float dt)
{

}

void SelectionScreen::Draw(SDL_Renderer & ren, float dt)
{
	AbstractScreen::Draw(ren, dt);
	images.at(currentImageIndex)->Draw(ren);
	SDL_RenderCopy(&ren, title.first, 0, &title.second);
	SDL_RenderCopy(&ren, subTitle.first, 0, &subTitle.second);
	HandleKeyboardEvents(ren, dt);
}

SelectionScreen::~SelectionScreen()
{
	for (auto& image: images)
	{
		delete image;
	}
}