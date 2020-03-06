#pragma once
#include "Global.h"
#include "Entities.h"
#include "TextureManager.h"
#include <vector>
class EntityManager {		
	private:
		std::vector<Entity*>* m_entities;

		TextureManager* m_texManager;
		SDL_Renderer* m_renderer;

	public:
		EntityManager(SDL_Renderer* renderer, TextureManager* texManager);
		~EntityManager();

		void ProcessEntities();

		int CreateEntity(std::string name, std::string type, Vector2D size, Vector2D pos = Vector2D(0, 0));
		void RemoveEntity(int id);

		Entity* GetEntity(int id);

		void RenderEntities();

		TextureManager* GetTextureManager() const {	return m_texManager; };

};