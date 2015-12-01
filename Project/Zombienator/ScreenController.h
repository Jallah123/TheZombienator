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
	std::stack<AbstractScreen*> GetScreenStack() { return screenStack; };
	AbstractScreen* GetCurrentScreen() { return screenStack.top(); };
	AbstractScreen* GetLoadingScreen() { return loadingScreen; };
	AbstractScreen* GetGameOverScreen() { return gameoverScreen; };
	void AddLoadingScreen(AbstractScreen* s) { loadingScreen = s; };
	void AddGameOverScreen(AbstractScreen* s) { gameoverScreen = s; };
	int Size();
private:
	ScreenController() {};
	~ScreenController() {};
	ScreenController(ScreenController const&) = delete;
	void operator=(ScreenController const&) = delete;
	stack<AbstractScreen*> screenStack;
	AbstractScreen* loadingScreen;
	AbstractScreen* gameoverScreen;
};





