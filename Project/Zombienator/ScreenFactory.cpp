#include "ScreenFactory.h"
#include "HomeScreen.h"
#include "LoadingScreen.h"
#include "WinScreen.h"
#include "SelectionScreen.h"
#include "MenuScreen.h"
#include "GameScreen.h"
#include "HelpScreen.h"
#include "GameOverScreen.h"
#include "CreditScreen.h"
#include "PauseScreen.h"
#include "SettingsScreen.h"

std::map<ScreenEnum, std::function<AbstractScreen*(void)>> fillMap()
{
	std::map<ScreenEnum, std::function<AbstractScreen*(void)>> map;
	map[ScreenEnum::HOMESCREEN] = [](void) -> AbstractScreen * { return new HomeScreen{ Program::getInstance()->GetRenderer() }; };
	map[ScreenEnum::LOADINGSCREEN] = [](void) -> AbstractScreen * { return new LoadingScreen{ Program::getInstance()->GetRenderer() }; };
	map[ScreenEnum::WINSCREEN] = [](void) -> AbstractScreen * { return new WinScreen{ Program::getInstance()->GetRenderer() }; };
	map[ScreenEnum::SELECTIONSCREEN] = [](void) -> AbstractScreen * { return new SelectionScreen{ Program::getInstance()->GetRenderer() }; };
	map[ScreenEnum::HELPSCREEN] = [](void) -> AbstractScreen * { return new HelpScreen{ Program::getInstance()->GetRenderer() }; };
	map[ScreenEnum::GAMEOVERSCREEN] = [](void) -> AbstractScreen * { return new GameOverScreen{ Program::getInstance()->GetRenderer() }; };
	map[ScreenEnum::CREDITSCREEN] = [](void) -> AbstractScreen * { return new CreditScreen{ Program::getInstance()->GetRenderer() }; };
	map[ScreenEnum::PAUSESCREEN] = [](void) -> AbstractScreen * { return new PauseScreen{ Program::getInstance()->GetRenderer() }; };
	map[ScreenEnum::SETTINGSSCREEN] = [](void) -> AbstractScreen * { return new SettingsScreen{ Program::getInstance()->GetRenderer() }; };

	return map;
}

std::map<ScreenEnum, std::function<AbstractScreen*(void)>> ScreenFactory::ScreenMap = fillMap();
AbstractScreen* ScreenFactory::Create(ScreenEnum screenEnum, string play1_img_url, string play2_img_url)
{
	static string play1ImgUrl = "";
	static string play2ImgUrl = "";
	AbstractScreen* screen = nullptr;
	if (play1_img_url != "") {
		play1ImgUrl = play1_img_url;
	}
	if (play2_img_url != "") {
		play2ImgUrl = play2_img_url;
	}
	if (screenEnum == ScreenEnum::GAMESCREEN)
	{
		screen = new GameScreen(Program::getInstance()->GetRenderer(), play1ImgUrl, play2ImgUrl);
	}
	else {
		auto it = ScreenMap.find(screenEnum);
		if (it != ScreenMap.end())
		{
			screen = it->second();
		}
	}
	return screen;
}