#pragma once
#include "Global.h"
#include "EntityManager.h"
#include "Tiles.h"

class LevelManager {
	private:
		SDL_Renderer* m_renderer;
		EntityManager* m_entityManager;
		TextureManager* m_textureManager;

		Texture* m_levelTexture;

		Vector2D* m_levelSize;
		

		int m_maxLevels = 40; // 40 levels at most, it's not required, used for hashing		
		int m_gridSize = 3;
		Vector2D m_tileSize = Vector2D(32,32);

		std::vector<std::string> m_levelList;


		struct Grid {
			SDL_Rect m_bounding;
			std::vector<std::vector<Tile*>> m_tiles;

			bool m_isActive = false;
		};

		std::vector<Grid*> m_grid;
		
		int m_level;

		void ProcessTiles();

		void GenerateLevelList();

		bool m_levelLoaded = false;

		bool const SanityCheckLevelFile(std::vector<std::string>& file);

	public:
		LevelManager(SDL_Renderer* renderer, EntityManager* entityManager);
		~LevelManager();

		void LoadLevel(std::string input);
		void UnloadLevel();

		Tile* GetTile(Vector2D pos);

		void Update();
		void RenderTiles();
};