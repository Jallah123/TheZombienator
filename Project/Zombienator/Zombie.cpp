#include "Zombie.h"
#include "GameObjectContainer.h"
#include "ZombieStateFactory.h"
#include "NumberUtility.h"
#include <string>

using std::string;

Zombie::Zombie() : Character() 
{
	SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::STANDSTILL, this));
}


Zombie::~Zombie()
{
}


void Zombie::Init(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, ActionContainer* actionC, CollideContainer* collideC, GameObjectContainer* gameObjectC, SDL_Renderer* ren)
{
	//Zombie doesn't have input from the InputContainer	
	int dice_roll = NumberUtility::RandomNumber(1, 6);

	string basePath = "assets/images/spritesheets/";
	string spriteSheet = std::to_string(dice_roll) + "zombie.png";

	SetImage(basePath+spriteSheet, *ren);
	this->SetContainers(drawC, animC, moveC, nullptr, nullptr, collideC, gameObjectC);
	SetDrawBehaviour("CharacterDrawBehaviour");
	SetAnimateBehaviour("AnimateBehaviour");
	SetMoveBehaviour("AiMoveBehaviour");
	SetCollideBehaviour("CharacterCollideBehaviour");

	gameObjectC->AddGameObject(this);
	
	SetSize(32, 36);
	SetFrames(3);
	SetSpeed(0.2f);
	SetMaxHealth(50);
	SetHealth(50);
}

bool Zombie::IsInAttackRadius(Character * target)
{
	SDL_Rect* targetRadius = target->GetDestinationRect();
	targetRadius->h += 2;
	targetRadius->w += 2;
	targetRadius->x -= 1;
	targetRadius->y -= 1;
	if (SDL_HasIntersection(GetDestinationRect(),targetRadius)) 
	{
		return true;
	}
	return false;
}
