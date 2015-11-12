#include "Zombie.h"
#include "CharacterContainer.h"
#include <random>
#include <string>

using std::string;

Zombie::Zombie() : Character() {}


Zombie::~Zombie()
{
}


void Zombie::Init(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, ActionContainer* actionC, CollideContainer* collideC, CharacterContainer* characterC, SDL_Renderer* ren)
{
	//Zombie doesn't have input from the InputContainer
	std::random_device dev;
	std::default_random_engine dre{ dev() };
	std::uniform_int_distribution<int> dist{ 1, 6 };
	int dice_roll = dist(dre);

	string basePath = "assets/images/spritesheets/";
	string spriteSheet = std::to_string(dice_roll) + "zombie.png";

	SetImage(basePath+spriteSheet, *ren);
	this->SetContainers(drawC, animC, moveC, nullptr, nullptr, collideC, characterC);
	SetDrawBehaviour("CharacterDrawBehaviour");
	SetAnimateBehaviour("AnimateBehaviour");
	SetMoveBehaviour("AiMoveBehaviour");
	SetCollideBehaviour("CharacterCollideBehaviour");

	characterC->AddCharacter(this);
	
	SetSize(32, 36);
	SetFrames(3);
	SetSpeed(0.2f);
	SetHealth(50);
}