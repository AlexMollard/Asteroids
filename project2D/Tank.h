#pragma once
#include "GameObject.h"
#include "Renderer2D.h"

class Tank : public GameObject
{
public:
	Tank(const char* FileName);
	~Tank();

	void Update(float deltaTime);
	void OnCollision(GameObject* OtherObject);
	std::string GetName();

	std::string _Name;
	float _Speed;
	float _Acceleration = 0.0f;
	Vector2 _Velocity;
	Vector2 _Position;
	Vector2 ForwardBuf;
	Vector2 _PrevPos;
};