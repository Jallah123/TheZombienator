#include "SelectionScreen.h"
#include <iostream>
#include <time.h>
#include "Button.h"
#include "Image.h"
#include <functional>
#include "PreviousButton.h"


SelectionScreen::SelectionScreen(SDL_Renderer* ren) : MenuScreen(ren)
{
	std::cout << "Made SelectionScreen" << std::endl;
	//Init buttons
	PreviousButton* previousButton = new PreviousButton(*ren, "", "assets/images/previous.bmp");
	previousButton->SetDimensions(100, 10, 75, 75);
	previousButton->SetLocation(100, 282);
	AddUIComponent(previousButton);

	Button* nextButton = new Button(*ren, "", "assets/images/next.png");
	nextButton->SetDimensions(100, 10, 75, 75);
	nextButton->SetLocation(1080, 282);
	AddUIComponent(nextButton);

	Button* selectButton = new Button(*ren, "Select character", "assets/images/select.bmp");
	selectButton->SetDimensions(100, 10, 250, 90);
	selectButton->SetLocation(500, 500);
	AddUIComponent(selectButton);

	//Add images to vector
	Image* image2 = new Image{ *ren, "assets/images/next.png" };
	image2->SetDimensions(200, 10, 250, 250);
	image2->SetLocation(500, 200);
	AddImage(*image2);

	Image* image3 = new Image{ *ren, "assets/images/previous.png" };
	image3->SetDimensions(200, 10, 250, 250);
	image3->SetLocation(500, 200);
	AddImage(*image3);

	//Testing
	currentImage = image2;
	AddUIComponent(currentImage);
	Previous();
	Previous();
}

void SelectionScreen::Next()
{
	currentImageIndex++;
	if (currentImageIndex >= images.capacity())
	{
		currentImageIndex = 0;
	}
	*currentImage = images.at(currentImageIndex);
}

void SelectionScreen::Previous()
{
	std::cout << images.capacity() << std::endl;
	currentImageIndex--;
	if (currentImageIndex < 0)
	{
		currentImageIndex = images.capacity() - 1;
	}
	std::cout << "ImageIndex: " << currentImageIndex << std::endl;
	*currentImage = images.at(currentImageIndex);
}

void SelectionScreen::AddImage(Image img)
{
	images.push_back(img);
}

SelectionScreen::~SelectionScreen()
{

}