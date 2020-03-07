#pragma once
#include "Global.h"
#include <variant>
#include <vector>

enum class TileType {
	EMPTY = 0,
	ROCK,
	BRICK,
	GREYBRICK,
	BLOCK,
	QUESTIONBLOCK,
	ENTITYSPAWN
};

class Tile {
	private:
		TileType* m_type;

		VectorF2D* m_size = new VectorF2D(32,32);

		SDL_Rect* m_transRect;
		SDL_Rect* m_srcRect;

		TileType* CharToType(const char& cstr);

		void GenerateTexture(const TileType* type);

		bool m_animated = false;
		int m_frameInterval = 0;
		int m_frameDelay = 0;
		int m_frameCount = 0;
		int m_frame = 0;

	public:
		Tile(const char& type, VectorF2D pos);
		~Tile();

		void ChangeType(const TileType type);

		VectorF2D GetTilePos() const { return VectorF2D(m_transRect->x, m_transRect->y); };
		bool IsAnimated() const { return m_animated; };
		SDL_Rect* GetTransRect() const { return m_transRect; };
		SDL_Rect* GetSrcRect() const { return m_srcRect; };


		void UpdateSprite();

};