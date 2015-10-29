#include "BulletFactory.h"
#include "Bullet.h"
#include "NormalBullet.h"
//
// DO NOT FORGET TO INITIALIZE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
std::map<std::string, std::function<Bullet*(void)>> BulletFactory::registry;


BulletFactory::BulletFactory()
{
}


BulletFactory::~BulletFactory()
{
}

Bullet * BulletFactory::Find(std::string name)
{
	Bullet* instance = nullptr;
	auto it = BulletFactory::registry.find(name);
	if (it != BulletFactory::registry.end())
		instance = it->second();
	if (instance != nullptr) return instance;
	return nullptr;
}

void BulletFactory::Register(std::string name, std::function<Bullet*(void)> fn)
{
	Bullet* instance = BulletFactory::Find(name);
	if(instance == nullptr)
		BulletFactory::registry[name] = fn;
}

NormalBullet * BulletFactory::CreateNormalBullet(PlayableCharacter * obj)
{
	Bullet* instance = BulletFactory::Find("bullet");

	if (instance != nullptr) {
		NormalBullet* cInstance = dynamic_cast<NormalBullet*>(instance);
		cInstance->SetOrigin(obj);//link the behaviour to its gameObject
		return cInstance;
	}

	return nullptr;
}
