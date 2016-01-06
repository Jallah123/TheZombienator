#include "CharacterDrawBehaviour.h"
#include "Character.h"

CharacterDrawBehaviour::CharacterDrawBehaviour()
{
}


CharacterDrawBehaviour::~CharacterDrawBehaviour()
{
}

void CharacterDrawBehaviour::Draw(float dt, SDL_Renderer & ren, int XOffset, int YOffset)
{

	if (!this->gameObject) return;
	//Do casting here:
	Character* c = dynamic_cast<Character*>(gameObject);
	SDL_Rect Destination = *c->GetDestinationRect();
	Destination.x -= XOffset;
	Destination.y -= YOffset;
	SDL_RenderCopy(&ren, c->GetTexture(), c->GetSourceRect(), &Destination);
	
	double healthPercentage = (double)c->GetHealth() / (double)c->GetMaxHealth();
	if (healthPercentage != 1 && ! c->IsDeath()) {
		// Black bar around actual health bar
		int healthSize = (36 * healthPercentage);
		SDL_Rect healthBarSurround{ Destination.x - 1, Destination.y - 11, 38, 7 };
		// Black
		SDL_SetRenderDrawColor(&ren, 0, 0, 0, 255);
		SDL_RenderFillRect(&ren, &healthBarSurround);

		SDL_Rect damageBar{ Destination.x, Destination.y - 10, 36, 5 };
		// Red
		SDL_SetRenderDrawColor(&ren, 255, 0, 0, 255);
		SDL_RenderFillRect(&ren, &damageBar);

		// Actual health bar
		SDL_Rect healthBar{ Destination.x, Destination.y - 10, healthSize, 5 };
		// Green
		SDL_SetRenderDrawColor(&ren, 0, 255, 0, 255);
		SDL_RenderFillRect(&ren, &healthBar);
	}

	/*==== Draw Collision && Dest Rectangle
	
	SDL_SetRenderDrawColor(&ren, 0, 0, 255, 255);
	SDL_RenderFillRect(&ren, c->GetDestinationRect());
	SDL_SetRenderDrawColor(&ren, 255, 0, 0, 255);
	SDL_RenderFillRect(&ren, c->GetCollideRect());
	
	*/
}
