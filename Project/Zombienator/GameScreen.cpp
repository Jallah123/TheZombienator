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
#include "ContainerContainer.h"
#include <SDL_mixer.h>
#include "SpawnController.h"
Mike* mike = nullptr;
DrawContainer* drawContainer = ContainerContainer::GetInstance().GetDrawContainer();
AnimateContainer* animateContainer = ContainerContainer::GetInstance().GetAnimateContainer();
ActionContainer* actionContainer = ContainerContainer::GetInstance().GetActionContainer();
MoveContainer* moveContainer = ContainerContainer::GetInstance().GetMoveContainer();
CollideContainer* collideContainer = ContainerContainer::GetInstance().GetCollideContainer();
CharacterContainer* characterContainer = ContainerContainer::GetInstance().GetCharacterContainer();
SpawnController* spawnController;
GameScreen::GameScreen(SDL_Renderer* ren, string path) : AbstractScreen(ren)
{
	MapParser* mp{};
	map = mp->ParseJsonMap(path);
	GameObjectFactory::Instance()->mapLevel = map.get();
	//spawnController.AddLocation(1280, 340);
	//spawnController.AddLocation(640, 680);
	//spawnController.AddLocation(0, 340);
	
	characterContainer->Init();
	spawnController = new SpawnController();
	spawnController->AddLocation(640, 100);
	spawnController->SetRenderer(ren);

	mike = GameObjectFactory::Instance()->CreateMike();
	mike->SetPosition(800, 150);
	mike->Init(drawContainer, animateContainer, moveContainer, actionContainer, characterContainer, ren);
	
	spawnController->AddTarget(mike);

	// --
	map.get()->setSprites(mp->GenerateSprites(path));
	SDL_Surface* s;
	s = IMG_Load(map->getImagePath().c_str());
	if (!s) {
		cout << "Error image load : " << IMG_GetError() << endl;
		return;
	}

	//Load && play sound
	loadSounds();
	playSound();
	map.get()->setTexture(SDL_CreateTextureFromSurface(ren, s));
	SDL_FreeSurface(s);
}

void GameScreen::loadSounds() {

	//more info : http://content.gpwiki.org/index.php/SDL_mixer:Tutorials:Playing_a_WAV_Sound_File
	//todo dit dynamische maken -> kan pas bij levelfactory
	sound = Mix_LoadWAV("assets/sounds/bgSound1.wav");
	if (sound == NULL) {
		cout << stderr << "Unable to load WAV file: %s\n" << Mix_GetError();
	}
}

void GameScreen::playSound() {
	int channel;
	// first -1 will cause Mix_PlayChannel to play our sample on the first available sound channel.This is probably what you'll want to do, in most cases. If for some reason you wish to specify a certain channel for playback, you may pass an integer designating the desired channel.
	//sound for the sound chunk
	// Second -1 to play soundchunk only once. Passing -1 plays the sample on an infinite loop.
	channel = Mix_PlayChannel(-1, sound, -1);
	if (channel == -1) {
		cout << stderr << "Unable to play WAV file: %s\n" << Mix_GetError();
	}
	Mix_Volume(channel, 25);

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
}

void GameScreen::stopSound() {
	Mix_FreeChunk(sound);
	Mix_CloseAudio();
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
	actionContainer->Update(dt);
	moveContainer->Move(dt);
	collideContainer->Collide(dt);
	animateContainer->Animate(dt);
	drawContainer->Draw(dt, ren);

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