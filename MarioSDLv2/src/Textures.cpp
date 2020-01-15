#include "Textures.h"
#include <iostream>

Texture::Texture(std::string id, SDL_Renderer* renderer) {
	m_id = new std::string(id);
	LoadTexture(renderer);
}

Texture::~Texture() {
	delete m_id;
	delete m_texture;
}

void Texture::LoadTexture(SDL_Renderer* renderer) {
	std::string* path = new std::string("./resources/" + *m_id + ".bmp");

	if (SDL_Surface* surface = SDL_LoadBMP(path->c_str())) {
		m_texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface); // "deletes" the surface. We need hardware accelerated rendering and not software based.
	}
	else {
		std::cout << SDL_GetError() << std::endl;
	}

	delete path;

	// SDL 2.0 provides hardware based rendering by allowing you to use SDL_Textures
	// SDL_Textures load into the VRAM in the graphics card, while SDL_Surface loads into the system memory such as your RAM.
	// We need to load it into system memory before loading it into the VRAM, destroying it later once it's loaded as a texture allows this to work.
}