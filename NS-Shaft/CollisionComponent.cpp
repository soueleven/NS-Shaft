#include "CollisionComponent.h"
#include "Actor.h"

CollisionComponent::CollisionComponent(class Actor* owner)
	:Component(owner)
	, mPosition(0.0f, 0.0f)
	, mShape(0.0f, 0.0f)
{
}

bool Collision(const CollisionComponent* rectangle, const CollisionComponent* square)
{
	float rY = rectangle->GetOwner()->GetPosition().y;
	float rX = rectangle->GetOwner()->GetPosition().x;
	float rW = rectangle->GetOwner()->GetShape().x;
	float rH = rectangle->GetOwner()->GetShape().y;
	float sY = square->GetOwner()->GetPosition().y;
	float sX = square->GetOwner()->GetPosition().x;
	float sW = square->GetOwner()->GetShape().x;
	float sH = square->GetOwner()->GetShape().y;

	// The player must be on the stair 
	if ((rY - sY) > (rH + sH)) {
		if ((rY - sY) <= (rH * 2 + sH) &&
			(sX - sW / 2) < (rX + rW / 2) &&
			(sX + sW / 2) > (rX - rW / 2))
		{
			return true;
		}
	}

	return false;
}