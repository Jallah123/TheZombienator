#include "GameObjectFactory.h"

#pragma once
template<class T>
class Registrar
{
public:
	Registrar(std::string className);
};
//http://www.codeproject.com/Articles/567242/AplusC-b-bplusObjectplusFactory
template<class T>
inline Registrar<T>::Registrar(std::string className)
{
	GameObjectFactory::Instance()->Register(className, [](void) -> GameObject * { return new T(); });
}
