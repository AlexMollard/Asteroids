#pragma once
#include "GameObject.h"
#include "Renderer2D.h"

class Bullet : public GameObject
{
public:
	// Constructor
	Bullet(const char* FileName);

	// Update/Draw Functions
	void Update(float deltaTime);
	virtual void Draw(aie::Renderer2D* renderer);

	// Alive Functions
	void SetAlive(bool setting) { _Alive = setting; };
	bool GetAlive()				{ return _Alive; };

	// Fire Functions
	void Fire(Vector2 Position, Vector2 Rotation);

	// Variables
	Vector2 _BulletPos;
	Vector2 _Direction;
	bool _Alive;
	GameObject* _Turret;
};

