#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include "CollisionManager.h"


class BulletManager : public GameObject
{
public:
	// Constructor/Destructor
	BulletManager();
	~BulletManager();

	// Functions
	Bullet* GetBullet();
	bool AreAllBulletsAlive();

	// Variables
	Bullet* _Bullet[10];
	Bullet* _OldestBullet;
	CollisionManager* _BulletCollisionManager;

};