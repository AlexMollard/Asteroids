#include "Astroids.h"
#include "Application.h"
#include <iostream>

Astroids::Astroids()
{
	aie::Application* application = aie::Application::GetInstance();

	_collisionManager = new CollisionManager();

	for (int i = 0; i < count; i++)
	{
		_Asteroids[i] = new Astroid("./textures/rock_small.png"); 
		_Asteroids[i]->SetParent(this);
		_Asteroids[i]->UpDateGlobalTransform();
		_collisionManager->AddObject(_Asteroids[i]);
	}
	
	for (int i = 0; i < 4; i++)
	{
		_AsteroidsLarge[i] = new Astroid("./textures/rock_large.png");
		_AsteroidsLarge[i]->SetParent(this);
		_AsteroidsLarge[i]->UpDateGlobalTransform();
		_collisionManager->AddObject(_AsteroidsLarge[i]);
	}

	for (int i = 0; i < 2; i++)
	{
		_AsteroidsLargeGreen[i] = new Astroid("./textures/rock_large_green.png");
		_AsteroidsLargeGreen[i]->SetParent(this);
		_AsteroidsLargeGreen[i]->UpDateGlobalTransform();
		_collisionManager->AddObject(_AsteroidsLargeGreen[i]);
	}
}


Astroids::~Astroids()
{
	delete _collisionManager;
	_collisionManager = nullptr;
}


void Astroids::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
	_collisionManager->Update(deltaTime);
}

void Astroids::Draw(aie::Renderer2D* renderer)
{
	GameObject::Draw(renderer);
	_collisionManager->Draw(renderer);
}

Astroid* Astroids::GetSmallAsteroid(int index)
{
	return _Asteroids[index];
}

Astroid* Astroids::GetLargeAsteroid(int index)
{
	return _AsteroidsLarge[index];
}

bool Astroids::CheckForCollisions(Tank* player)
{
	if (_collisionManager->GetObject() == player)
	{
		_collisionManager->RemoveObject();
		_collisionManager->AddObject(player);
	}
	else
	{
		_collisionManager->AddObject(player);
	}
	
	Vector2 temp(player->GetPosition());
	std::cout << "Ship: X: "<< temp.x << " Y: " << temp.y << std::endl;
	return true;
}