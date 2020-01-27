#include "RenderManager.h"
#include <iostream>

RenderManager::RenderManager(SDL_Window* window, Resolution* res) {

	m_res = new Resolution; m_res = res;

	// Parameters: Window, index, flags.
	if (!(m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE)))	std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
	
	// Parameters: Renderer, pixel format, flags, width, height
	m_texTarget = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_TARGET, m_res->x, m_res->y);
}

void RenderManager::ProcessRendering() {

	SDL_SetRenderTarget(m_renderer, m_texTarget); // Set the target to render textures to.

	SDL_RenderClear(m_renderer);

	m_entityManager->RenderEntities();

	SDL_SetRenderTarget(m_renderer, NULL); // Stop targetting the texture.

	SDL_RenderClear(m_renderer);

	SDL_RenderCopyEx(m_renderer, m_texTarget, NULL, NULL, 0, NULL, SDL_FLIP_NONE);

	SDL_RenderPresent(m_renderer);

	SDL_Delay(1);


}

void RenderManager::SetEntityManager(EntityManager* entityManager) { m_entityManager = entityManager; };