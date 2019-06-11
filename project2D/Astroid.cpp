#include "Astroid.h"
#include "Input.h"
#include "Application.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;


Astroid::Astroid(const char* FileName) : GameObject(FileName)
{
	aie::Application* application = aie::Application::GetInstance();

	_TempPostion = _LocalTransform[1];

	_FX = _LocalTransform.m[3];
	_FY = _LocalTransform.m[4];
	_Speed = 0.10;

	_Position = Vector2(rand() + application->GetWindowWidth(), rand() + application->GetWindowHeight());
	SetPosition(_Position);

	if (FileName == "./textures/rock_small.png" || FileName == "./textures/rock_small_blue.png")
	{
		_Collider = new Collider(Vector2(-15, -15), Vector2(15, 15));
		_ForwardSpeed = 250;
		_Name = "Small Asteroid";
		SetName(_Name);
	}
	else
	{
		_Collider = new Collider(Vector2(-30, -30), Vector2(30, 30));
		_ForwardSpeed = 125;
		_Name = "Large Asteroid";
		SetName(_Name);
	}
}


Astroid::~Astroid()
{
}

void Astroid::Update(float deltaTime)
{
	aie::Application* application = aie::Application::GetInstance();
	aie::Input* _Input = aie::Input::GetInstance();

	//Calculate Movement
	Vector2 _Position = GetPosition();
	Vector2 _Forward(_LocalTransform.m[3], _LocalTransform.m[4]);
	_Velocity = _Forward * 300;

	if (_Velocity.magnitude() > _ForwardSpeed)
	{
		_Velocity.normalise();
		_Velocity *= _ForwardSpeed;
	}

	_Position = GetPosition();
	_Position = _Position + (_Velocity * deltaTime);

	//If astroid is off screen
	if (_Position.y > application->GetWindowHeight() + 45)
	{
		_Position.y = -25;
		_Speed = rand() % 10;
		_FX = _LocalTransform.m[3];
		_FY = _LocalTransform.m[4];
	}
	else if (_Position.y < -45)
	{	
		_Position.y = application->GetWindowHeight() + 25;
		_Speed = rand() % 10;
		_FX = _LocalTransform.m[3];
		_FY = _LocalTransform.m[4];
	}
	if (_Position.x > application->GetWindowWidth() + 45)
	{
		_Position.x = -25;
		_Speed = rand() % 10;
		_FX = _LocalTransform.m[3];
		_FY = _LocalTransform.m[4];
	}
	else if (_Position.x < -45)
	{
		_Position.x = application->GetWindowWidth() + 25;
		_Speed = rand() % 10;
		_FX = _LocalTransform.m[3];
		_FY = _LocalTransform.m[4];
	}

	//Rotation
	SetRotation(GetRotation() + (_Speed / 10) * deltaTime);

	//Sets ships position
	SetPosition(_Position);

	//Updates all objects
	GameObject::Update(deltaTime);
}

void Astroid::SetSpeed(float speed)
{
	_Speed = speed;
}

std::string Astroid::GetName()
{
	return _Name;
}
