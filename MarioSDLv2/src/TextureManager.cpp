#include <TextureManager.h>
#include <filesystem>

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


void TextureManager::CreateTexture(std::string cat, std::string name) {
	Texture* tex = new Texture(cat, name, m_renderer);
	m_textures->push_back(tex);
}

void TextureManager::RemoveTexture(std::string id) {
	for (int i = 0; i < m_textures->size(); i++) {
		if (id.c_str() == m_textures->at(i)->GetID().c_str()) { // If ID is equal to the texture's ID.
			m_textures->erase(m_textures->begin() + i);
		}
	}
}

SDL_Texture* TextureManager::GetTexture(std::string id) {
	int i; // Initialised outside the loop in order to successfuly return the texture.

	for (i = 0; i < m_textures->size(); i++) {
		if (id.c_str() == m_textures->at(i)->GetID().c_str()) { // If ID is equal to the texture's ID.
			break;
		}
	}

	return m_textures->at(i - 1)->GetTexture(); // int i - 1 as the for loop adds an extra 1 after break;
}

void TextureManager::LoadTextures() {

}