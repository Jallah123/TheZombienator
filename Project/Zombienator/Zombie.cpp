#include "Zombie.h"
#include "CharacterContainer.h"
#include "ZombieStateFactory.h"
#include "ZombieAttackState.h"
#include "NumberUtility.h"
#include <string>
#include "TextureFactory.h"

using std::string;

Zombie::Zombie() : Character() 
{
	SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::STANDSTILL, this));
}

Zombie::~Zombie() {}

void Zombie::Init(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, ActionContainer* actionC, CollideContainer* collideC, CharacterContainer* characterC, SDL_Renderer* ren)
{
	//Zombie doesn't have input from the InputContainer	
	int dice_roll = NumberUtility::RandomNumber(1, 6);

	string basePath = "assets/images/spritesheets/";
	string baseAttackPath = "assets/images/spritesheets/attack/";
	string spriteSheet = std::to_string(dice_roll) + "zombie.png";

	SetImage(basePath + spriteSheet, *ren);
	SetNormalTexture(basePath + spriteSheet);
	SetAttackTexture(baseAttackPath + spriteSheet);
	this->SetContainers(drawC, animC, moveC, nullptr, nullptr, collideC, characterC);
	SetDrawBehaviour("CharacterDrawBehaviour");
	SetAnimateBehaviour("AnimateBehaviour");
	SetMoveBehaviour("AiMoveBehaviour");
	SetCollideBehaviour("CharacterCollideBehaviour");

	characterC->AddCharacter(this);

	SetSize(32, 36);
	SetFrames(3);
	SetSpeed(0.2f);
	SetMaxHealth(50);
	SetHealth(50);

	// -- Zombie Attack
	SetAttackDamage(1);
	SetAttackSpeed(2);
	SetSoundSpeed(4);
}

void Zombie::SetCurrentState(ZombieState* newState)
{	
	if(this->currentState != newState)
	{
		if (dynamic_cast<ZombieAttackState*>(newState))
			ChangeTexture(true);
		else
			ChangeTexture(false);
	}
	this->currentState = newState;
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

void Zombie::SetNormalTexture(string path)
{
	normalTexture = TextureFactory::GenerateTextureFromImgUrl(path);
}

void Zombie::SetAttackTexture(string path)
{
	AttackTexture = TextureFactory::GenerateTextureFromImgUrl(path);
}

void Zombie::ChangeTexture(bool isAttack)
{
	if (isAttack)
		SetTexture(this->AttackTexture);
	else
		SetTexture(this->normalTexture);
}
