#pragma once
#include <SDL.h>
#include <vector>
#include "Textures.h"

class TextureManager {

public:
	TextureManager();
	~TextureManager();

	void CreateTexture(); // If a new texture ever needs to be added.
	void RemoveTexture(); // Removes a texture from the list.
	SDL_Texture GetTexture(); // Gets the texture from the list.

private:
	std::vector<Texture>* m_textures; // List containing the textures.

	void LoadTextures(); // Loads all textures from the textures folder.
};
