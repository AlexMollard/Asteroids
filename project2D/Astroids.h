#pragma once
#include "GameObject.h"
#include "Astroid.h"
#include "CollisionManager.h"
#include "Tank.h"

class Astroids : public GameObject
{
public:
	Astroids();
	~Astroids();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* renderer);

	Astroid* GetSmallAsteroid(int index);
	Astroid* GetLargeAsteroid(int index);

	int _RandomInt = 0;
	const int count = 5;

	bool CheckForCollisions(Tank* player);
private:
	CollisionManager* _collisionManager;
	Astroid* _Asteroids[5];
	Astroid* _AsteroidsLarge[4];
	Astroid* _AsteroidsLargeGreen[2];
};