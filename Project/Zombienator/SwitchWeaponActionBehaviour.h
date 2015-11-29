#pragma once
#include "ActionBehaviour.h"
class SwitchWeaponActionBehaviour :
	public ActionBehaviour
{
private:
	bool isPressed = false;
	char actionBackward;
public:
	SwitchWeaponActionBehaviour();
	~SwitchWeaponActionBehaviour();

	virtual void Update(float dt) override;

};

