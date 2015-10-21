#pragma once
#include <stack> 
#include "AbstractScreen.h"
#include <memory>

using namespace std;

class ScreenController
{
public:
	static ScreenController& GetInstance() {
		static ScreenController instance;
		return instance;
	}
	void ChangeMenu(AbstractScreen* NewMenu);
	void Back();
	std::stack<AbstractScreen*> GetMenuStack() { return MenuStack; };
	AbstractScreen* GetCurrentMenu() { return MenuStack.top(); };
	int Size();
private:
	ScreenController() {};
	~ScreenController() {};
	ScreenController(ScreenController const&) = delete;
	void operator=(ScreenController const&) = delete;
	stack<AbstractScreen*> MenuStack;
};





