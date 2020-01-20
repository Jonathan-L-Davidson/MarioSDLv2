#pragma once
#include <string>
#include <SDL.h>

class Texture {
	public:
		Texture(std::string cat, std::string id, SDL_Renderer* renderer);
		~Texture();

		std::string GetID() const { return *m_id; };
		SDL_Texture* GetTexture() const { return m_texture; };
	private:
		std::string* m_id; // ID will be the filename of the image. Helps prevent duplicates.
		std::string* m_category;
		SDL_Texture* m_texture;

		void LoadTexture(SDL_Renderer* renderer);
};