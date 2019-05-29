#include "Turret.h"
#include "Input.h"


Turret::Turret(const char* FileName) : GameObject(FileName)
{
	//_Collider = new Collider(Vector2(-1, -1), Vector2(1, 1));
	_Speed = 1;
	_Acceleration = 0.0f;
}

Turret::~Turret()
{
}

void Turret::Update(float deltaTime)
{
	aie::Input* _Input = aie::Input::GetInstance();

	if (_Input->IsKeyDown(aie::INPUT_KEY_LEFT_SHIFT))
		_Speed = 100.0f * deltaTime;
	else
		_Speed = 50.0f * deltaTime;

	//Calculate Rotation
	float _Rotation = GetLocalRotation();
	if (_Input->IsKeyDown(aie::INPUT_KEY_LEFT))
	{
		_Rotation += _Speed / 15;
	}
	if (_Input->IsKeyDown(aie::INPUT_KEY_RIGHT))
	{
		_Rotation -= _Speed / 15;
	}
	SetRotation(_Rotation);

	GameObject::Update(deltaTime);
}
