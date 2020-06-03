#include "AnimSpriteComponent.h"
#include "SpriteComponent.h"
#include "Actor.h"

AnimSpriteComponent::AnimSpriteComponent(
	Actor* owner, SDL_Texture* texture, int drawOrder, int unitPixel
):SpriteComponent(owner, drawOrder)
	, mCurrTrigger(1)
	, mAnimFPS(6.0f)
	, mUnitPixel(unitPixel)
{
	SetTexture(texture);
}

void AnimSpriteComponent::Update(float deltaTime)
{
	for (auto& at : mAnimaTileMap)
	{
		if (mCurrTrigger == static_cast<int>(at.mTrigger))
		{
			// Update the current frame based on frame rate
			// and delta time
			at.mCurrFrame += mAnimFPS * deltaTime;
		}
	}
}

void AnimSpriteComponent::Draw(SDL_Renderer* renderer)
{
	if (mTexture) {
		for (auto& at : mAnimaTileMap)
		{
			if (mCurrTrigger == static_cast<int>(at.mTrigger))
			{
				// Wrap current frame if needed
				while (at.mCurrFrame >= at.mMap.size())
				{
					at.mCurrFrame -= at.mMap.size();
					mCurrTrigger = 1;
				}

				int currTile = at.mMap[static_cast<int>(at.mCurrFrame)];
				int texRow = mTexWidth / mUnitPixel;

				SDL_Rect tileRect;
				tileRect.w = static_cast<int>(mUnitPixel);
				tileRect.h = static_cast<int>(mUnitPixel);
				tileRect.x = static_cast<int>(currTile % texRow * mUnitPixel);
				tileRect.y = static_cast<int>(currTile / texRow * mUnitPixel);
				SDL_Rect r;
				// Scale the width/height by owner's scale
				r.w = static_cast<int>(mTexWidth);
				r.h = static_cast<int>(mTexHeight);
				// Center the rectangle around the position of the owner
				r.x = static_cast<int>(mOwner->GetPosition().x - r.w / 2);
				r.y = static_cast<int>(mOwner->GetPosition().y - r.h / 2);

				// Draw
				SDL_RenderCopyEx(renderer,
					mTexture,
					&tileRect,
					&r,
					0,
					nullptr,
					SDL_FLIP_NONE
				);
			}
		}
	}
}

void AnimSpriteComponent::SetAnimTileMap(const std::vector<int> map, unsigned int trigger)
{
	AnimaTileMap temp;
	for (auto& m : map)
	{
		temp.mMap.emplace_back(m);
	}
	temp.mTrigger = trigger;

	if (temp.mMap.size() > 0)
	{
		// Set the active texture to first frame
		temp.mCurrFrame = 0.0f;
	}

	mAnimaTileMap.emplace_back(temp);
}