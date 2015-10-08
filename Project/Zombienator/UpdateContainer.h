#include "AbstractContainer.h"
#pragma once
class UpdateContainer : public AbstractContainer
{
public:
	UpdateContainer();
	~UpdateContainer();

	void Update(int dt);
};

