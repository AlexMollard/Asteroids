#pragma once
#include "GameObject.h"
#include "Renderer2D.h"

class Bullet : public GameObject
{
public:
	Bullet(const char* FileName);
	~Bullet();

	void Update(float deltaTime);

	void Hit();

	bool fired;
	float _Acceleration = 0.0f;
	float rotation;

	Vector2 _Velocity;
	Vector2 _Position;
	Vector3 _TempPostion;
};

