#include "game.h";

Game::Game() {
	Start();

	while (m_running) {
		Update();
		Draw();
	}

	End();
	
	//SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

	
	// Close and destroy the window
	SDL_DestroyWindow(m_window);

	// Clean up
	SDL_Quit();
	return 0;
}

void Game::Start() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL failed to initialise. Error: ", SDL_GetError());
		return;
	}


	// Parameters: Title, X position, Y position, width, height, flags.
	m_window = SDL_CreateWindow("Mario SDLv2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_res.x, m_res.y, SDL_WINDOW_OPENGL);

	if (!m_window) { // If window has no value
		printf("Window failed to be created. Error: ", SDL_GetError());
		return;
	}
}

