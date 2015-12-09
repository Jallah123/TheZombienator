#include "ZombieWalkingState.h"
#include "ZombieStateFactory.h"
#include "GameObjectContainer.h"

ZombieWalkingState::ZombieWalkingState()
{
}


ZombieWalkingState::~ZombieWalkingState()
{
}


void ZombieWalkingState::CheckState()
{
	Zombie* z = GetOwner();
	Character* target = z->GetTarget();
	if (target == nullptr && !target->IsDeath()) {
		z->SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::STANDSTILL, z));
		return;
	}
	else if (z->IsInAttackRadius(target)) {
		z->SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::ATTACKING, z));
		return;
	}
}

void ZombieWalkingState::Update(float dt)
{
	Zombie* z = GetOwner();
	Character* target = z->GetTarget();
	GameObjectContainer* goc = z->GetGameObjectContainer();

	float destX = target->getPosX();
	float destY = target->getPosY();

	// -- Get destination rect
	SDL_Rect* goRect = z->GetCollideRect();
	float newX = z->getPosX();
	float newY = z->getPosY();

	// -- Move directions
	bool left = destX + target->GetWidth() <= newX;
	bool right = destX >= newX + z->GetWidth();
	bool up = destY + (target->GetHeight()/2) <= newY;
	bool down = destY >= newY + (z->GetHeight() / 2);
	
	float speed = z->GetSpeed() * dt;

	z->SetMoveDir(Direction::NONE);

	// -- Move directions
	if (left) {
		z->SetMoveDir(Direction::WEST);
		z->SetLookDir(Direction::WEST);
		newX -= speed;
	}
	if (right) {
		z->SetMoveDir(Direction::EAST);
		z->SetLookDir(Direction::EAST);
		newX += speed;
	}
	if (up) {
		z->SetMoveDir(Direction::NORTH);
		z->SetLookDir(Direction::NORTH);
		newY -= speed;
	}
	if (down) {
		z->SetMoveDir(Direction::SOUTH);
		z->SetLookDir(Direction::SOUTH);
		newY += speed;
	}
	

	float finalX = newX;
	float finalY = newY;

	// -- Map Collision
	std::vector<GameObject*> gameObjects = goc->GetGameObjects();
	for (auto& g : gameObjects)
	{
		if (g != z) {
			goRect->x = static_cast<int>(newX + .5f);
			goRect->y = static_cast<int>(z->getPosY() + .5f + (goRect->h));
			if (SDL_HasIntersection(goRect, g->GetCollideRect()))
				finalX = z->getPosX();

			goRect->x = static_cast<int>(z->getPosX() + .5f);
			goRect->y = static_cast<int>(newY + .5f + (goRect->h));
			if (SDL_HasIntersection(goRect, g->GetCollideRect()))
				finalY = z->getPosY();
		}
	}
	z->SetPosition(finalX, finalY);
	CheckState();
}

void ZombieWalkingState::CalculatePath() {
	/*
	vector<vector<unique_ptr<Room>>>& rooms = CurrentLayer->GetRooms();
	for each (auto& roomrow in rooms)
	{
		for each (auto& room in roomrow)
		{
			room.get()->SetDistance(numeric_limits<int>::max());
			room.get()->SetPreviousRoom(nullptr);
		}
	}
	GetCurrentRoom()->SetDistance(0);
	deque<Room*> queue;
	queue.push_back(GetCurrentRoom());

	while (!queue.empty()) {
		Room* room = queue.front();
		queue.pop_front();
		for each (auto& AdjecentRoom in room->GetAdjecentRooms())
		{

			int weight = AdjecentRoom.second->GetWeigth();
			int distance = room->GetDistance() + weight;

			if (distance < AdjecentRoom.second->GetDistance()) {
				AdjecentRoom.second->SetDistance(distance);
				AdjecentRoom.second->SetPreviousRoom(room);
				queue.push_back(AdjecentRoom.second);
			}
		}
	}
	*/
}
