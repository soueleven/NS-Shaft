#pragma once

#include "Actor.h"

class Stair : public Actor
{
public:
	Stair(class Game* game);
	~Stair();

	class CollisionComponent* GetCollision() { return mCollision; }
private:
	class CollisionComponent* mCollision;
};