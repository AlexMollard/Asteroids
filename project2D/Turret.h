#pragma once
#include "GameObject.h"
class Turret : public GameObject
{
public:
	Turret(const char* FileName);
	~Turret();

	void Update(float deltaTime);


	float _Speed;
	bool _FireToggle;
	float _Acceleration;
};

