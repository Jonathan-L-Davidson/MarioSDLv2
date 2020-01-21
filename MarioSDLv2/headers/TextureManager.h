#pragma once
#include <SDL.h>
#include <vector>
#include "Textures.h"

class TextureManager {

public:
	TextureManager(SDL_Renderer* renderer);
	~TextureManager();

	void CreateTexture(std::string id, std::string cat); // If a new texture ever needs to be added.
	void RemoveTexture(std::string id); // Removes a texture from the list.
	Texture* GetTexture(std::string id, std::string cat); // Gets the texture from the list.

private:
	std::vector<Texture*>* m_textures; // List containing the textures.
	SDL_Renderer* m_renderer;
	void LoadTextures(); // Loads all textures from the textures folder.
};
