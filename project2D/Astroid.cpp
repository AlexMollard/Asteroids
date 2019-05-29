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

	_TempPostion = _GlobalTransform[1];

	_Speed = 0.10;
	
	cout << rand() % application->GetWindowWidth() << endl;

	_Position = Vector2(rand() + application->GetWindowWidth(), rand() + application->GetWindowHeight());
	SetPosition(_Position);

	if (FileName == "./textures/rock_small.png")
	{
		_Collider = new Collider(Vector2(-20, -20), Vector2(20, 20));
		_ForwardSpeed = 500;
		_Name = "Small Asteroid";
		SetName(_Name);
	}
	else
	{
		_Collider = new Collider(Vector2(-35, -35), Vector2(35, 35));
		_ForwardSpeed = 250;
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
	Vector2 _Forward(_TempPostion.x, _TempPostion.y);
	_Acceleration = 100;
	_Velocity = _Velocity + (_Forward * _Acceleration);

	if (_Velocity.magnitude() > _ForwardSpeed)
	{
		_Velocity.normalise();
		_Velocity *= _ForwardSpeed;
	}

	_Position = GetPosition();
	_Position = _Position + (_Velocity * deltaTime);

	//If astroid is off screen
	if (_Position.y > application->GetWindowHeight() + 70)
	{
		_Position.y = -70;
		_TempPostion = _GlobalTransform[1];
		_Speed = (float)rand()/RAND_MAX;
	}
	else if (_Position.y < 0 - 70)
	{
		_Position.y = application->GetWindowHeight() + 70;
		_TempPostion = _GlobalTransform[1];
		_Speed = (float)rand() / RAND_MAX;
	}
	if (_Position.x > application->GetWindowWidth() + 70)
	{
		_Position.x = -70;
		_TempPostion = _GlobalTransform[1];
		_Speed = (float)rand() / RAND_MAX;
	}
	else if (_Position.x < 0 - 70)
	{
		_Position.x = application->GetWindowWidth() + 70;
		_TempPostion = _GlobalTransform[1];
		_Speed = (float)rand() / RAND_MAX;
	}

	//Rotation
	SetRotation(GetRotation() + (_Speed / 10));

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
