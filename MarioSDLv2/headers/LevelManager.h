#pragma once
#include "Global.h"
#include "Tiles.h"

class LevelManager {
	private:


		int m_maxLevels = 40; // 40 levels at most, it's not required, used for hashing.


		std::vector<std::string> m_levelList;


		struct grid {
			SDL_Rect m_bounding;
			std::vector<std::vector<Tile*>*>* m_tiles;

			bool m_isActive = false;
		};

		std::vector<grid*>* m_tileGrid;

		Vector2D* m_levelSize;
		
		int m_level;

		void ProcessTiles();

		void GenerateLevelList();

	public:
		LevelManager();
		~LevelManager();

		void LoadLevel();
		void UnloadLevel();

		Tile* GetTile(Vector2D pos);

		void Update();

		void LoadLevel(int index);
};