#include "Game.h"
#include "SDL.h"
#include <stdio.h>
#include <iostream>

Game::Game() {
	Start();

	SDL_Event event;

	while (m_running) {
		
		m_prevFrameTime = m_frameTime;
		m_frameTime = SDL_GetPerformanceCounter();

		m_deltaTime = (double)(m_frameTime - m_prevFrameTime) * 1000 / SDL_GetPerformanceFrequency(); 

		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT) {
			m_running = false;
			break;
		}

		if (event.type == SDL_KEYDOWN) {
			m_playerController->KeyDownCatch(event);
		}

		if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_r) {
			m_entityManager->CreateEntity("test", "mob", Vector2D(32, 32));
		}
		
		Update();
		Draw();

		//std::cout << "SDL_GetError: " << SDL_GetError() << std::endl;
	}

	End();
}

Game::~Game() {
	delete m_window;
}

void Game::Start() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL failed to initialise. Error: ", SDL_GetError());
		return;
	}

	m_res = new Resolution;

	// Parameters: Title, X position, Y position, width, height, flags.
	m_window = SDL_CreateWindow("Mario SDLv2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_res->x, m_res->y, SDL_WINDOW_OPENGL);
	if(!m_window)	std::cout << "Failed to create window: " << SDL_GetError() << std::endl;

	m_renderManager = new RenderManager(m_window, m_res);
	m_texManager = new TextureManager(m_renderManager->GetRenderer());
	m_entityManager = new EntityManager(m_renderManager->GetRenderer(), m_texManager);
	m_renderManager->SetEntityManager(m_entityManager);

	m_playerController = new PlayerController(m_entityManager);

	m_frameTime = SDL_GetPerformanceCounter();
}

void Game::Update() {
	
	// Managers
	m_entityManager->ProcessEntities();

	// Controllers
	m_playerController->Tick();

	return;
}

void Game::Draw() {

	m_renderManager->ProcessRendering();

	return;
}

void Game::End() {

	m_running = false;

	SDL_DestroyWindow(m_window); // Destroy Window

	// Clean up
	SDL_Quit();

	return;
}
