#include "NumberUtility.h"
#include <random>

NumberUtility::NumberUtility()
{
}


NumberUtility::~NumberUtility()
{
}

int NumberUtility::RandomNumber(int min, int max) {

	std::random_device dev;
	std::default_random_engine dre{ dev() };
	std::uniform_int_distribution<int> dist{ min, max };

	return dist(dre);
}