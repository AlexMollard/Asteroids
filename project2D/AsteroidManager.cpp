#include "AsteroidManager.h"
#include "Application.h"
#include <iostream>

AsteroidManager::AsteroidManager()
{
	aie::Application* application = aie::Application::GetInstance();

	_collisionManager = new CollisionManager();

	for (int i = 0; i < 4; i++)
	{
		_AsteroidsSmall[i] = new Astroid("./textures/rock_small.png");
		_AsteroidsSmall[i]->SetParent(this);
		_AsteroidsSmall[i]->UpDateGlobalTransform();
		_collisionManager->AddObject(_AsteroidsSmall[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		_AsteroidsSmallBlue[i] = new Astroid("./textures/rock_small_blue.png");
		_AsteroidsSmallBlue[i]->SetParent(this);
		_AsteroidsSmallBlue[i]->UpDateGlobalTransform();
		_collisionManager->AddObject(_AsteroidsSmallBlue[i]);
	}
	
	for (int i = 0; i < 4; i++)
	{
		_AsteroidsLarge[i] = new Astroid("./textures/rock_large.png");
		_AsteroidsLarge[i]->SetParent(this);
		_AsteroidsLarge[i]->UpDateGlobalTransform();
		_collisionManager->AddObject(_AsteroidsLarge[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		_AsteroidsLargeGreen[i] = new Astroid("./textures/rock_large_green.png");
		_AsteroidsLargeGreen[i]->SetParent(this);
		_AsteroidsLargeGreen[i]->UpDateGlobalTransform();
		_collisionManager->AddObject(_AsteroidsLargeGreen[i]);
	}

	for (int i = 0; i < 2; i++)
	{
		_AsteroidsLargeBlue[i] = new Astroid("./textures/rock_large_blue.png");
		_AsteroidsLargeBlue[i]->SetParent(this);
		_AsteroidsLargeBlue[i]->UpDateGlobalTransform();
		_collisionManager->AddObject(_AsteroidsLargeBlue[i]);
	}
}


AsteroidManager::~AsteroidManager()
{
	delete _collisionManager;
	_collisionManager = nullptr;
}


void AsteroidManager::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
	_collisionManager->Update(deltaTime);
}

void AsteroidManager::Draw(aie::Renderer2D* renderer)
{
	GameObject::Draw(renderer);
	_collisionManager->Draw(renderer);
}

Astroid* AsteroidManager::GetSmallAsteroid(int index)
{
	return _AsteroidsSmall[index];
}

Astroid* AsteroidManager::GetLargeAsteroid(int index)
{
	return _AsteroidsLarge[index];
}

bool AsteroidManager::CheckForCollisions(Tank* player)
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
	if (player->GetCollided())
	{
		player->SetCollided(false);
		return true;
	}
	
	return false;
}