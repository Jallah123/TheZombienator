#include "GameObject.h"



GameObject::GameObject()
{
}

GameObject::GameObject(AnimateContainer & animC)
{
	animateContainer = &animC;
}


GameObject::~GameObject()
{
}
