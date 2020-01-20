#include "Game.h"
#include "SDL.h"
#include <stdio.h>


Game::Game() {
	Start();

	SDL_Event event;

	while (m_running) {
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT) {
			m_running = false;
			break;
		}
		
		Update();
		Draw();


	}

	End();
	
	//SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

}

Game::~Game() {
	delete m_window;
	delete m_renderer;
}

void Game::Start() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL failed to initialise. Error: ", SDL_GetError());
		return;
	}

	// Parameters: Title, X position, Y position, width, height, flags.
	m_window = SDL_CreateWindow("Mario SDLv2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_res.x, m_res.y, SDL_WINDOW_OPENGL);

	// Parameters: Window, index, flags.
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

	// Parameters: Renderer, pixel format, flags, width, height
	m_texTarget = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_TARGET, m_res.x, m_res.y);

	m_texRect.x = 50;
	m_texRect.y = 50;

	m_texRect.w = 128;
	m_texRect.h = 128;

	m_srcRect.x = 32;
	m_srcRect.y = 0;
	m_srcRect.w = 64;
	m_srcRect.h = 64;

	tex = new Texture("entity", m_renderer);

	if (!m_window) { // If window has no value
		printf("Window failed to be created. Error: ", SDL_GetError());
		return;
	}
}

void Game::Update() {
	return;
}

void Game::Draw() {

	SDL_SetRenderTarget(m_renderer, m_texTarget);
	
	SDL_RenderClear(m_renderer);

	SDL_RenderCopy(m_renderer, tex->GetTexture(), &m_srcRect, &m_texRect);
	
	SDL_SetRenderTarget(m_renderer, NULL);

	SDL_RenderClear(m_renderer);

	SDL_RenderCopyEx(m_renderer, m_texTarget, NULL, NULL, 0, NULL, SDL_FLIP_NONE);

	SDL_RenderPresent(m_renderer);

	return;
}

void Game::End() {

	m_running = false;

	SDL_DestroyWindow(m_window); // Destroy Window

	// Clean up
	SDL_Quit();

	return;
}
