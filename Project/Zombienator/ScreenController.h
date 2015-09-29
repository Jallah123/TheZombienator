#pragma once
#include <stack> 
#include "MenuScreen.h"

class ScreenController
{
public:
	static ScreenController& GetInstance() {
		static ScreenController instance;
		return instance;
	}
	void ChangeMenu(MenuScreen NewMenu);
	void Back();
	std::stack<MenuScreen> GetMenuStack() { return MenuStack; };
	MenuScreen GetCurrentMenu() { return MenuStack.top(); };
private:
	ScreenController() {};
	~ScreenController() {};
	ScreenController(ScreenController const&) = delete;
	void operator=(ScreenController const&) = delete;
	std::stack<MenuScreen> MenuStack;
};





