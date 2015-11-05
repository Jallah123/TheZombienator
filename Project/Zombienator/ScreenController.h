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
	void ChangeMenu(AbstractScreen* screen);
	void Back();
	std::stack<AbstractScreen*> GetMenuStack() { return screenStack; };
	AbstractScreen* GetCurrentScreen() { return screenStack.top(); };
	int Size();
private:
	ScreenController() {};
	~ScreenController() {};
	ScreenController(ScreenController const&) = delete;
	void operator=(ScreenController const&) = delete;
	stack<AbstractScreen*> screenStack;
};





