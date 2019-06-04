#pragma once
#include "GameObject.h"
#include "CollisionManager.h"
#include "Tank.h"
#include "Turret.h"
#include "Bullet.h"

class Level : public GameObject
{
public:
	Level();
	~Level();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* renderer);

	Tank* GetShip();
	Turret* GetTurret();
	Bullet* GetBullet();
private:
	CollisionManager* _collisionManager;

	Tank* _Tank;
	Turret* _Turret;
	Bullet* _Bullet;
};

