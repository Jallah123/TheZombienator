#include "SelectionScreen.h"
#include <iostream>
#include <time.h>
#include "Button.h"
#include "Image.h"
#include <functional>


SelectionScreen::SelectionScreen(SDL_Renderer* ren) : MenuScreen(ren)
{
	std::cout << "Made SelectionScreen" << std::endl;

	Button* previousButton = new Button(*ren, "", "assets/images/previous.bmp");
	previousButton->SetDimensions(100, 10, 75, 75);
	previousButton->SetLocation(100, 282);
	AddUIComponent(previousButton);
	
	Button* nextButton = new Button(*ren, "", "assets/images/next.bmp");
	nextButton->SetDimensions(200, 10, 75, 75);
	nextButton->SetLocation(1080, 282);
	AddUIComponent(nextButton);

	Image* image = new Image(*ren, "assets/images/next.bmp");
	image->SetDimensions(200, 10, 250, 250);
	image->SetLocation(500, 200);
	AddImage(image);

	Image* image2 = new Image(*ren, "assets/images/previous.bmp");
	image2->SetDimensions(200, 10, 250, 250);
	image2->SetLocation(500, 200);
	AddImage(image2);

	Button* selectButton = new Button(*ren, "Select character", "assets/images/select.bmp");
	selectButton->SetDimensions(100, 10, 250, 90);
	selectButton->SetLocation(500, 500);
	AddUIComponent(selectButton);

	AddUIComponent(images.at(0));
}

void SelectionScreen::Next()
{
	currentImage++;
	if (currentImage >= images.capacity())
	{
		currentImage = 0;
	}
	AddUIComponent(images.at(currentImage));
}

void SelectionScreen::Previous()
{
	currentImage--;
	if (currentImage < 0)
	{
		currentImage = images.capacity() - 1;
	}
	AddUIComponent(images.at(currentImage));
}

void SelectionScreen::AddImage(Image* img)
{
	images.push_back(img);
}


SelectionScreen::~SelectionScreen()
{
}
