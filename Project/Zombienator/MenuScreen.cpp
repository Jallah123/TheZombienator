#include "MenuScreen.h"
#include "Character.h"
//#include "GameObjectRegistrar.h"
#include "GameObjectFactory.h"
#include "iostream"

MenuScreen::MenuScreen(SDL_Renderer* ren)
{
	SDL_Surface *s = IMG_Load("assets/images/menu_bg.png");
	BackgroundTexture = SDL_CreateTextureFromSurface(ren, s);
}

void MenuScreen::AddUIComponent(AbstractUIComponent* UIComponent)
{
	UIComponents.push_back(UIComponent);
}

void MenuScreen::ClickComponents(SDL_Point MousePosition)
{
	std::vector<AbstractUIComponent*>::iterator it;
	for (it = UIComponents.begin(); it != UIComponents.end(); it++) (*it)->OnClick(MousePosition);
}

void MenuScreen::Draw(SDL_Renderer& ren)
{
	SDL_RenderCopy(&ren, BackgroundTexture, 0, 0);

	std::vector<AbstractUIComponent*>::iterator it;
	for (it = UIComponents.begin(); it != UIComponents.end(); it++) (*it)->Draw(ren);

	Character* c = new Character();
	c->SetImage("assets/images/spritesheets/Boy1.png", ren);
	c->SetSize(40, 40);
	c->SetPosition(80, 80);

	//static GameObjectRegistrar<Character> GameObjectRegistrar("henk");

	//auto instance = GameObjectFactory::Instance()->Create("henk");

	GameObjectFactory::Instance()->Register("name", [](void) -> GameObject* {return new Character(); });

	SDL_Surface * image = IMG_Load("assets/images/spritesheets/Boy1.png");
	/*
	SDL_Texture * texture = SDL_CreateTextureFromSurface(&ren, image);
	Uint32 ticks = SDL_GetTicks();
	const int FRAMES = 3;
	Uint32 sprite = (ticks / 100) % FRAMES;
	int width = 40;
	int height = 40;
	SDL_Rect srcrect = { sprite * width, 0, width, height };
	SDL_Rect dstrect = { 10, 10, width, height };
	
	SDL_RenderCopy(&ren, texture, &srcrect, &dstrect);
	*/

}

void MenuScreen::ChangeBackground(SDL_Renderer* ren, std::string img_url)
{
	char tab2[1024];
	SDL_Surface *s = IMG_Load(strcpy(tab2, img_url.c_str()));
	BackgroundTexture = SDL_CreateTextureFromSurface(ren, s);
}
