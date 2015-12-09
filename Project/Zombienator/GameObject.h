#pragma once
#include "Direction.cpp"
#include <SDL_image.h>
#include <string>
#include <vector>

//Containers

class DrawContainer;
class AnimateContainer;
class MoveContainer;
class CollideContainer;
class ActionContainer;
class GameObjectContainer;
class InputContainer;

//Behaviours
class DrawBehaviour;
class AnimateBehaviour;
class MoveBehaviour;
class CollideBehaviour;
class ActionBehaviour;

using std::string;

class GameObject
{
protected:
	SDL_Texture* texture = nullptr;

	int width = 0, height = 0;
	float posY = 0.0f, posX = 0.0f;

	Direction moveDir = Direction::NONE;
	Direction lookDir = Direction::SOUTH;

	bool canMove = true;

	SDL_Rect sourceRect = { 0,0,0,0 },
		destRect = { 0,0,0,0 },
		collRect = { 0,0,0,0 };

	int animationFrames = 0;
	
	//Containers
	InputContainer* inputContainer = nullptr;
	ActionContainer* actionContainer = nullptr;
	AnimateContainer* animateContainer = nullptr;
	DrawContainer* drawContainer = nullptr;
	MoveContainer* moveContainer = nullptr;
	CollideContainer* collideContainer = nullptr;
	GameObjectContainer* gameObjectContainer = nullptr;

	//Behaviours
	DrawBehaviour* drawBehaviour = nullptr;
	AnimateBehaviour* animateBehaviour = nullptr;
	MoveBehaviour* moveBehaviour = nullptr;
	CollideBehaviour* collideBehaviour = nullptr;
	std::vector<ActionBehaviour*> actionBehaviours = {};

public:
	//=== Constructors
	GameObject();
	GameObject(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, CollideContainer* collideC, ActionContainer* actionC, GameObjectContainer* gameObjectC);
	virtual ~GameObject();


	//=== Texture
	SDL_Texture* const GetTexture() { return this->texture; }
	void SetTexture(SDL_Texture* t) { this->texture = t; }
	void SetImage(string path);

	int GetFrames() const { return animationFrames; }
	void SetFrames(int f) { animationFrames = f; }

	//=== Position && Dimensions
	float getPosY() { return posY; }
	float getPosX() { return posX; }

	int const GetHeight() { return this->height; }
	int const GetWidth() { return this->width; }

	void SetSize(int w, int h);
	void SetPosition(float x, float y);


	//=== Rectangles
	void SetSourceRect(SDL_Rect r) { sourceRect = r; }
	void SetDestinationRect(SDL_Rect r) { destRect = r; }

	SDL_Rect* GetSourceRect() { return &this->sourceRect; }
	SDL_Rect* GetDestinationRect() { return &this->destRect; }
	SDL_Rect* GetCollideRect() { return &this->collRect; }


	//=== Move Direction
	void SetMoveDir(Direction d) { if (moveDir != d) moveDir = d; }
	void SetLookDir(Direction d) { if (lookDir != d) lookDir = d; }

	Direction const GetMoveDir() { return this->moveDir; }
	Direction const GetLookDir() { return this->lookDir; }

	//=== Object is able to move
	bool CanMove() { return this->canMove; }
	void CanMove(bool c) { this->canMove = c; }


	//=== Containers
	void SetContainers(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, InputContainer* inputC, ActionContainer* actionC, CollideContainer* collideC, GameObjectContainer* gameObjectC);
	
	InputContainer* GetInputContainer() { return inputContainer; }
	GameObjectContainer* GetGameObjectContainer() { return this->gameObjectContainer; }


	//=== Behaviours
	void SetDrawBehaviour(string name);
	void SetAnimateBehaviour(string name);
	void SetMoveBehaviour(string name);
	void SetActionBehaviour(string name);
	void SetCollideBehaviour(string name);

	virtual void Remove();
};