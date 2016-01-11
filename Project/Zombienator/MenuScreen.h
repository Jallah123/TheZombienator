#pragma once
#include <vector>
#include "AbstractScreen.h"
#include "Button.h"
class InputContainer;

class MenuScreen 
	: public AbstractScreen
{
protected:
	InputContainer* inputContainer = nullptr;
	int selectedComponent = 0;
	float lastHandled = 50;
	SDL_Rect selectedRect{};
	bool previous = false;
	bool next = false;
	bool enter = false;
	vector<Button*> buttons;

public:
	MenuScreen();
	MenuScreen(SDL_Renderer* ren);	//Constructor
	virtual ~MenuScreen() {};		//Destructor

	void HandleKeyboardEvents(SDL_Renderer& ren, float dt);
	void InitializeButtons();

	virtual void Update(float dt) = 0;
	virtual void Draw(SDL_Renderer& ren, float dt) = 0;
};