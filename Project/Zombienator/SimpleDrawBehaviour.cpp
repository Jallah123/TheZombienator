#include "SimpleDrawBehaviour.h"
#include "GameObject.h"


SimpleDrawBehaviour::SimpleDrawBehaviour()
{
}


SimpleDrawBehaviour::~SimpleDrawBehaviour()
{
}

void SimpleDrawBehaviour::Draw(float dt, SDL_Renderer & ren, int XOffset, int YOffset)
{
	if (gameObject == nullptr) return;

	SDL_Rect& dest = *gameObject->GetDestinationRect();
	dest.x -= XOffset;
	dest.y -= YOffset;
	SDL_RenderCopy(&ren, gameObject->GetTexture(), gameObject->GetSourceRect(), &dest);
}
