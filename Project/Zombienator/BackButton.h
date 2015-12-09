#pragma once
#include "Button.h"
#include "AbstractScreen.h"
#include <functional>
class BackButton 
	: public Button
{
private:
	AbstractScreen* parentScreen = nullptr;
	std::function<void()> updateParent;
public:
	BackButton();
	BackButton(SDL_Renderer& ren, char* text, char* img_url);
	~BackButton();
	void setUpdateParentFunction(std::function<void()> func);
	virtual void ClickAction() override;
};
