#pragma once
#include "GameObject.h"
#include "CollisionManager.h"
#include "Tank.h"

class Level : public GameObject
{
public:
	Level();
	~Level();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* renderer);

	void GetShipHit();
	bool SetShipHit();
	Tank* GetShip();
private:
	CollisionManager* _collisionManager;

	Tank* _Tank;
};

