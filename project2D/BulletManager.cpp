#include "BulletManager.h"
#include <iostream>

using namespace std;

BulletManager::BulletManager()
{
	SetName("Bullet Manager");

	// Set all bullets parent to be the level
	for (int i = 0; i < 10; i++)
	{
		_Bullet[i] = new Bullet("./textures/Bullet.png");
		_Bullet[i]->SetParent(this);
		_Bullet[i]->SetName("Bullet");
	}
	_OldestBullet = new Bullet("./textures/Bullet.png");
	_OldestBullet->SetTimeAlive(-10);
	_OldestBullet->SetName("Bullet");
}

BulletManager::~BulletManager()
{
	if (_OldestBullet)
	{
		delete _OldestBullet;
		_OldestBullet = nullptr;
	}
}

Bullet* BulletManager::GetBullet()
{
	for (int i = 0; i < 10; i++)
	{
		if (!_Bullet[i]->GetAlive())
		{
			return _Bullet[i];
		}
		else if (AreAllBulletsAlive())
		{
			_OldestBullet->SetTimeAlive(-10.0f);
			for (int n = 0; n < 10; n++)
			{
				if (_Bullet[n]->GetTimeAlive() > _OldestBullet->GetTimeAlive())
				{
					_OldestBullet = _Bullet[n];
				}
			}
			return _OldestBullet;
		}
	}
}

bool BulletManager::AreAllBulletsAlive()
{
	for (int i = 0; i < 10; i++)
	{
		if (_Bullet[i]->GetAlive() == false)
		{
			return false;
		}
	}
	return true;
}

