#pragma once

#include "SpriteComponent.h"
#include <vector>

class AnimSpriteComponent : public SpriteComponent
{
public:
	AnimSpriteComponent(class Actor* owner, SDL_Texture* texture, int drawOrder = 100, int unitPixel = 32);
	// Update/Draw animation every frame (overriden from component)
	void Update(float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;
	// Set the textures used for animation
	float GetAnimFPS() const { return mAnimFPS; }
	void SetAnimTileMap(const std::vector<int> map, unsigned int trigger);
	// Set/get the animation FPS
	void SetAnimFPS(float fps) { mAnimFPS = fps; }
	// Set/get the trigger
	int GetCurrTrigger() const { return mCurrTrigger; }
	void SetCurrTrigger(int trigger) { mCurrTrigger = trigger; }
private:
	struct AnimaTileMap
	{
		float mCurrFrame;
		float mAnimFPS;
		unsigned int mTrigger;
		std::vector<int> mMap;
	};
	// All textures in the animation
	std::vector<AnimaTileMap> mAnimaTileMap;
	// Current trigger
	int mCurrTrigger;
	// Animation frame rate
	float mAnimFPS;
	// Tile unit pixel
	unsigned int mUnitPixel;
};