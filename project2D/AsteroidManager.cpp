#include "AsteroidManager.h"
#include "Application.h"
#include <iostream>

AsteroidManager::AsteroidManager(CollisionManager* collisionManager)
{
	aie::Application* application = aie::Application::GetInstance();

	for (int i = 0; i < 4; i++)
	{
		_AsteroidsSmall[i] = new Astroid("./textures/rock_small.png");
		_AsteroidsSmall[i]->SetParent(this);
		collisionManager->AddObject(_AsteroidsSmall[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		_AsteroidsSmallBlue[i] = new Astroid("./textures/rock_small_blue.png");
		_AsteroidsSmallBlue[i]->SetParent(this);
		collisionManager->AddObject(_AsteroidsSmallBlue[i]);
	}
	
	for (int i = 0; i < 4; i++)
	{
		_AsteroidsLarge[i] = new Astroid("./textures/rock_large.png");
		_AsteroidsLarge[i]->SetParent(this);
		collisionManager->AddObject(_AsteroidsLarge[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		_AsteroidsLargeGreen[i] = new Astroid("./textures/rock_large_green.png");
		_AsteroidsLargeGreen[i]->SetParent(this);
		collisionManager->AddObject(_AsteroidsLargeGreen[i]);
	}

	for (int i = 0; i < 2; i++)
	{
		_AsteroidsLargeBlue[i] = new Astroid("./textures/rock_large_blue.png");
		_AsteroidsLargeBlue[i]->SetParent(this);
		collisionManager->AddObject(_AsteroidsLargeBlue[i]);
	}
}


AsteroidManager::~AsteroidManager()
{
}


void AsteroidManager::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}

void AsteroidManager::Draw(aie::Renderer2D* renderer)
{
	GameObject::Draw(renderer);
}

Astroid* AsteroidManager::GetSmallAsteroid(int index)
{
	return _AsteroidsSmall[index];
}

Astroid* AsteroidManager::GetLargeAsteroid(int index)
{
	return _AsteroidsLarge[index];
}