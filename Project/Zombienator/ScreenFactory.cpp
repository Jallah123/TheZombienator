#include "ScreenFactory.h"
#include "HomeScreen.h"
#include "LoadingScreen.h"
#include "SelectionScreen.h"
#include "MenuScreen.h"
#include "GameScreen.h"

std::map<ScreenEnum, std::function<AbstractScreen*(void)>> fillMap()
{
	std::map<ScreenEnum, std::function<AbstractScreen*(void)>> map;
	map[ScreenEnum::HOMESCREEN] = [](void) -> AbstractScreen * { return new HomeScreen{ Program::getInstance()->GetRenderer() }; };
	map[ScreenEnum::LOADINGSCREEN] = [](void) -> AbstractScreen * { return new LoadingScreen{ Program::getInstance()->GetRenderer() }; };
	map[ScreenEnum::SELECTIONSCREEN] = [](void) -> AbstractScreen * { return new SelectionScreen{ Program::getInstance()->GetRenderer() }; };
	return map;
}

std::map<ScreenEnum, std::function<AbstractScreen*(void)>> ScreenFactory::ScreenMap = fillMap();

AbstractScreen* ScreenFactory::Create(ScreenEnum screenEnum)
{
	AbstractScreen* screen = nullptr;
	if (screenEnum == ScreenEnum::GAMESCREEN)
	{
		screen = new GameScreen(Program::getInstance()->GetRenderer());
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