#include "SelectionScreen.h"
#include <iostream>
#include <time.h>
#include <SDL_image.h>
#include "Button.h"
#include "Image.h"

struct PreviousButton : AbstractUIComponent {
	SelectionScreen* selectionScreen;

	PreviousButton(SDL_Renderer& ren, SelectionScreen* _selectionScreen) : AbstractUIComponent(ren) {
		selectionScreen = _selectionScreen;
	}

	void Draw(SDL_Renderer& ren) {
		std::string img_url{ "assets/images/previous.bmp" };
		char tab2[1024];
		SDL_Surface* s = IMG_Load(strcpy(tab2, img_url.c_str()));
		SDL_Texture* Image = SDL_CreateTextureFromSurface(&ren, s);
		SDL_RenderCopy(&ren, Image, 0, this);
	}

	void ClickAction() {
		selectionScreen->SetCurrentImageIndex(selectionScreen->GetCurrentImageIndex() - 1);
		if (selectionScreen->GetCurrentImageIndex() < 0)
		{
			selectionScreen->SetCurrentImageIndex(selectionScreen->GetImages().size() - 1);
		}
		selectionScreen->SetCurrentImage(&selectionScreen->GetImages().at(selectionScreen->GetCurrentImageIndex()));
	}
};

struct NextButton : AbstractUIComponent {
	SelectionScreen* selectionScreen;

	NextButton(SDL_Renderer& ren, SelectionScreen* _selectionScreen) : AbstractUIComponent(ren) {
		selectionScreen = _selectionScreen;
	}

	void Draw(SDL_Renderer& ren) {
		std::string img_url{ "assets/images/next.bmp" };
		char tab2[1024];
		SDL_Surface* s = IMG_Load(strcpy(tab2, img_url.c_str()));
		SDL_Texture* Image = SDL_CreateTextureFromSurface(&ren, s);
		SDL_RenderCopy(&ren, Image, 0, this);
	}

	void ClickAction() {
		selectionScreen->SetCurrentImageIndex(selectionScreen->GetCurrentImageIndex() + 1);
		if (selectionScreen->GetCurrentImageIndex() >= selectionScreen->GetImages().size())
		{
			selectionScreen->SetCurrentImageIndex(0);
		}
		selectionScreen->SetCurrentImage(&selectionScreen->GetImages().at(selectionScreen->GetCurrentImageIndex()));
	}
};

SelectionScreen::SelectionScreen(SDL_Renderer* ren) : MenuScreen(ren)
{
	std::cout << "Made SelectionScreen" << std::endl;

	//Add images to vector
	Image* image2 = new Image{ *ren, "assets/images/next.png" };
	image2->SetDimensions(200, 10, 250, 250);
	image2->SetLocation(500, 200);
	AddImage(*image2);

	Image* image3 = new Image{ *ren, "assets/images/previous.png" };
	image3->SetDimensions(200, 10, 250, 250);
	image3->SetLocation(500, 200);
	AddImage(*image3);

	//Init buttons
	PreviousButton* previousButton = new PreviousButton(*ren, this);
	previousButton->SetDimensions(100, 10, 75, 75);
	previousButton->SetLocation(100, 282);
	AddUIComponent(previousButton);

	NextButton* nextButton = new NextButton(*ren, this);
	nextButton->SetDimensions(100, 10, 75, 75);
	nextButton->SetLocation(1080, 282);
	AddUIComponent(nextButton);

	Button* selectButton = new Button(*ren, "Select character", "assets/images/select.bmp");
	selectButton->SetDimensions(100, 10, 250, 90);
	selectButton->SetLocation(500, 500);
	AddUIComponent(selectButton);

	//Testing
	currentImage = image2;
	AddUIComponent(currentImage);
}

void SelectionScreen::AddImage(Image img)
{
	images.push_back(img);
}

SelectionScreen::~SelectionScreen()
{

}