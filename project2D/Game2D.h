#pragma once
#include "Game.h"
#include "Renderer2D.h"

class Player;
class Level;
class AsteroidManager;

class Game2D : public aie::Game
{
public:
	Game2D(const char* title, int width, int height, bool fullscreen);
	virtual ~Game2D();

	virtual void Update(float deltaTime);
	virtual void Draw();

	float starX[100000];
	float starY[100000];

	float width;
	float height;
	float _DefaultCamX;
	float _DefaultCamY;
	float timer;
	float score;
	float _size;
	float _Shake;
	int frame;
protected:
	aie::Renderer2D*	m_2dRenderer;

	// Example textures.
	aie::Texture*		m_texture;
	aie::Texture*		m_texture2;
	aie::Font*			_Font;

	// Player.
	Player* m_Player;

	Level* _Level;

	AsteroidManager* _Astroids;
};