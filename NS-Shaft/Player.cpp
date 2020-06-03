#include "Player.h"
#include "Stair.h"
#include "AnimSpriteComponent.h"
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "CollisionComponent.h"
#include "Game.h"

Player::Player(Game* game)
	:Actor(game)
{
	// Initialize to random position/orientation
	SetPosition(Vector2(384.0f, 704.0f));
	SetShape(Vector2(32.0f, 32.0f));

	// Create an input component and set keys/speed
	InputComponent* ic = new InputComponent(this);
	ic->SetLeftKey(SDL_SCANCODE_LEFT);
	ic->SetRightKey(SDL_SCANCODE_RIGHT);
	ic->SetMaxSpeed(250.0f);

	// Create a collision component (for collision)
	mCollision = new CollisionComponent(this);
	mCollision->SetPosition(GetPosition());
	mCollision->SetShape(GetShape());
	
	// Create an animation component
	mAnim = new AnimSpriteComponent(this, game->GetTexture("Assets/player.png"));
	mAnim->SetAnimTileMap({ 1 }, STOP_ANIMATE);
	mAnim->SetAnimTileMap({ 4, 5, 6, 5 }, LEFT_ANIMATE);
	mAnim->SetAnimTileMap({ 6, 7, 8, 7 }, RIGHT_ANIMATE);
}

void Player::UpdateActor(float deltaTime)
{
	for (auto sta : GetGame()->GetStairs())
	{
		if (Collision(sta->GetCollision(), mCollision))
		{
			Vector2 pos = sta->GetPosition();
			Vector2 shape = GetShape();
			pos.x = GetPosition().x;
			pos.y = sta->GetPosition().y - sta->GetShape().y * 2 - shape.y;
			SetPosition(pos);
			SetDirection(Actor::EUp);
			break;
		}
		else
		{
			SetDirection(Actor::EDown);
		}
	}
}

void Player::ActorInput(const uint8_t* keyState)
{
	if (keyState[SDL_SCANCODE_LEFT])
	{
		mAnim->SetCurrTrigger(LEFT_ANIMATE);
	}
	if (keyState[SDL_SCANCODE_RIGHT])
	{
		mAnim->SetCurrTrigger(RIGHT_ANIMATE);
	}

	if (!(keyState[SDL_SCANCODE_RIGHT] || keyState[SDL_SCANCODE_LEFT]))
	{
		mAnim->SetCurrTrigger(STOP_ANIMATE);
	}
}