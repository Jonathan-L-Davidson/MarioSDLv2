#include "Game.h"
#include "SDL.h"
#include <stdio.h>
#include <iostream>

Game::Game() {
	Start();

	SDL_Event event;

	const Uint8* state = new Uint8;

	while (m_running) {
		state = SDL_GetKeyboardState(NULL);


		m_prevFrameTime = m_frameTime;
		m_frameTime = SDL_GetPerformanceCounter();

		m_deltaTime = (double)(m_frameTime - m_prevFrameTime) * 1000 / SDL_GetPerformanceFrequency();

		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				m_running = false;
				break;
			}

			if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
				m_playerController->KeyboardEvent(event, state);
			}

			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_r) {
				m_entityManager->CreateEntity("test", "mob", Vector2D(32, 32));
			}
		}
		
		Update();
		Draw();

		if (strlen(SDL_GetError())) {
			std::cout << "Error Found: " << SDL_GetError() << std::endl;
			SDL_ClearError();
		}
	}

	End();
}

Game::~Game() {
	delete m_window;
}

void Game::Start() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL failed to initialise. Error: " << SDL_GetError() << std::endl;
		return;
	}

	m_res = new Resolution;

	// Parameters: Title, X position, Y position, width, height, flags.
	m_window = SDL_CreateWindow("Mario SDLv2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_res->x, m_res->y, SDL_WINDOW_OPENGL);
	if(!m_window)	std::cout << "Failed to create window: " << SDL_GetError() << std::endl;

	m_renderManager = new RenderManager(m_window, m_res);
	m_texManager = new TextureManager(m_renderManager->GetRenderer());
	m_entityManager = new EntityManager(m_renderManager->GetRenderer(), m_texManager);
	m_levelManager = new LevelManager(m_renderManager->GetRenderer(), m_entityManager);
	m_renderManager->SetEntityManager(m_entityManager);
	m_renderManager->SetLevelManager(m_levelManager);

	m_playerController = new PlayerController(m_entityManager, m_deltaTime);

	m_frameTime = SDL_GetPerformanceCounter();

	m_levelManager->LoadLevel("MainLevel");
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
