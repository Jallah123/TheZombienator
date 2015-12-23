#pragma once
class KeyBinding
{
public:
	KeyBinding(SDL_Keycode __UP, SDL_Keycode _LEFT, SDL_Keycode _DOWN, SDL_Keycode _RIGHT, SDL_Keycode _SHOOT, SDL_Keycode _PREVIOUSWEAPON, SDL_Keycode _NEXTWEAPON) { UP = __UP; LEFT = _LEFT; DOWN = _DOWN; RIGHT = _RIGHT; SHOOT = _SHOOT; PREVIOUSWEAPON = _PREVIOUSWEAPON; NEXTWEAPON = _NEXTWEAPON; };
	SDL_Keycode UP;
	SDL_Keycode LEFT;
	SDL_Keycode DOWN;
	SDL_Keycode RIGHT;
	SDL_Keycode SHOOT;
	SDL_Keycode PREVIOUSWEAPON;
	SDL_Keycode NEXTWEAPON;
};

