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
#include "MapSelectionScreen.h"

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
	map[ScreenEnum::MAPSELECTIONSCREEN] = [](void) -> AbstractScreen * { return new MapSelectionScreen{ Program::getInstance()->GetRenderer() }; };

	return map;
}

std::map<ScreenEnum, std::function<AbstractScreen*(void)>> ScreenFactory::ScreenMap = fillMap();

AbstractScreen* ScreenFactory::Create(ScreenEnum screenEnum)
{
	AbstractScreen* screen = nullptr;

	auto it = ScreenMap.find(screenEnum);
	if (it != ScreenMap.end())
	{
		screen = it->second();
	}
	return screen;
}

AbstractScreen* ScreenFactory::CreateGameScreen(string characterUrl, string mapUrl)
{
	return new GameScreen(Program::getInstance()->GetRenderer(), characterUrl, mapUrl);
}