#include "Stair.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "CollisionComponent.h"
#include "Game.h"

Stair::Stair(Game* game)
	:Actor(game)
{
	// Initialize to bottom center position
	SetPosition(Vector2(384.0f, 768.0f));
	SetShape(Vector2(80.0f, 16.0f));

	// Create a sprite component
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/stair.png"));

	// Create a move component, and set a forward speed
	MoveComponent* mc = new MoveComponent(this);

	// Create a collision component (for collision)
	mCollision = new CollisionComponent(this);
	mCollision->SetPosition(GetPosition());
	mCollision->SetShape(GetShape());

	// Add to mStairs in game
	game->AddStair(this);
}

Stair::~Stair()
{
	GetGame()->RemoveStair(this);
}