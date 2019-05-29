#pragma once
#include "GameObject.h"
#include "Renderer2D.h"

class Astroid : public GameObject
{
public:
	Astroid(const char* FileName);
	~Astroid();

	void Update(float deltaTime);
	
	void SetSpeed(float speed);

	std::string GetName();

	std::string _Name;
	float _Speed;
	float _ForwardSpeed;
	float _Acceleration = 40.0f;
	Vector2 _Velocity;
	Vector2 _Position;
	Vector2 ForwardBuf;

	Vector3 _TempPostion;
};