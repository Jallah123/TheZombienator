#pragma once
#include "AbstractScreen.h"
#include "ScreenEnum.cpp"
#include <map>
#include <functional>

class ScreenFactory
{
public:
	static AbstractScreen* ScreenFactory::Create(ScreenEnum screenEnum, string img_url = "");
private:
	static std::map<ScreenEnum, std::function<AbstractScreen*(void)>> ScreenMap;
};

