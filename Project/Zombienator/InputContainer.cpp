#include "InputContainer.h"

bool InputContainer::GetKeyState(char c)
{
	if (!InputContainer::KeyExists(c)) return false;
	return keys[c];
}

bool InputContainer::KeyExists(char c)
{
	return InputContainer::keys.count(c) == 1;
}
