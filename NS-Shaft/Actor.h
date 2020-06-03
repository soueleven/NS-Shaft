#pragma once

#include <vector>
#include <cstdint>
#include "Vector2.h"

class Actor
{
public:
	enum State
	{
		EActive,
		EPaused,
		EDead
	};

	enum Direction
	{
		EDown,
		EUp,
	};

	Actor(class Game* game);
	virtual ~Actor();

	// Update function called from Game (not overridable)
	void Update(float deltaTime);
	// Updates all the components attached to the actor (not overridable)
	void UpdateComponents(float deltaTime);
	// Any actor-specific update code (overridable)
	virtual void UpdateActor(float deltaTime);

	// ProcessInput function called from Game (not overridable)
	void ProcessInput(const uint8_t* keyState);
	// Any actor-specific input code (overridable)
	virtual void ActorInput(const uint8_t* keyState);

	// Getters/setters
	const Vector2& GetPosition() const { return mPosition; }
	void SetPosition(const Vector2& pos) { mPosition = pos; }
	const Vector2& GetShape() const { return mShape; }
	void SetShape(const Vector2& pos) { mShape = pos; }

	State GetState() const { return mState; }
	void SetState(State state) { mState = state; }
	Direction GetDirection() const { return mDirection; }
	void SetDirection(Direction direction) { mDirection = direction; }

	class Game* GetGame() { return mGame; }

	// Add/remove components
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);
private:
	// Actor's state
	State mState;

	// Transform
	Vector2 mPosition;
	Vector2 mShape;
	Direction mDirection;

	std::vector<class Component*> mComponents;
	class Game* mGame;
};