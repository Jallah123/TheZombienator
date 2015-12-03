#include "ScreenFactory.h"
#include "HomeScreen.h"
#include "LoadingScreen.h"
#include "WinScreen.h"
#include "SelectionScreen.h"
#include "MenuScreen.h"
#include "GameScreen.h"
#include "GameOverScreen.h"

std::map<ScreenEnum, std::function<AbstractScreen*(void)>> fillMap()
{
	std::map<ScreenEnum, std::function<AbstractScreen*(void)>> map;
	map[ScreenEnum::HOMESCREEN] = [](void) -> AbstractScreen * { return new HomeScreen{ Program::getInstance()->GetRenderer() }; };
	map[ScreenEnum::LOADINGSCREEN] = [](void) -> AbstractScreen * { return new LoadingScreen{ Program::getInstance()->GetRenderer() }; };
	map[ScreenEnum::WINSCREEN] = [](void) -> AbstractScreen * { return new WinScreen{ Program::getInstance()->GetRenderer() }; };
	map[ScreenEnum::SELECTIONSCREEN] = [](void) -> AbstractScreen * { return new SelectionScreen{ Program::getInstance()->GetRenderer() }; };
	map[ScreenEnum::GAMEOVERSCREEN] = [](void) -> AbstractScreen * { return new GameOverScreen{ Program::getInstance()->GetRenderer() }; };
	return map;
}

std::map<ScreenEnum, std::function<AbstractScreen*(void)>> ScreenFactory::ScreenMap = fillMap();

AbstractScreen* ScreenFactory::Create(ScreenEnum screenEnum, string map, string img_url)
{
	AbstractScreen* screen = nullptr;
	if (screenEnum == ScreenEnum::GAMESCREEN && map != "" && img_url != "")
	{
		screen = new GameScreen(Program::getInstance()->GetRenderer(), map, img_url);
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