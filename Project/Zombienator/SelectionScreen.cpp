#include "SelectionScreen.h"
#include <iostream>
#include <time.h>
#include "Button.h"
#include "TextureFactory.h"
#include "ScreenFactory.h"
#include "ScreenController.h"

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
	}

	void ClickAction() {
		ScreenController::GetInstance().ChangeScreen(ScreenFactory::Create(ScreenEnum::GAMESCREEN, "assets/maps/landscape-1280x640.json", _ss->GetImages().at(_ss->GetCurrentImageIndex())->GetImageUrl()));
	}
};

SelectionScreen::SelectionScreen(SDL_Renderer* ren) : MenuScreen(ren)
{
	std::cout << "Made SelectionScreen" << std::endl;
	backgroundTexture = TextureFactory::GenerateTextureFromImgUrl("assets/images/default_bg.png");
	images.push_back(new Image(*ren, "assets/images/spritesheets/Boy1.png"));
	images.push_back(new Image(*ren, "assets/images/spritesheets/Boy2.png"));

	//Init buttons
	char* ssUrl = "assets/images/button_spritesheet.png";

	title = TextureFactory::GenerateText("Character selection", 32, 625, 100, true);

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
	sbtn->SetSourceLocation(0, 238);
	sbtn->SetSize(239, 97);
	sbtn->SetDestLocation(500, 500);
	AddUIComponent(sbtn);

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

}