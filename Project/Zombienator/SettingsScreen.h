#pragma once
#include "MenuScreen.h"
#include "TextureFactory.h"
#include "BackButton.h"
#include "Label.h"
#include "SwitchButton.h"
#include <functional>

using namespace std;
class SettingsScreen :
	public MenuScreen
{
protected:
	bool friendlyFire = false;
	bool sound = true;
	bool music = true;
	void initCompontents(SDL_Renderer &ren);
	
public:
	SettingsScreen(SDL_Renderer* ren);
	SettingsScreen();
	~SettingsScreen();
	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;

	bool getFiendlyFire() { return friendlyFire; };
	void setFriendlyFire(bool value) { friendlyFire = value; };

	bool getSound() { return sound; };
	void setSound(bool value) { sound = value; };

	bool getMusic() { return music; };
	void setMusic(bool value) { music = value; };

};

