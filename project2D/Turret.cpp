#include "Turret.h"
#include "Input.h"
#include <iostream>

using namespace std;

Turret::Turret(const char* FileName) : GameObject(FileName)
{
	counter = 0;
	SetName("Turret");

	_BulletPool = new BulletManager();
	_BulletPool->SetParent(this);
}

void Turret::Update(float deltaTime)
{
}

void Turret::UpdateMouse(float deltaTime)
{
	aie::Input* _Input = aie::Input::GetInstance();

	// ---------- Point turret to mouse ----------
	Vector2 _Mouse = Vector2(_Input->GetMouseX(), _Input->GetMouseY());
	Vector2 _Rotation = _Mouse - _GlobalTransform.getPosition();

	_Rotation.normalise();
	_GlobalTransform.m[3] = _Rotation.x;
	_GlobalTransform.m[4] = _Rotation.y;

	_GlobalTransform.m[0] = _Rotation.y;
	_GlobalTransform.m[1] = -_Rotation.x;
	// -------------------------------------------

		// If player is shooting
	if (_Input->WasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT))
	{
		Bullet* bullet = _BulletPool->GetBullet();
		bullet->Fire(_GlobalTransform.getPosition(), _Rotation);
		_Shooting = true;
	}
	else
		_Shooting = false;

	//_BulletPool->Update(deltaTime, _Shooting, _Rotation);

	GameObject::Update(deltaTime);
}

void Turret::SetShooting(bool setting)
{
	_Shooting = setting;
}

bool Turret::GetShooting()
{
	return _Shooting;
}