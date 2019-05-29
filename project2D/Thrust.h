#pragma once
#include "GameObject.h"
class Thrust : public GameObject
{
public:
	Thrust(const char* FileName);
	~Thrust();

	void Update(float deltaTime);

	float _Speed;
	bool _FireToggle;
	float _Acceleration;
};
