#include "InputContainer.h"

bool InputContainer::GetKeyState(char c)
{
	if (!KeyExists(c)) return false;
	return keys[c];
}

bool InputContainer::KeyExists(char c)
{
	return keys.count(c) == 1;
}
