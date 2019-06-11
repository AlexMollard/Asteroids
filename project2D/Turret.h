#pragma once
#include "GameObject.h"
#include "BulletManager.h"

class Turret : public GameObject
{
public:
	// Constructor
	Turret(const char* FileName);

	// Functions
	void Update(float deltaTime);
	void UpdateMouse(float deltaTime);

	// Shooting
	void SetShooting(bool setting);
	bool GetShooting();

	//Collider

	// Variables
	int counter;
	float _Speed;
	bool _Shooting;
	float _Acceleration;

	BulletManager* _BulletPool;
};

//Create an objectpool class
	//creates array of bullets

//Each bullet would have a bool to say if its alive
	//default to false

//Turret would have an instance of the object pool

//In turrets update, checks for mouse click
	//if mouse clicked
		//ask object pool for the next bullet
		//tells bullet to fire and passes in direction
			//bullet fire() would set alive to true and store direction