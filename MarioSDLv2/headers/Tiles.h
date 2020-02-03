#pragma once
#include "Global.h"
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
		TileType* type;

	public:
		Tile(TileType type, Vector2D pos);
		~Tile();

};