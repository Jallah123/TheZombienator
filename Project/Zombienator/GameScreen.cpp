#pragma once
#include "GameScreen.h"
#include <SDL_mixer.h>
#include <iostream>

#include "Map.h"
#include "Mike.h"
#include "Zombie.h"



GameScreen::GameScreen(SDL_Renderer* ren, char* path) : AbstractScreen(ren)
{
	map = new Map(path, *ren);

	goFactory->SetLevel( map );
	goFactory->SetContainers(
		&drawContainer, 
		&animateContainer, 
		&moveContainer, 
		&actionContainer, 
		&collideContainer, 
		&characterContainer, 
		ren
	);
	BehaviourFactory::Instance()->SetContainers(
		&drawContainer,
		&animateContainer,
		&moveContainer,
		&actionContainer,
		&collideContainer,
		&characterContainer,
		ren
	);
	BehaviourFactory::Instance()->SetMap(map);
	characterContainer.Init();
	
	spawnController.AddLocation(640, 100);
	spawnController.AddLocation(1280, 340);
	spawnController.AddLocation(640, 680);
	spawnController.AddLocation(0, 340);
	spawnController.SetRenderer(ren);

	mike = goFactory->CreateMike();
	mike->SetPosition(800, 150);
	
	spawnController.AddTarget(mike);

	//Load && play sound
	musicController->Load("assets/sounds/bgSound1.wav");
	musicController->Play(1, -1);
	musicController->SetVolume(25, 1);
}


GameScreen::~GameScreen()
{
	delete mike;
}

void GameScreen::Update(float dt)
{

}

void GameScreen::Draw(SDL_Renderer& ren, float dt)
{
	if (InputContainer::GetInstance().GetKeyState('['))
	{
		speed += 0.1;
	}
	else if (InputContainer::GetInstance().GetKeyState(']'))
	{
		speed -= 0.1;
		if(speed < 0)
			speed = 0;
	}
	else if (InputContainer::GetInstance().GetKeyState('\\'))
	{
		speed = 1.0;
	}
	dt *= speed;
	map->Draw(ren);
	spawnController.Update(dt);
	actionContainer.Update(dt);
	collideContainer.Collide(dt);
	moveContainer.Move(dt);
	animateContainer.Animate(dt);
	drawContainer.Draw(dt, ren);
}
