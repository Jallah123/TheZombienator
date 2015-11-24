#pragma once
#include "Map.h"
#include <SDL_render.h>
#include "AbstractScreen.h"
#include "MapParser.h"
#include "GameObjectFactory.h"
#include "SpawnController.h"
#include "BehaviourFactory.h"
#include "AnimateContainer.h"
#include "DrawContainer.h"
#include "MoveContainer.h"
#include "ActionContainer.h"
#include "GameObjectContainer.h"
#include "CollideContainer.h"

class GameScreen 
	: public AbstractScreen
{
public:
	GameScreen();
	GameScreen(SDL_Renderer* _ren, char* path);
	~GameScreen();
	void Shake(float time, int intensity = 20);
	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
	void DrawMap(SDL_Renderer& ren);
private:
	float shake = 0;
	int shakeIntensity = 20;
	int XOffset = 0;
	int YOffset = 0;
	GameObjectFactory* goFactory = GameObjectFactory::Instance();
	
	DrawContainer drawContainer;
	AnimateContainer animateContainer;
	ActionContainer actionContainer;
	MoveContainer moveContainer;
	CollideContainer collideContainer;
	GameObjectContainer gameObjectContainer;
	SpawnController spawnController;
	
	Mike* mike = nullptr;
	Map* map = nullptr;

	float speed = 1.0;
	
	void DrawRect(int x, int y, SDL_Rect* clip, SDL_Renderer* ren);
	void DrawCollisionObject(int x, int y, int width, int height, SDL_Renderer* ren);
};