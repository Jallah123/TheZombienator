#pragma once
#include "Map.h"
#include <SDL_render.h>
#include "AbstractScreen.h"
#include "MapParser.h"
#include "GameObjectFactory.h"
#include "SpawnController.h"
#include "AnimateContainer.h"
#include "DrawContainer.h"
#include "MoveContainer.h"
#include "ActionContainer.h"
#include "CharacterContainer.h"
#include "CollideContainer.h"

class Quadtree;

class GameScreen 
	: public AbstractScreen
{
public:
	GameScreen(SDL_Renderer* _ren, char* path);
	~GameScreen();

	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
	
	Quadtree* GetTree() { return this->tree; }
private:
	GameObjectFactory* goFactory = GameObjectFactory::Instance();
	
	DrawContainer drawContainer;
	AnimateContainer animateContainer;
	ActionContainer actionContainer;
	MoveContainer moveContainer;
	CollideContainer collideContainer;
	CharacterContainer characterContainer;

	SpawnController* spawnController = nullptr;
	
	Mike* mike = nullptr;
	Map* map = nullptr;
	Quadtree* tree = nullptr;
		
};