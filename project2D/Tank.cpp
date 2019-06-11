#include "Tank.h"
#include "Input.h"
#include "Application.h"
#include <iostream>
using namespace std;

Tank::Tank()
{
	_Acceleration = 20.0f;
	_Collider = new Collider(Vector2(-40, -40), Vector2(40, 40));

	_ShipTexture = new aie::Texture("./textures/newShip.png");
	_ShipTextureFlash = new aie::Texture("./textures/newShip_hit.png");
	
	_Texture = _ShipTexture;

	_Name = "Space_Ship";
	SetName(_Name);
	_Health = 100;
	_Timer = 3;
}

Tank::~Tank()
{
	_Texture = nullptr;
	
	if (_ShipTexture)
	{
		delete _ShipTexture;
		_ShipTexture = nullptr;
	}

	if (_ShipTextureFlash)
	{
		delete _ShipTextureFlash;
		_ShipTextureFlash = nullptr;
	}

	if (_Collider)
	{
		delete _Collider;
		_Collider = nullptr;
	}

	if (_Collider2)
	{
		delete _Collider2;
		_Collider2 = nullptr;
	}
}

void Tank::Update(float deltaTime)
{
	time = deltaTime;
	aie::Application* application = aie::Application::GetInstance();
	aie::Input* _Input = aie::Input::GetInstance();
	_PrevPos = GetPosition();

	if (_Health <= 0)
	{
		SetParent(nullptr);
	}

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

	//Sets ships position
	SetPosition(_Position);

	//Sets ships texture to flash on hit
	if (_Timer <= 2.9 && _Timer >= 0)
	{
		_Timer += 1 * time;
		if (_Timer < 0.5)
			SetTexture(GetShipHitTexture());
		else if (_Timer < 1)
			SetTexture(GetShipTexture());
		else if (_Timer < 1.5)
			SetTexture(GetShipHitTexture());
		else if (_Timer < 2)
			SetTexture(GetShipTexture());
		else if (_Timer < 2.5)
			SetTexture(GetShipHitTexture());
		else if (_Timer < 3)
			SetTexture(GetShipTexture());
	}
	else if (_Timer >= 2.9)
	{
		_Timer = 3;
	}

	//Updates all objects
	GameObject::Update(deltaTime);
}

void Tank::OnCollision(GameObject* OtherObject)
{
	if (_Timer > 2.9)
	{
		Vector2 _Position = (Vector2(10000, 10000));
		OtherObject->SetPosition(_Position);
		_Timer = 0;
		Hit();
	}
}

std::string Tank::GetName()
{
	return _Name;
}

void Tank::Hit()
{
	_Position = GetPosition();
	_Velocity = Vector2(0, 0);
	_Position = _Position + (_Velocity * time);
	_Health -= 10;
	SetPosition(_Position);
}

int Tank::GetHealth()
{
	return _Health;
}

void Tank::SetTexture(aie::Texture* tex)
{
	_Texture = tex;
}

aie::Texture* Tank::GetShipTexture()
{
	return _ShipTexture;
}

aie::Texture* Tank::GetShipHitTexture()
{
	return _ShipTextureFlash;
}

float Tank::GetTimer()
{
	return _Timer;
}