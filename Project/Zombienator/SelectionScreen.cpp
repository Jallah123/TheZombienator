#include "SelectionScreen.h"
#include <iostream>
#include <time.h>
#include <SDL_image.h>
#include "Button.h"
#include "Image.h"

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
		_ss->SetCurrentImage(&_ss->GetImages().at(_ss->GetCurrentImageIndex()));
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
		_ss->SetCurrentImage(&_ss->GetImages().at(_ss->GetCurrentImageIndex()));
	}
};

struct SelectButton : Button {
	SelectionScreen* _ss;

	SelectButton(SDL_Renderer& ren, char* text, char* img_url, SelectionScreen* ss)
		: Button(ren, text, img_url) {
		_ss = ss;
	}
	
	void ClickAction() {
		_ss->SetCurrentImageIndex(_ss->GetCurrentImageIndex() + 1);
		if (_ss->GetCurrentImageIndex() >= _ss->GetImages().size())
		{
			_ss->SetCurrentImageIndex(0);
		}
		_ss->SetCurrentImage(&_ss->GetImages().at(_ss->GetCurrentImageIndex()));
	}
};

SelectionScreen::SelectionScreen() : MenuScreen()
{
}

SelectionScreen::SelectionScreen(SDL_Renderer* ren) : MenuScreen(ren)
{
	std::cout << "Made SelectionScreen" << std::endl;
	char* ssUrl = "assets/images/button_spritesheet.png";

	//Init buttons
	PreviousButton* pbtn = new PreviousButton(*ren, "Previous", ssUrl, this);
	
	pbtn->SetSourceLocation(100, 10);
	pbtn->SetSize(75, 75);
	pbtn->SetDestLocation(100, 282);
	AddUIComponent(pbtn);

	NextButton* nbtn = new NextButton(*ren, "Next", ssUrl, this);
	nbtn->SetSourceLocation(100, 10);
	nbtn->SetSize(75, 75);
	nbtn->SetDestLocation(1080, 282);
	AddUIComponent(nbtn);

	SelectButton* sbtn = new SelectButton(*ren,  "select", ssUrl, this);
	sbtn->SetSourceLocation(100, 10);
	sbtn->SetSize(250, 90);
	sbtn->SetDestLocation(500, 500);
	AddUIComponent(sbtn);

	//Testing
	AddUIComponent(currentImage);
}
SelectionScreen::~SelectionScreen()
{

}
void SelectionScreen::AddImage(Image img)
{
	images.push_back(img);
}

void SelectionScreen::Update(float dt)
{
}

void SelectionScreen::Draw(SDL_Renderer & ren, float dt)
{
	for (const auto& c : UIComponents)
		c->Draw(ren);
}
