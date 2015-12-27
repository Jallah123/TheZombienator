#pragma once
#include <stack> 

using namespace std;

class AbstractScreen;
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
	void PopLatestScreen() { AbstractScreen* screen = screenStack.top();  screenStack.pop(); delete screen; };
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





