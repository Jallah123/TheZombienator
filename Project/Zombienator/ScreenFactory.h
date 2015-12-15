#pragma once
#include "ScreenEnum.cpp"
#include <map>
#include <functional>
#include <string>

class AbstractScreen;
class ScreenFactory
{
public:
	static AbstractScreen* ScreenFactory::Create(ScreenEnum screenEnum);
	static AbstractScreen* ScreenFactory::CreateGameScreen(std::string characterUrl = "assets/images/spritesheets/Boy1.png", std::string mapUrl = "");
private:
	static std::map<ScreenEnum, std::function<AbstractScreen*(void)>> ScreenMap;
};

