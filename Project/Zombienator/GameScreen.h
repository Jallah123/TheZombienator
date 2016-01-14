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
#include "GameState.h"
#include "HudVisitor.h"
#include "BubbleVisitor.h"
#include "TutorialController.h"
#include "PauseScreen.h"
#include "PlayableCharacter.h"
#include "GameTypeEnum.cpp"

class Quadtree;
class GameScreen 
	: public AbstractScreen
{
public:
	GameScreen();
	GameScreen(SDL_Renderer* _ren, vector<string> characterImageUrls, string mapUrl = "");
	~GameScreen();
	void Shake(float time, int intensity = 20);
	virtual void Update(float dt) override;
	virtual void ReceiveFocus() override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
	void NextMap(SDL_Renderer* ren);
	bool Transition(SDL_Renderer& ren);
	void NextMap(SDL_Renderer & ren);
	Quadtree* GetTree() { return this->tree; }
	bool IsGameOver();
	InputContainer* inputContainer = &InputContainer::GetInstance();
	void EndMap();

	GameType& GetGameType() { return gameType; }
private:
	GameType gameType = GameType::STORY_MODE;
	void ShakeScreen(float dt);
	void UpdateZombies(float dt);
	void SetZombieTargets();
	void RemoveDeadPlayers();
	vector<KeyBinding*> defaultKeybindings;
	vector<string> characterImageUrls;
	float shake = 0;
	int shakeIntensity = 20;
	int XOffset = 0;
	int YOffset = 0;
	int stateChangeDelay = 50;
	int timeLastStateChange = 0;
	bool inTransistion = false;
	int cheatDelay = 50;
	int timeCheatActivated = 0;
	GameState currentState = GameState::INIT;
	Settings* settings = &Settings::GetInstance();
	GameObjectFactory* goFactory = GameObjectFactory::Instance();

	void HandleInput(float dt);
	
	DrawContainer drawContainer;
	AnimateContainer animateContainer;
	ActionContainer actionContainer;
	MoveContainer moveContainer;
	CollideContainer collideContainer;
	GameObjectContainer* gameObjectContainer;
	SpawnController spawnController;
	HudVisitor hudVisitor;
	BubbleVisitor bubbleVisitor;
	TutorialController tutorialController;
	
	vector<PlayableCharacter*> players;
	Map* map = nullptr;
	Quadtree* tree = nullptr;
};