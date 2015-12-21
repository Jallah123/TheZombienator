#pragma once
class KeyBinding
{
public:
	KeyBinding(char __UP, char _LEFT, char _DOWN, char _RIGHT, char _SHOOT, char _PREVIOUSWEAPON, char _NEXTWEAPON) { UP = __UP; LEFT = _LEFT; DOWN = _DOWN; RIGHT = _RIGHT; SHOOT = _SHOOT; PREVIOUSWEAPON = _PREVIOUSWEAPON; NEXTWEAPON = _NEXTWEAPON; };
	char UP;
	char LEFT;
	char DOWN;
	char RIGHT;
	char SHOOT;
	char PREVIOUSWEAPON;
	char NEXTWEAPON;
};

