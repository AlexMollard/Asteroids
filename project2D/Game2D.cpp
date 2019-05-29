#include "Game2D.h"
#include <stdio.h>
#include <string.h>
#include "Application.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Level.h"
#include "AsteroidManager.h"
#include <iostream>

Game2D::Game2D(const char* title, int width, int height, bool fullscreen) : Game(title, width, height, fullscreen)
{
	// Initalise the 2D renderer.
	m_2dRenderer = new aie::Renderer2D();

	_Level = new Level();
	_Astroids = new AsteroidManager();

	m_texture = new aie::Texture("./textures/space2.png");
	_Font = new aie::Font("./font/consolas.ttf", 24);

	//Star gen
	for (int i = 0; i < 50; i++)
	{
		starX[i] = rand() % width;
		starY[i] = rand() % width;
	}

	timer = 3;
	_Shake = 100;
	_DefaultCamX;
	_DefaultCamY;
	m_2dRenderer->GetCameraPos(_DefaultCamX, _DefaultCamY);

	this->height = height;
	this->width = width;

	frame = 60;
}

Game2D::~Game2D()
{
	delete _Level;
	_Level = nullptr;

	delete _Font;
	_Font = nullptr;

	delete _Astroids;
	_Astroids = nullptr;

	// Delete the renderer.
	delete m_2dRenderer;

	delete m_texture;
}

void Game2D::Update(float deltaTime)
{
	aie::Application* application = aie::Application::GetInstance();
	aie::Input* input = aie::Input::GetInstance(); 
	_Level->Update(deltaTime);
	_Level->UpDateGlobalTransform();

	_Astroids->Update(deltaTime);
	_Astroids->UpDateGlobalTransform();

	//Check if ship hits asteroid
	if (_Astroids->CheckForCollisions(_Level->GetShip()) && timer >= 3)
	{
		_Level->GetShip()->Hit();
		timer = 0;
	}
	else if (timer <= 2.9 && timer >= 0)
	{
		timer += 1 * deltaTime;
		if (timer < 0.5)
			_Level->GetShip()->SetTexture(_Level->GetShip()->GetShipHitTexture());
		else if (timer < 1)
			_Level->GetShip()->SetTexture(_Level->GetShip()->GetShipTexture());
		else if (timer < 1.5)
			_Level->GetShip()->SetTexture(_Level->GetShip()->GetShipHitTexture());
		else if (timer < 2)
			_Level->GetShip()->SetTexture(_Level->GetShip()->GetShipTexture());
		else if (timer < 2.5)
			_Level->GetShip()->SetTexture(_Level->GetShip()->GetShipHitTexture());
		else if (timer < 3)
			_Level->GetShip()->SetTexture(_Level->GetShip()->GetShipTexture());
	}
	else if (timer >= 2.9)
	{
		timer = 3;
	}

	if (application->GetWindowWidth() != width || application->GetWindowHeight() != height)
	{
		width = application->GetWindowWidth();
		height = application->GetWindowHeight();

		for (int i = 0; i < 50; i++)
		{
			starX[i] = rand() % application->GetWindowWidth();
			starY[i] = rand() % application->GetWindowHeight();
		}
	}


	if (input->IsKeyDown(aie::INPUT_KEY_ESCAPE))
	{
		application->Quit(); 
	}
}

void Game2D::Draw()
{
	aie::Application* application = aie::Application::GetInstance();
	float time = application->GetTime();

	// Wipe the screen to clear away the previous frame.
	application->ClearScreen();

	// Prepare the renderer. This must be called before any sprites are drawn.
	m_2dRenderer->Begin();

	m_2dRenderer->DrawSprite(m_texture, 0, 0, width * 2, height * 2);

	char s[20];
	sprintf(s, "%d", _Level->GetShip()->GetHealth());

	m_2dRenderer->DrawText2D(_Font, "Health: ", 100, height - 100);
	m_2dRenderer->DrawText2D(_Font, s, 200, height - 100);

	//Timer
	char t[20];
	sprintf(t, "%.2f", -timer + 3);

	m_2dRenderer->DrawText2D(_Font, "No-Damage: ", 100, height - 150);
	m_2dRenderer->DrawText2D(_Font, t, 240, height - 150);

	for (int i = 0; i < 50; i++)
	{
		_size = rand() % 5;
		m_2dRenderer->DrawBox(starX[i] - 400, starY[i], _size, _size);
	}


	m_2dRenderer->SetRenderColour(1, 1, 1);

	_Level->Draw(m_2dRenderer);
	_Astroids->Draw(m_2dRenderer);


	// Done drawing sprites. Must be called at the end of the Draw().
	m_2dRenderer->End();
}