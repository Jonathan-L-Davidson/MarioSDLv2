#include "EntityManager.h"
#include <iostream>

EntityManager::EntityManager(SDL_Renderer* renderer, TextureManager* texManager) {
	m_entities = new std::vector<Entity*>;

	m_renderer = renderer;
	m_texManager = texManager;
}

EntityManager::~EntityManager() {

}

void EntityManager::ProcessEntities() {
	for (int i = 0; i < m_entities->size(); i++) {
		m_entities->at(i)->Update();
	}
}

int EntityManager::CreateEntity(std::string name, std::string type, Vector2D size, Vector2D pos) {
	int id = m_entities->size() + 1;
	Entity* ent = new Entity(name, type, size, id);
	
	ent->SetTexture(m_texManager->GetTexture(name, "entity"));
	ent->MoveBody(pos);
	m_entities->push_back(ent);
	
	return id;
}

void EntityManager::RemoveEntity(int id) {
	for (int i = 0; i < m_entities->size(); i++) {
		if (id == m_entities->at(i)->GetID()) {
			m_entities->erase(m_entities->begin() + i);
		}
	}
}

Entity* EntityManager::GetEntity(int id) {
	for (int i = 0; i < m_entities->size(); i++) {
		if (id == m_entities->at(i)->GetID()) { // If ID is equal to the texture's ID.
			return m_entities->at(i);
		}
	}
}

void EntityManager::RenderEntities() {
	for (int i = 0; i < m_entities->size(); i++) {
		if(m_entities->at(i) == NULL)	return;
		
		Entity* ent = m_entities->at(i);
		SDL_RenderCopy(m_renderer, ent->GetTexture(), &ent->GetSrcRect(), &ent->GetBody());
	}
}

/*

class EntityManager {

	public:
		EntityManager();
		~EntityManager();

		void ProcessEntities();

		void CreateEntity();
		void RemoveEntity();

		Entity* GetEntity(int id);

		void RenderEntities(SDL_Renderer* renderer);

	private:
		std::vector<Entity*>* m_entities;

		SDL_Renderer* m_renderer;

*/