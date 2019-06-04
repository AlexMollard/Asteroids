#pragma once
#include "GameObject.h"
#include "Bullet.h"

class BulletManager : public GameObject
{
public:
	// Constructor
	BulletManager();

	// Functions
	void Update(float deltaTime, bool shooting, Vector2 _NewRotation);
	Bullet* GetBullet();

	// Variables
	Bullet* _Bullet[10];
};