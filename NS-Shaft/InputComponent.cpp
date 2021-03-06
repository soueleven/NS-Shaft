#include "InputComponent.h"
#include "Actor.h"
#include "SDL.h"

InputComponent::InputComponent(class Actor* owner)
	:MoveComponent(owner)
	, mRightKey(0)
	, mLeftKey(0)
{
}

void InputComponent::Update(float deltaTime)
{
	MoveComponent::Update(deltaTime);

	Vector2 pos = mOwner->GetPosition();

	pos.x += mMoveSpeed * deltaTime;
	
	if (pos.x > 768)
	{
		pos.x = 0;
	}
	if (pos.x < 0)
	{
		pos.x = 768;
	}

	mOwner->SetPosition(pos);
}

void InputComponent::ProcessInput(const uint8_t* keyState)
{
	mMoveSpeed = 0.0f;
	if (keyState[mRightKey])
	{
		mMoveSpeed += mMaxSpeed;
	}
	if (keyState[mLeftKey])
	{
		mMoveSpeed -= mMaxSpeed;
	}
}
