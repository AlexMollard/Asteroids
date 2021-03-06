#pragma once
#include "GameObject.h"
#include "Renderer2D.h"

class Tank : public GameObject
{
public:
	Tank();
	~Tank();

	void Update(float deltaTime);
	void OnCollision(GameObject* OtherObject);
	void Hit();
	float GetTimer();
	std::string GetName();

	aie::Texture* GetShipTexture();
	aie::Texture* GetShipHitTexture();
	void SetTexture(aie::Texture* tex);

	int GetHealth();

	std::string _Name;
	float _Speed;
	int _Health;
	float time;
	float _Acceleration = 0.0f;
	Vector2 _Velocity;
	Vector2 _Position;
	Vector2 ForwardBuf;
	Vector2 _PrevPos;
	float _Timer;

	aie::Texture*	_ShipTexture;
	aie::Texture*	_ShipTextureFlash;
};