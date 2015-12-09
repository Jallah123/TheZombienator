#pragma once
#include "AbstractScreen.h"
#include "ScreenEnum.cpp"
#include <map>
#include <functional>

class ScreenFactory
{
public:
	static AbstractScreen* ScreenFactory::Create(ScreenEnum screenEnum);
	static AbstractScreen* ScreenFactory::CreateGameScreen(string characterUrl = "assets/images/spritesheets/Boy1.png", string mapUrl = "");
private:
	static std::map<ScreenEnum, std::function<AbstractScreen*(void)>> ScreenMap;
};

