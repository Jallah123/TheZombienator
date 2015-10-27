#ifndef BULLET_FACTORY
#define BULLET_FACTORY
#pragma once
#include <map>
#include <functional>

class NormalBullet;
class Bullet;
class PlayableCharacter;

class BulletFactory
{
private:
	BulletFactory();

public:
	~BulletFactory();
	static std::map<std::string, std::function<Bullet*(void)>> registry;


	static BulletFactory* Instance() {//Singleton
		static BulletFactory f;
		return &f;
	}
	static Bullet* Find(std::string name);

	static void Register(std::string name, std::function<Bullet*(void)> fn);
	static NormalBullet* CreateNormalBullet(PlayableCharacter* obj);


};
#endif
