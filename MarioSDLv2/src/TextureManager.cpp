#include <TextureManager.h>
#include <filesystem>
#include <iostream>

TextureManager::TextureManager(SDL_Renderer* renderer) {
	m_renderer = renderer;
	m_textures = new std::vector<Texture*>;
}

TextureManager::~TextureManager() {
	for (int i = 0; i < m_textures->size(); i++) {
		delete m_textures->at(i);
	}
	delete m_textures;
}

void TextureManager::CreateTexture(std::string id, std::string cat) {
	Texture* tex = new Texture(id, cat, m_renderer);
	m_textures->push_back(tex);
}

void TextureManager::RemoveTexture(std::string id) {
	for (int i = 0; i < m_textures->size(); i++) {
		if (id.c_str() == m_textures->at(i)->GetID().c_str()) { // If ID is equal to the texture's ID.
			m_textures->erase(m_textures->begin() + i);
		}
	}
}

Texture* TextureManager::GetTexture(std::string id, std::string cat) {
	std::string null = "";
	Texture* result = new Texture(null, null, m_renderer);

	for (int i = 0; i < m_textures->size(); i++) {
		if (id == m_textures->at(i)->GetID()) { // If ID is equal to the texture's ID.
			result = m_textures->at(i);
		}
	}
	
	if (result->GetID() == "") {
		std::cout << "Texture not found, creating new texture...\n";
		CreateTexture(id, cat);
		result = GetTexture(id, cat);
	}
	
	return result;
}

void TextureManager::LoadTextures() {

}