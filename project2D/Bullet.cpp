#include "Bullet.h"
#include "Input.h"
#include "Application.h"
#include <iostream>

using namespace std;

Bullet::Bullet(const char* FileName) : GameObject(FileName)
{
	SetName("Bullet");
	_Collider = new Collider(Vector2(-10, -10), Vector2(10, 10));
	_Alive = false;
}

void Bullet::Update(float deltaTime)
{
	aie::Application* application = aie::Application::GetInstance();
	if (_Alive)
	{

		//Accelerate 
		Vector2 _Position = GetPosition();
		Vector2 _Forward(_GlobalTransform.m[3], _GlobalTransform.m[4]);
		Vector2 _Velocity = _Forward * 300;

		if (_Velocity.magnitude() > 800)
		{
			_Velocity.normalise();
			_Velocity *= 800;
		}

		_Position = _Position + (_Velocity * deltaTime);

		//If bullet is off screen
		if (GetPosition().y > application->GetWindowHeight() + 25)
		{
			_Alive = false;
			SetPosition(Vector2(10000, 10000));
		}
		else if (GetPosition().y < 0 - 25)
		{
			_Alive = false;
			SetPosition(Vector2(10000, 10000));
		}
		if (GetPosition().x > application->GetWindowWidth() + 25)
		{
			_Alive = false;
			SetPosition(Vector2(10000, 10000));
		}
		else if (GetPosition().x < 0 - 25)
		{
			_Alive = false;
			SetPosition(Vector2(10000, 10000));
		}

		cout << _Position.x << " , " << _Position.y << endl;

		SetPosition(_Position);
	}
}

void Bullet::Draw(aie::Renderer2D* renderer)
{
	if (_Alive)
		renderer->DrawSprite(_Texture, GetPosition().x, GetPosition().y);
}

void Bullet::Fire(Vector2 Position, Vector2 Rotation)
{
	_Alive = true;

	SetPosition(Position);

	if (Rotation.magnitudeSqr() > 0)
	{
		_LocalTransform.m[3] = Rotation.x;
		_LocalTransform.m[4] = Rotation.y;

		_LocalTransform.m[0] = Rotation.y;
		_LocalTransform.m[1] = -Rotation.x;
		UpDateGlobalTransform();
	}
	//cout << _LocalTransform.m[3] <<" , " << _LocalTransform.m[4] << endl;

	//SetPosition(_Turret->GetPosition());
	//cout << GetParent()->GetPosition() << endl;
}