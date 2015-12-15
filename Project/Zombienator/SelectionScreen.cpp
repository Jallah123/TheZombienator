#include "SelectionScreen.h"
#include <iostream>
#include <time.h>
#include "Button.h"
#include "TextureFactory.h"
#include "ScreenFactory.h"
#include "ScreenController.h"
#include "MapFactory.h"
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
		SetSize(239, 102);
		SetDestLocation(500, 500);
		buttonText = TextureFactory::GenerateText(string(text), 24, destRect.x + (destRect.w / 2), destRect.y + (destRect.h / 2), FontEnum::CARTOON, { 248 ,248 ,255 });
	}

	void ClickAction() {
		ScreenController::GetInstance().ChangeScreen(ScreenFactory::Create(ScreenEnum::GAMESCREEN, _ss->GetImages().at(_ss->GetCurrentImageIndex())->GetImageUrl()));
	}
};

struct TutorialButton : Button {
	SelectionScreen* _ss;

	TutorialButton(SDL_Renderer& ren, char* text, char* img_url, SelectionScreen* ss)
		: Button(ren, text, img_url) {
		_ss = ss;
		SetSourceLocation(286, 320);
		SetSize(82, 81);
		SetDestLocation(1190, 10);
	}

	void ClickAction() { // Start Tutorial mode here

		MapFactory::GetInstance()->TutorialMode();
		ScreenController::GetInstance().ChangeScreen(ScreenFactory::Create(ScreenEnum::GAMESCREEN, _ss->GetImages().at(_ss->GetCurrentImageIndex())->GetImageUrl()));

	}
};

SelectionScreen::SelectionScreen(SDL_Renderer* ren) : MenuScreen(ren)
{
	std::cout << "Made SelectionScreen" << std::endl;
	backgroundTexture = TextureFactory::GenerateTextureFromImgUrl("assets/images/default_bg.png");
	images.push_back(new Image(*ren, "assets/images/spritesheets/Boy1.png"));
	images.push_back(new Image(*ren, "assets/images/spritesheets/Boy2.png"));
	images.push_back(new Image(*ren, "assets/images/spritesheets/Boy3.png"));
	images.push_back(new Image(*ren, "assets/images/spritesheets/Boy4.png"));
	images.push_back(new Image(*ren, "assets/images/spritesheets/Girl1.png"));
	images.push_back(new Image(*ren, "assets/images/spritesheets/Girl2.png"));
	//Init buttons
	char* ssUrl = "assets/images/button_spritesheet.png";

	title = TextureFactory::GenerateText("Character selection", 32, 625, 100, FontEnum::CARTOON, { 248 ,248 ,255 });

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

	TutorialButton* tbtn = new TutorialButton(*ren, "", ssUrl, this);
	AddUIComponent(tbtn);

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
	SDL_RenderCopy(&ren, backgroundTexture, 0, 0);
	for (const auto& c : UIComponents)
	{
		c->Draw(ren);
	}
	images.at(currentImageIndex)->Draw(ren);
	SDL_RenderCopy(&ren, title.first, 0, &title.second);
}

SelectionScreen::~SelectionScreen()
{
	for (auto& image: images)
	{
		delete image;
	}
}