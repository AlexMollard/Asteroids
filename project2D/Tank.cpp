#include "Tank.h"
#include "Input.h"
#include "Application.h"
#include <iostream>
using namespace std;

Tank::Tank(const char* FileName) : GameObject(FileName)
{
	_Acceleration = 20.0f;
	_Collider = new Collider(Vector2(-10, -10), Vector2(10, 10));
	_Name = "Space_Ship";
	SetName(_Name);
}

Tank::~Tank()
{
}

void Tank::Update(float deltaTime)
{
	aie::Application* application = aie::Application::GetInstance();
	aie::Input* _Input = aie::Input::GetInstance();
	_PrevPos = GetPosition();

	//Calculate Movement
	Vector3 _TempPostion = _GlobalTransform[1];
	Vector2 _Forward(_TempPostion.x, _TempPostion.y);
	Vector2 _OppositeVelocity = _Velocity;

	if (_Velocity.x != 0 || _Velocity.y != 0)
		_OppositeVelocity.normalise();


	if (_Input->IsKeyDown(aie::INPUT_KEY_W) && _Acceleration <= 400)
	{
		_Velocity = _Velocity + (_Forward * _Acceleration);
	}
	else if (_Acceleration > 20 || _Velocity.y != 0 || _Velocity.x != 0)
	{
		//Y
		if (_Velocity.y <= 1 && _Velocity.y >= -1)
		{
			_Velocity.y = 0;
		}
		if (_Velocity.y <= -1)
		{
			_Velocity.y += 100 * deltaTime;
		}
		if (_Velocity.y >= 1)
		{
			_Velocity.y -= 100 * deltaTime;
		}

		// X
		if (_Velocity.x <= 1 && _Velocity.x >= -1)
		{
			_Velocity.x = 0;
		}
		if (_Velocity.x <= -1)
		{
			_Velocity.x += 100 * deltaTime;
		}
		if (_Velocity.x >= 1)
		{
			_Velocity.x -= 100 * deltaTime;
		}
	}
	
	if (_Velocity.magnitude() > 500)
	{
		_Velocity.normalise();
		_Velocity *= 500;
	}

	if (_Input->IsKeyDown(aie::INPUT_KEY_S))
	{
		_Velocity += (_OppositeVelocity * -1) * _Acceleration;

		if (_Velocity.magnitude() < 10)
		{
			_Velocity = Vector2(0, 0);
		}
	}


	_Position = GetPosition();
	_Position = _Position + (_Velocity * deltaTime);


	//Calculate Rotation
	float _Rotation = GetLocalRotation();
	if (_Input->IsKeyDown(aie::INPUT_KEY_A))
	{
		_Rotation += 5 * deltaTime;
	}
	if (_Input->IsKeyDown(aie::INPUT_KEY_D))
	{
		_Rotation -= 5 * deltaTime;
	}
	SetRotation(_Rotation);

	//If ship is off screen
	if (_Position.y > application->GetWindowHeight() + 15)
		_Position.y = -15;
	else if (_Position.y < 0 - 15)
		_Position.y = application->GetWindowHeight() + 15;

	if (_Position.x > application->GetWindowWidth() + 15)
		_Position.x = -15;
	else if (_Position.x < 0 - 15)
		_Position.x = application->GetWindowWidth() + 15;

	//Debugging ship movement
	cout << endl;
	cout << "------- New Update -------" << endl;
	cout << "Velocity: X: " << _Velocity.x << " Y: " << _Velocity.y << endl;
	cout << "Acceleration: " << _Acceleration << endl;

	//Sets ships position
	SetPosition(_Position);

	//Updates all objects
	GameObject::Update(deltaTime);
}

void Tank::OnCollision(GameObject* OtherObject)
{
	SetPosition(_PrevPos);
}

std::string Tank::GetName()
{
	return _Name;
}