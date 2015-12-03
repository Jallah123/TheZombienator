#include "AbstractContainer.h"



AbstractContainer::AbstractContainer()
{
}


AbstractContainer::~AbstractContainer()
{
	std::vector<Behaviour*>::reverse_iterator it;
	/*for (it = arr.rbegin(); it != arr.rend(); ++it)
		delete *it;*/

	arr.clear();

	for (it = arrRemove.rbegin(); it != arrRemove.rend(); ++it)
		delete *it;

	arrRemove.clear();
}
