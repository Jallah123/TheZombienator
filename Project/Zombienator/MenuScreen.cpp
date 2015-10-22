#include "MenuScreen.h"
#include "Character.h"
#include "GameObjectFactory.h"
#include "AnimateContainer.h"
#include "MoveContainer.h"
#include "iostream"

SDL_Texture* texture = nullptr;
Character* c = nullptr;
DrawContainer drawContainer;
AnimateContainer animateContainer;
MoveContainer moveContainer;

MenuScreen::MenuScreen(SDL_Renderer* ren) : AbstractScreen(ren)
{
	GameObjectFactory::Instance()->Register("character", [](void) -> GameObject* {return new Character(); });
	c = GameObjectFactory::Instance()->CreateCharacter("character");
	c->SetContainers(&drawContainer, &animateContainer, &moveContainer);
	c->SetDrawBehaviour("DrawBehaviour");
	c->SetAnimateBehaviour("AnimateBehaviour");
	c->SetMoveBehaviour("MoveBehaviour");
	c->SetImage("assets/images/spritesheets/Boy1.png", *ren);
	c->SetSize(40, 40);
	c->SetPosition(200, 100);
	c->SetFrames(3);
	SDL_Surface * image = IMG_Load("assets/images/spritesheets/Boy1.png");
	texture = SDL_CreateTextureFromSurface(ren, image);

	std::cout << "Adress of character " << &c << std::endl;

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

void MenuScreen::Draw(SDL_Renderer& ren, float dt)
{	// Draw background
	SDL_RenderCopy(&ren, BackgroundTexture, 0, 0);

	std::vector<AbstractUIComponent*>::iterator it;
	for (it = UIComponents.begin(); it != UIComponents.end(); it++) (*it)->Draw(ren);

	// Deltatime

	// Draw GameObjects
	animateContainer.Animate(dt);
	drawContainer.Draw(dt, ren);
	moveContainer.Move(dt);
}

void MenuScreen::ChangeBackground(SDL_Renderer* ren, std::string img_url)
{
	char tab2[1024];
	SDL_Surface *s = IMG_Load(strcpy(tab2, img_url.c_str()));
	BackgroundTexture = SDL_CreateTextureFromSurface(ren, s);
}
