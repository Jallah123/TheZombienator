#include "MenuScreen.h"
#include "Character.h"
//#include "GameObjectRegistrar.h"
#include "GameObjectFactory.h"
#include "AnimateContainer.h"
#include "iostream"

SDL_Texture* texture = nullptr;
Character* c = nullptr;
DrawContainer drawContainer;
AnimateContainer animateContainer;

MenuScreen::MenuScreen(SDL_Renderer* ren)
{
	GameObjectFactory::Instance()->Register("character", [](void) -> GameObject* {return new Character(); });
	c = GameObjectFactory::Instance()->CreateCharacter("character");
	c->SetContainers(&drawContainer, &animateContainer);
	c->SetDrawBehaviour("DrawBehaviour");
	c->SetImage("assets/images/spritesheets/Boy1.png", *ren);

	SDL_Surface * image = IMG_Load("assets/images/spritesheets/Boy1.png");
	texture = SDL_CreateTextureFromSurface(ren, image);

	std::cout << "Adress of character " << &c << std::endl;
	//c->SetSize(40, 40);
	//c->SetPosition(200, 100);
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
{	//Draw background
	SDL_RenderCopy(&ren, BackgroundTexture, 0, 0);

	std::vector<AbstractUIComponent*>::iterator it;
	for (it = UIComponents.begin(); it != UIComponents.end(); it++) (*it)->Draw(ren);

	//Draw GameObjects
	float dt = 1;
	drawContainer.Draw(dt, ren);
	
	//static Registrar<Character> GameObjectRegistrar("name");
	
	Uint32 ticks = SDL_GetTicks();
	const int FRAMES = 3;
	Uint32 sprite = (ticks / 100) % FRAMES;
	int width = 40;
	int height = 40;
	SDL_Rect srcrect = { sprite * width, 0, width, height };
	SDL_Rect dstrect = { 10, 10, width, height };

	SDL_RenderCopy(&ren, texture, &srcrect, &dstrect);
}

void MenuScreen::ChangeBackground(SDL_Renderer* ren, std::string img_url)
{
	char tab2[1024];
	SDL_Surface *s = IMG_Load(strcpy(tab2, img_url.c_str()));
	BackgroundTexture = SDL_CreateTextureFromSurface(ren, s);
}
