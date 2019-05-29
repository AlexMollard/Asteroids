#pragma once
#include "GameObject.h"
#include "Astroid.h"
#include "CollisionManager.h"
#include "Tank.h"

class AsteroidManager : public GameObject
{
public:
	AsteroidManager();
	~AsteroidManager();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* renderer);

	Astroid* GetSmallAsteroid(int index);
	Astroid* GetLargeAsteroid(int index);

	int _RandomInt = 0;

	bool CheckForCollisions(Tank* player);
private:
	CollisionManager* _collisionManager;
	Astroid* _AsteroidsSmall[4];
	Astroid* _AsteroidsSmallBlue[4];
	Astroid* _AsteroidsLarge[4];
	Astroid* _AsteroidsLargeGreen[3];
	Astroid* _AsteroidsLargeBlue[2];
};