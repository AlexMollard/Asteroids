#include "Bullet.h"
#include "Input.h"
#include "Application.h"
#include <iostream>

using namespace std;

Bullet::Bullet(const char* FileName) : GameObject(FileName)
{
	SetName("Bullet");

	_HitScore = false;
	_Collider = new Collider(Vector2(-10, -10), Vector2(10, 10));
	_Alive = false;
	_TimeAlive = 0;

	Vector2 _Position = (Vector2(10000, 10000));
	SetPosition(_Position);
	_Collider->SetPostition(GetPosition());

}

void Bullet::Update(float deltaTime)
{
	_Time = deltaTime;
	aie::Application* application = aie::Application::GetInstance();
	if (_Alive)
	{
		_TimeAlive += deltaTime * 2;
		_HitScore = false;

		//Accelerate 
		Vector2 _Position = GetPosition();
		Vector2 _Forward(_LocalTransform.m[3], _LocalTransform.m[4]);
		Vector2 _Velocity = _Forward * 300;

		if (_Velocity.magnitude() > 800)
		{
			_Velocity.normalise();
			_Velocity *= 800;
		}

		_Position = _Position + (_Velocity * deltaTime);

		//If bullet is off screen
		if (GetPosition().y > application->GetWindowHeight())
		{
			_Alive = false;
			_Position = (Vector2(10000, 10000));
			_TimeAlive = 0;
		}
		else if (GetPosition().y < 0 - 25)
		{
			_Alive = false;
			_Position = (Vector2(10000, 10000));
			_TimeAlive = 0;
		}
		if (GetPosition().x > application->GetWindowWidth() + 25)
		{
			_Alive = false;
			_Position = (Vector2(10000, 10000));
			_TimeAlive = 0;
		}
		else if (GetPosition().x < 0 - 25)
		{
			_Alive = false;
			_Position = (Vector2(10000, 10000));
			_TimeAlive = 0;
		}

		SetPosition(_Position);
	}
		_Collider->SetPostition(GetPosition());

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

void Bullet::OnCollision(GameObject* OtherObject)
{
	if (!_HitScore && GetPosition() != (Vector2(40000, 40000)))
	{
		AddScore(_Time);
		_HitScore = true;
	}

	Vector2 _NewPosition = (Vector2(40000, 40000));
	SetPosition(_NewPosition);
	
	Vector2 _Position = (Vector2(10000, 10000));
	OtherObject->SetPosition(_Position);

}

void Bullet::AddScore(float deltaTime)
{
	GetParent()->GetParent()->GetParent()->GetParent()->SetScore(GetParent()->GetParent()->GetParent()->GetParent()->GetScore() + 100 * deltaTime);
}