#include "Level.h"
#include "Thrust.h"


Level::Level()
{
	SetName("Level");
	_Score = 0;
	_collisionManager = new CollisionManager();

	_Tank = new Tank();
	_Tank->SetParent(this);
	_Tank->SetPosition(Vector2(500,500));
	_Tank->UpDateGlobalTransform();
	_collisionManager->AddObject(_Tank);

	_Turret = new Turret("./textures/Gun.png");
	_Turret->SetParent(_Tank);
	_Turret->SetPosition(Vector2(0, 0));
	_Turret->UpDateGlobalTransform();

	for (int i = 0; i < 10; i++)
		_collisionManager->AddObject(_Turret->_BulletPool->_Bullet[i]);

	Thrust* _Thrust = new Thrust("./textures/Thrust.png");
	_Thrust->SetParent(_Tank);
	_Thrust->SetPosition(Vector2(0, -25));
	_Thrust->UpDateGlobalTransform();

	_Astroids = new AsteroidManager(_collisionManager);
	_Astroids->SetParent(this);
	_Astroids->SetPosition(Vector2(0, 0));
	_Turret->UpDateGlobalTransform();
}

Level::~Level()
{
	delete _collisionManager;
	_collisionManager = nullptr;
}

void Level::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
	_collisionManager->Update(deltaTime);
}

void Level::Draw(aie::Renderer2D* renderer)
{
	GameObject::Draw(renderer);
	_collisionManager->Draw(renderer);
}

Tank* Level::GetShip()
{
	return _Tank;
}

Turret* Level::GetTurret()
{
	return _Turret;
}

Bullet* Level::GetBullet()
{
	return _Bullet;
}

