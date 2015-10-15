#include "DrawBehaviour.h"
#include "Character.h"
#include <iostream>


DrawBehaviour::DrawBehaviour()
{
}


DrawBehaviour::~DrawBehaviour()
{
}

void DrawBehaviour::Draw(float dt, SDL_Renderer & ren)
{
	if (!this->gameObject) return;
	//Do casting here:
	Character* c = (Character*) &this->gameObject;
	std::cout << "Draw behaviour draw " << &c << std::endl;
	if(c->GetTexture() != nullptr)
	SDL_RenderCopy(&ren, c->GetTexture(), &c->GetSourceRect(), &c->GetDestinationRect());
}

