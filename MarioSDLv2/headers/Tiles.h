#pragma once
#include "Global.h"
#include "Entities.h"
#include <variant>
#include <vector>

enum class TileType {
	ROCK,
	BRICK,
	GREYBRICK,
	BLOCK,
	QUESTIONBLOCK,
	ENTITYSPAWN
};

class Tile {
	private:
		std::vector<std::vector<Tile*>*>* m_tiles;
		TileType* m_type;
		Entity* m_tileEntity;

		Vector2D m_tilePos;

	public:
		Tile(TileType type, Vector2D pos);
		~Tile();

		SDL_Rect GetTileRect() const { return m_tileEntity->GetBody(); };
		Vector2D GetTilePos() const { return m_tilePos; };

};