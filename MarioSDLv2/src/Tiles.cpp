#include "Global.h"
#include "Tiles.h"
#include "EntityManager.h"
#include <iostream>

Tile::Tile(const char& type, VectorF2D pos) {
	m_transRect = new SDL_Rect();

	// Strangely, SDL_Rect does not want to construct properly with x,y,w,h parameters.
	// I have to do this manually here.
	m_transRect->x = pos.x * m_size->x;
	m_transRect->y = pos.y * m_size->y;
	m_transRect->w = m_size->x; m_transRect->h = m_size->y;

	ChangeType(*CharToType(type));
}

Tile::~Tile() {
	delete m_type;
	delete m_size;
	delete m_transRect;
}


TileType* Tile::CharToType(const char& cstr) {
	switch (cstr) {
		case '0':
			return new TileType(TileType::EMPTY);
			break;
		case '1':
			return new TileType(TileType::BRICK);
			break;
	}
}

void Tile::ChangeType(const TileType type) {
	if (m_type != nullptr) { delete m_type; }
	m_type = new TileType(type);

	GenerateTexture(m_type);
}

void Tile::GenerateTexture(const TileType* type) {
	m_srcRect = new SDL_Rect();
	
	int typeNum = (int)*type;

	if (typeNum) typeNum -= 1;

	m_srcRect->y = typeNum * m_transRect->h;
	m_srcRect->w = m_size->x; m_srcRect->h = m_size->y;

	switch (*type) {
			case TileType::QUESTIONBLOCK:

				m_animated = true;

				m_frameInterval = 0;
				m_frameDelay = 45;
				m_frameCount = 4;
				break;
	}
}

void Tile::UpdateSprite() {
	if (!m_animated) return;

	if (m_frameInterval > m_frameDelay) {

		m_frame++;
		if (m_frame > m_frameDelay)	m_frame = 0;

		m_frameInterval = 0;
	}

	m_srcRect->x = m_frame * m_transRect->w;
}


