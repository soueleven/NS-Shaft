#pragma once

#include "Component.h"

class MoveComponent : public Component
{
public:
	// Lower update order to update first
	MoveComponent(class Actor* owner, int updateOrder = 10);

	void Update(float deltaTime) override;

	float GetSpeed() const { return mSpeed; }
	void SetSpeed(float speed) { mSpeed = speed; }
	float GetMoveSpeed() const { return mMoveSpeed; }
	void SetMoveSpeed(float speed) { mMoveSpeed = speed; }
private:
	float mSpeed;
	float mMoveSpeed;
};