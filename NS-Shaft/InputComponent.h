#pragma once

#include "MoveComponent.h"
#include <cstdint>

class InputComponent : public MoveComponent
{
public:
	// Lower update order to update first
	InputComponent(class Actor* owner);

	void Update(float deltaTime) override;
	void ProcessInput(const uint8_t* keyState) override;

	// Getters/setters for private variables
	float GetMaxSpeed() const { return mMaxSpeed; }
	int GetRightKey() const { return mRightKey; }
	int GetLeftKey() const { return mLeftKey; }

	void SetMaxSpeed(float speed) { mMaxSpeed = speed; }
	void SetRightKey(int key) { mRightKey = key; }
	void SetLeftKey(int key) { mLeftKey = key; }
private:
	// The maximum speeds
	float mMaxSpeed;
	// The move speed
	float mMoveSpeed;
	// Keys for right/left movement
	int mRightKey;
	int mLeftKey;
};