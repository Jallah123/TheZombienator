#include "MapSelectionScreen.h"
#include "Map.h"
#include "DirectoryUtils.h"
#include "Label.h"
#include "Button.h"
#include "BackButton.h"
#include "ScreenFactory.h"
#include "SelectionScreen.h"
#include <iostream>

struct PreviousMapButton : Button {
	MapSelectionScreen* screen;

	PreviousMapButton(SDL_Renderer& ren, char* text, char* img_url, MapSelectionScreen* ss)
		: Button(ren, text, img_url) {
		screen = ss;
	}

	void ClickAction() {
		screen->setCurrentMapIndex(screen->getCurrentMapIndex() - 1);
		if (screen->getCurrentMapIndex() < 0)
		{
			screen->setCurrentMapIndex(screen->getAmountOfMaps() - 1);
		}
	}
};

struct NextMapButton : Button {
	MapSelectionScreen* screen;

	NextMapButton(SDL_Renderer& ren, char* text, char* img_url, MapSelectionScreen* ss)
		: Button(ren, text, img_url) {
		screen = ss;
	}

	void ClickAction() {
		screen->setCurrentMapIndex(screen->getCurrentMapIndex() + 1);
		if (screen->getCurrentMapIndex() >= screen->getAmountOfMaps())
		{
			screen->setCurrentMapIndex(0);
		}
	}
};


struct MapSelectButton : Button {
	MapSelectionScreen* screen;

	MapSelectButton(SDL_Renderer& ren, char* text, char* img_url, MapSelectionScreen* ss)
		: Button(ren, text, img_url) {
		screen = ss;
		SetSourceLocation(0, 238);
		SetSize(239, 97);
		SetDestLocation(500, 500);
		buttonText = TextureFactory::GenerateText(string(text), 24, destRect.x + (destRect.w / 2), destRect.y + (destRect.h / 2), FontEnum::CARTOON, { 248 ,248 ,255 });
	}

	void ClickAction() {
		string map = screen->getCurrentMap()->GetMapPath();
		ScreenController::GetInstance().Back();
		ScreenController::GetInstance().ChangeScreen(ScreenFactory::Create(ScreenEnum::SELECTIONSCREEN));
		SelectionScreen* currentScreen = static_cast<SelectionScreen*>(ScreenController::GetInstance().GetCurrentScreen());
		currentScreen->setMapUrl(map);
	}
};

MapSelectionScreen::MapSelectionScreen(SDL_Renderer* ren): MenuScreen(ren)
{
	vector<string> test = DirectoryUtils::getFilesFromDirectory("maps", "json", true);
	for (auto s : test)
	{
		Map* m = new Map{ s };
		maps.push_back(m);
	}

	char* ssUrl = "assets/images/button_spritesheet.png";

	Label* l = new Label{ *ren, "Select your map", 640, 50, 32, { 248, 248, 255 } };
	AddUIComponent(l);
	
	PreviousMapButton * pbtn = new PreviousMapButton{ *ren, "Previous", ssUrl, this };
	pbtn->SetSourceLocation(0, 0);
	pbtn->SetSize(83, 76);
	pbtn->SetDestLocation(100, 282);
	AddUIComponent(pbtn);

	NextMapButton * nbtn = new NextMapButton(*ren, "Next", ssUrl, this);
	nbtn->SetSourceLocation(86, 0);
	nbtn->SetSize(83, 76);
	nbtn->SetDestLocation(1080, 282);
	AddUIComponent(nbtn);

	MapSelectButton* sbtn = new MapSelectButton(*ren, "Select", ssUrl, this);
	AddUIComponent(sbtn);

	BackButton* b = new BackButton(*ren, "", "assets/images/button_spritesheet.png");
	AddUIComponent(b);
}

void MapSelectionScreen::Update(float dt)
{

}

void MapSelectionScreen::Draw(SDL_Renderer& ren, float dt)
{
	if (backgroundTexture != nullptr)
	{
		SDL_RenderCopy(&ren, backgroundTexture, 0, 0);
	}
	Map* currentMap = maps[currentMapIndex];
	// int x = 188, y = 100;
	int x = 0, y = 0;
	currentMap->Draw(ren, x, y);
	currentMap->DrawFrontLayer(ren, x, y);
	for each (const auto& component in UIComponents)
	{
		component->Draw(ren);
	}
}

MapSelectionScreen::~MapSelectionScreen()
{
	for (auto s : maps)
	{
		delete s;
	}
}
