#pragma once
#include "GameScreen.h"
#include <iostream>
#include "Mike.h"
#include "Zombie.h"
#include "GameObjectFactory.h"
#include "AnimateContainer.h"
#include "DrawContainer.h"
#include "MoveContainer.h"
#include "ActionContainer.h"
#include "CharacterContainer.h"
#include "CollideContainer.h"
#include <SDL_mixer.h>
#include "SpawnController.h"

Mike* mike = nullptr;
DrawContainer drawContainer;
AnimateContainer animateContainer;
ActionContainer actionContainer;
MoveContainer moveContainer;
CollideContainer collideContainer;
CharacterContainer characterContainer;
SpawnController* spawnController;

GameScreen::GameScreen(SDL_Renderer* ren, string path) : AbstractScreen(ren)
{
	MapParser* mp{};
	map = mp->ParseJsonMap(path);
	GameObjectFactory::Instance()->SetLevel( map.get() );
	GameObjectFactory::Instance()->SetContainers(
		&drawContainer, 
		&animateContainer, 
		&moveContainer, 
		&actionContainer, 
		&collideContainer, 
		&characterContainer, 
		ren
	);
	
	
	spawnController = new SpawnController(&drawContainer, &animateContainer, &moveContainer, &actionContainer, &collideContainer, &characterContainer);
	spawnController->AddLocation(640, 100);
	spawnController->AddLocation(1280, 340);
	spawnController->AddLocation(640, 680);
	spawnController->AddLocation(0, 340);
	spawnController->SetRenderer(ren);

	mike = GameObjectFactory::Instance()->CreateMike();
	mike->SetPosition(800, 150);
	
	spawnController->AddTarget(mike);

	// --
	map.get()->setSprites(mp->GenerateSprites(path));
	SDL_Surface* s;
	s = IMG_Load(map->getImagePath().c_str());
	if (!s) {
		cout << "Error image load : " << IMG_GetError() << endl;
		return;
	}
	/*SDL_RenderCopy(&ren, BackgroundTexture, 0, 0);
	for (const auto& i : UIComponents)
		i->Draw(ren);*/
	//Load && play sound
	musicController->Load("assets/sounds/bgSound1.wav");
	musicController->Play(1, -1);
	musicController->SetVolume(25, 1);
	map.get()->setTexture(SDL_CreateTextureFromSurface(ren, s));
	SDL_FreeSurface(s);
}


void GameScreen::Update(float dt)
{
}

void GameScreen::Draw(SDL_Renderer& ren, float dt)
{
	vector<SDL_Rect*> sprites = map.get()->getSprites();
	vector<MapLayer> layers = map.get()->getLayers();
	vector<CollisionLayer> collisionLayers = map.get()->getCollisionLayers();

	for (int i = layers.size() - 1; i >= 0; i--)
	{
		for (int x = 0; x < 20; x++)
		{
			for (int y = 0; y < 40; y++)
			{
				DrawRect(x * 32, y * 32, sprites.at(layers.at(i).getGID(x, y)), &ren);
			}
		}
	}
	/*
	For debugging purposes only
	for (int j = collisionLayers.size() - 1; j >= 0; j--)
	{
		vector<CollisionObject> collisionObjects = collisionLayers[j].getCollisionObjects();

		for (int k = collisionObjects.size() - 1; k >= 0; k--)
		{
			 
			//DrawCollisionObject(collisionObjects[k].getY(), collisionObjects[k].getX(), collisionObjects[k].getWidth(), collisionObjects[k].getHeight(), &ren);
		}
	}
	*/
	spawnController->Update(dt);
	actionContainer.Update(dt);
	moveContainer.Move(dt);
	collideContainer.Collide(dt);
	animateContainer.Animate(dt);
	drawContainer.Draw(dt, ren);

	/* For debugging purposes only */
	//SDL_SetRenderDrawColor(&ren, 0xFF, 0x00, 0x00, 0xFF);
	//SDL_Rect rectangle = { 80, 80, 50, 50 };
	//SDL_RenderDrawRect(&ren, &rectangle);

	//cout << "checkCollision() : " << map->checkCollision(80, 80, 50, 50) << endl;
}

GameScreen::~GameScreen()
{
	delete spawnController;
}

void GameScreen::DrawRect(int x, int y, SDL_Rect* clip, SDL_Renderer* ren) {
	//Set rendering space and render to screen 
	SDL_Rect renderQuad = { y, x, 32, 32 };
	//Set clip rendering dimensions 
	if (clip != NULL) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	//Render to screen 
	SDL_RenderCopy(ren, map.get()->getTexture(), clip, &renderQuad);
}

/* For debugging purposes only */
void GameScreen::DrawCollisionObject(int x, int y, int width, int height, SDL_Renderer* ren) {
	//Set rendering space and render to screen 
	SDL_Rect rectangle = { y, x, width, height };
	//Render to screen
	SDL_RenderDrawRect(ren, &rectangle);
}