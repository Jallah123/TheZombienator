#pragma once
#include "ScreenEnum.cpp"
#include <map>
#include <functional>
#include <string>
#include <vector>

class AbstractScreen;
class ScreenFactory
{
public:
	static AbstractScreen* ScreenFactory::Create(ScreenEnum screenEnum);
	static AbstractScreen* ScreenFactory::CreateGameScreen(std::vector<std::string> characterUrls, std::string mapUrl = "");
private:
	static std::map<ScreenEnum, std::function<AbstractScreen*(void)>> ScreenMap;
};

