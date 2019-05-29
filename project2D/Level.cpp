#include "Level.h"

#include "Turret.h"
#include "Thrust.h"


Level::Level()
{
	_collisionManager = new CollisionManager();

	_Tank = new Tank("./textures/newShip.png");
	_Tank->SetParent(this);
	_Tank->SetPosition(Vector2(500,500));
	_Tank->UpDateGlobalTransform();
	_collisionManager->AddObject(_Tank);

	Turret* _Turret = new Turret("./textures/Gun.png");
	_Turret->SetParent(_Tank);
	_Turret->SetPosition(Vector2(0, 0));
	_Turret->UpDateGlobalTransform();
	//_collisionManager->AddObject(_Turret);

	Thrust* _Thrust = new Thrust("./textures/Thrust.png");
	_Thrust->SetParent(_Tank);
	_Thrust->SetPosition(Vector2(0, -25));
	_Thrust->UpDateGlobalTransform();

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