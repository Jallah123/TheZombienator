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
	void ChangeScreen(AbstractScreen* screen);
	void Back();
	void EmptyStack();
	std::stack<AbstractScreen*> GetScreenStack() { return screenStack; };
	AbstractScreen* GetCurrentScreen() { return screenStack.top(); };
	void PopLatestScreen() { screenStack.pop(); };
	AbstractScreen* GetLoadingScreen() { return loadingScreen; };
	void AddLoadingScreen(AbstractScreen* s) { loadingScreen = s; };
	int Size();
private:
	ScreenController() {};
	~ScreenController() { delete loadingScreen; };
	ScreenController(ScreenController const&) = delete;
	void operator=(ScreenController const&) = delete;
	stack<AbstractScreen*> screenStack;
	AbstractScreen* loadingScreen;
};





