#include "Thrust.h"
#include "Input.h"

Thrust::Thrust(const char* FileName) : GameObject(FileName)
{
}

Thrust::~Thrust()
{
}

void Thrust::Update(float deltaTime)
{
	aie::Input* _Input = aie::Input::GetInstance();

	if (_Input->IsKeyDown(aie::INPUT_KEY_W))
	{
		Vector2 tempScale(1, 1);
		SetScale(tempScale);
	}
	else
	{
		Vector2 tempScale(0, 0);
		SetScale(tempScale);
	}

	GameObject::Update(deltaTime);
}