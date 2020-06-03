#pragma once

#include "Actor.h"

class Player : public Actor
{
public:
	const unsigned int STOP_ANIMATE = 1;
	const unsigned int LEFT_ANIMATE = 2;
	const unsigned int RIGHT_ANIMATE = 3;

	Player(class Game* game);

	void UpdateActor(float deltaTime) override;
	void ActorInput(const uint8_t* keyState) override;
	class CollisionComponent* GetCollision() { return mCollision; }
private:
	class CollisionComponent* mCollision;
	class AnimSpriteComponent* mAnim;
};