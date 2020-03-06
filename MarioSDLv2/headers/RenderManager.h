#pragma once
#include "Global.h"
#include "EntityManager.h"
#include "LevelManager.h"

class RenderManager {
	public:
		RenderManager(SDL_Window* window, Resolution* res);
		~RenderManager();

		SDL_Renderer* GetRenderer() const {	return m_renderer; };

		void SetEntityManager(EntityManager* entityManager);
		void SetLevelManager(LevelManager* levelManager);
		void ProcessRendering();

	private:
		SDL_Texture* m_texTarget;
		
		SDL_Renderer* m_renderer;
		EntityManager* m_entityManager;
		LevelManager* m_levelManager;

		Resolution* m_res;
};