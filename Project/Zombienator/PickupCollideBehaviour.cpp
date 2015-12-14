#include "PickupCollideBehaviour.h"
#include "Pickup.h"
#include "PlayableCharacter.h"
#include "GameObjectContainer.h"


PickupCollideBehaviour::PickupCollideBehaviour() : CollideBehaviour()
{
}


PickupCollideBehaviour::~PickupCollideBehaviour()
{
}

void PickupCollideBehaviour::Collide(float dt)
{
	if (!this->gameObject) return;
	Pickup* kit = dynamic_cast<Pickup*>(this->gameObject);
	GameObjectContainer* goc = kit->GetGameObjectContainer();


	std::vector<GameObject*> gameObjects = goc->GetCollideableObjects();
	for (auto& g : gameObjects)
	{
		if (PlayableCharacter* pc = dynamic_cast<PlayableCharacter*>(g)) {
			if (SDL_HasIntersection(kit->GetDestinationRect(), pc->GetDestinationRect())) {
				kit->DoAction(pc);
				kit->Remove();
			}
		}
	}
}
