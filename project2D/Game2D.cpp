#include "Game2D.h"

#include "Application.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Level.h"
#include "Astroids.h"
#include <iostream>

Game2D::Game2D(const char* title, int width, int height, bool fullscreen) : Game(title, width, height, fullscreen)
{
	// Initalise the 2D renderer.
	m_2dRenderer = new aie::Renderer2D();

	_Level = new Level();
	_Astroids = new Astroids();

	m_texture = new aie::Texture("./textures/space2.png");

	for (int i = 0; i < 50; i++)
	{
		starX[i] = rand() % width;
		starY[i] = rand() % width;
	}

	

	this->height = height;
	this->width = width;

	frame = 60;
}

Game2D::~Game2D()
{
	delete _Level;
	_Level = nullptr;

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

	_Astroids->CheckForCollisions(_Level->GetShip());

	std::cout << application->GetFPS() << std::endl;

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

		for (int i = 0; i < 50; i++)
		{
			_size = rand() % 5;
			m_2dRenderer->DrawBox(starX[i] - 400, starY[i], _size, _size);
		}


	m_2dRenderer->SetRenderColour(1, 1, 1);

	_Astroids->Draw(m_2dRenderer);
	_Level->Draw(m_2dRenderer);


	// Done drawing sprites. Must be called at the end of the Draw().
	m_2dRenderer->End();
}