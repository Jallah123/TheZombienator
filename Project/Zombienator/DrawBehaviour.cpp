#include "DrawBehaviour.h"



DrawBehaviour::DrawBehaviour()
{
}


DrawBehaviour::~DrawBehaviour()
{
}

void DrawBehaviour::Draw(float dt, SDL_Renderer & ren)
{
	if (!this->gameObject) return;
	SDL_RenderCopy(&ren, this->gameObject->GetTexture(), &this->gameObject->GetSourceRect(), &this->gameObject->GetDestinationRect());
}

