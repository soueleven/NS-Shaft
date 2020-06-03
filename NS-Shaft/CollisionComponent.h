#pragma once

#include "Component.h"
#include "Vector2.h"

class CollisionComponent : public Component
{
public:
	CollisionComponent(class Actor* owner);

	// Getters/setters for private variables
	Vector2 GetPosition() const { return mPosition; }
	void SetPosition(Vector2 position) { mPosition = position; }
	Vector2 GetShape() const { return mShape; }
	void SetShape(Vector2 shape) { mShape = shape; }
private:
	Vector2 mPosition;
	Vector2 mShape;
};

bool Collision(const CollisionComponent* a, const CollisionComponent* b);