#pragma once
#include "Global.h"
#include "Entities.h"
#include "TextureManager.h"
#include <vector>
class EntityManager {

	public:
		EntityManager(SDL_Renderer* renderer, TextureManager* texManager);
		~EntityManager();

		void ProcessEntities();

		int CreateEntity(std::string name, std::string type, Vector2D size);
		void RemoveEntity(int id);

		Entity* GetEntity(int id);

		void RenderEntities();
		
	private:
		std::vector<Entity*>* m_entities;

		TextureManager* m_texManager;
		SDL_Renderer* m_renderer;
};