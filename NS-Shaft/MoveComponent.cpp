#include "MoveComponent.h"
#include "Actor.h"

MoveComponent::MoveComponent(class Actor* owner, int updateOrder)
	:Component(owner, updateOrder)
	, mSpeed(150.0f)
	, mMoveSpeed(0.0f)
{
}

void MoveComponent::Update(float deltaTime)
{
	if (mSpeed > 0.001f) // Not near zero
	{
		Vector2 pos = mOwner->GetPosition();
		
		if (mOwner->GetDirection() == Actor::EDown)
			pos.y += mSpeed * deltaTime;
		else
			pos.y -= mSpeed * deltaTime;

		if (pos.y < 0 || pos.y > 768) 
		{
			mOwner->SetState(Actor::EDead);
		}
		else
		{
			mOwner->SetPosition(pos);
		}
	}
}