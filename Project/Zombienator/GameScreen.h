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
#include "GameObjectContainer.h"
#include "Settings.h"
#include "TextureFactory.h"
#include "CollideContainer.h"
#include "HudVisitor.h"
#include "Mike.h"

class Quadtree;
class GameScreen : public AbstractScreen
{
public:
	GameScreen();
	GameScreen(SDL_Renderer* _ren);
	~GameScreen();
	void Shake(float time, int intensity = 20);
	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
	void NextMap(SDL_Renderer* ren);
	void Transition(SDL_Renderer& ren);
	void NextMap(SDL_Renderer & ren);
	Quadtree* GetTree() { return this->tree; }
	bool IsGameOver() { return mike->IsDeath(); }
	InputContainer* inputContainer = &InputContainer::GetInstance();
	void EndMap();
private:
	float shake = 0;
	int shakeIntensity = 20;
	int XOffset = 0;
	int YOffset = 0;
	float speed = 1.0;
	GameObjectFactory* goFactory = GameObjectFactory::Instance();
	Settings* settings = &Settings::GetInstance();
	DrawContainer drawContainer;
	AnimateContainer animateContainer;
	ActionContainer actionContainer;
	MoveContainer moveContainer;
	CollideContainer collideContainer;
	GameObjectContainer gameObjectContainer;
	SpawnController spawnController;
	HudVisitor hudVisitor;
	
	
	Mike* mike = nullptr;
	Map* map = nullptr;
	Quadtree* tree = nullptr;
};