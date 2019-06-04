#include "BulletManager.h"


BulletManager::BulletManager()
{
	SetName("Bullet Manager");

	// Set all bullets parent to be the level
	for (int i = 0; i < 10; i++)
	{
		_Bullet[i] = new Bullet("./textures/Bullet.png");
		_Bullet[i]->SetParent(this);
	}
}

void BulletManager::Update(float deltaTime, bool shooting, Vector2 _NewRotation) 
{
	if (shooting)
	{
		//GetBullet()->Fire(_NewRotation);
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
	}

	// No bullets alive

	// Take longest alive bullet and kill it
}