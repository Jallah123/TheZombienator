#include "LoadSaveButton.h"
#include "TextureFactory.h"
#include "StringUtils.h"
#include "MapFactory.h"
#include "ScreenFactory.h"
#include <iostream>

LoadSaveButton::LoadSaveButton(SDL_Renderer& ren, char* text, char* img_url, int _loadSlot): Button(ren, text, img_url)
{
	SetSourceLocation(0, 238);
	SetSize(239, 97);
	SetDestLocation(515, 220 + (97 * _loadSlot));
	buttonText = TextureFactory::GenerateText(string(text), 24, destRect.x + (destRect.w / 2), destRect.y + (destRect.h / 2), FontEnum::CARTOON, { 248 ,248 ,255 });
	loadSlot = _loadSlot;
}

void LoadSaveButton::ClickAction()
{
	ifstream save("assets/saves/story" + to_string(loadSlot) + ".save");
	// If opening succeeded
	if (save)
	{
		// Load all maps in this vector
		vector<string> maps;
		char urls[512];
		save.getline(urls, 512);
		string s = urls;
		StringUtils::Split(s, ',', maps);
		vector<string> imageurl;
		imageurl.push_back(maps.front());
		// remove image url from map queue
		maps.erase(maps.begin());
		// Add maps to mapqueue and change to that queue
		MapFactory::GetInstance()->SetCustomQueue(maps);
		ScreenController::GetInstance().Back();
		ScreenController::GetInstance().ChangeScreen(ScreenFactory::CreateGameScreen(imageurl));
		save.close();
	}
	else {
		cout << "No save";
	}
}


LoadSaveButton::~LoadSaveButton()
{
}
