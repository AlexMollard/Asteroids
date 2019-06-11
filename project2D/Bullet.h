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
	void SetTimeAlive(float time) { _TimeAlive = time; };
	float GetTimeAlive()		{ return _TimeAlive; };

	// Fire Functions
	void Fire(Vector2 Position, Vector2 Rotation);
	void OnCollision(GameObject* OtherObject);
	void AddScore(float deltaTime);

	// Variables
	Vector2 _BulletPos;
	Vector2 _Direction;
	bool _Alive;
	GameObject* _Turret;
	float _TimeAlive;
	GameObject* _Level;
	bool _HitScore;
	float _Time;
};

