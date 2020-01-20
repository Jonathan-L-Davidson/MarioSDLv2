#pragma once
#include <SDL.h>
#include <vector>
#include "Textures.h"

class TextureManager {

public:
	TextureManager(SDL_Renderer* renderer);
	~TextureManager();

	void CreateTexture(std::string cat, std::string name); // If a new texture ever needs to be added.
	void RemoveTexture(std::string id); // Removes a texture from the list.
	SDL_Texture* GetTexture(std::string id); // Gets the texture from the list.

private:
	std::vector<Texture*>* m_textures; // List containing the textures.
	SDL_Renderer* m_renderer;
	void LoadTextures(); // Loads all textures from the textures folder.
};
