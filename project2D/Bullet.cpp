#include "Bullet.h"
#include "Input.h"
#include "Application.h"

Bullet::Bullet(const char* FileName) : GameObject(FileName)
{
	_Collider = new Collider(Vector2(-10, -40), Vector2(10, 40));
	fired = false;
	_Acceleration = 20.0f;
}


Bullet::~Bullet()
{
}

void Bullet::Update(float deltaTime)
{
	aie::Input* _Input = aie::Input::GetInstance();
	aie::Application* application = aie::Application::GetInstance();

	if (!fired)
	{
		_TempPostion = _LocalTransform[1];
		_Position = GetPosition();
	}
	
	Vector2 _Forward(_TempPostion.x, _TempPostion.y);

	if (_Input->IsKeyDown(aie::INPUT_KEY_SPACE))
		fired = true;

	if (fired)
	{
		_Velocity = _Velocity + (_Forward * _Acceleration);
		_Position = _Position + (_Velocity * deltaTime);
		
		//If ship is off screen
		if (_Position.y > application->GetWindowHeight() + 15)
			_Position.y = -15;
		else if (_Position.y < 0 - 15)
			_Position.y = application->GetWindowHeight() + 15;

		if (_Position.x > application->GetWindowWidth() + 15)
			_Position.x = -15;
		else if (_Position.x < 0 - 15)
			_Position.x = application->GetWindowWidth() + 15;

		SetPosition(_Position);
	}
}

void Bullet::Hit()
{

}