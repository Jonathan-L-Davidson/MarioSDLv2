#include "LevelManager.h"
#include "Helpers.h"
#include <string>
#include <fstream>
#include <Windows.h>


LevelManager::LevelManager(SDL_Renderer* renderer, EntityManager* entityManager) {
    m_levelSize = new Vector2D(0,0);
    m_levelList.resize(m_maxLevels);

    m_renderer = renderer;
    m_entityManager = entityManager;
    m_textureManager = m_entityManager->GetTextureManager();
       
    GenerateLevelList();

}

LevelManager::~LevelManager() {

}

void LevelManager::LoadLevel(std::string input) {
    if (m_levelLoaded) {
        UnloadLevel();
    }

    std::string path = levelDir + input + ".lvl";

    std::fstream inputFile;
    inputFile.open(path);

    if (!inputFile) { SDL_SetError("LoadLevel() - inputFile failed to open"); return; };

    std::vector<std::string> fileData;

    for (std::string line; getline(inputFile, line);) {
        fileData.push_back(line); // I know that I can instead parse all the data here and such, however I would prefer to store it in a vector so I can sanity check the file and such.
    }

    m_levelSize->x = fileData.at(0).length();
    m_levelSize->y = fileData.size();

    if (!SanityCheckLevelFile(fileData)) return;

    int gridAmount = m_levelSize->x / m_gridSize;

    if (m_levelSize->x % m_gridSize) gridAmount += 1;
    
    m_grid.resize(gridAmount);
    
    for (int i = 0; i < gridAmount; i++) {
        m_grid.at(i) = new Grid;    
        m_grid.at(i)->m_tiles.resize(m_levelSize->y);

        for (int j = 0; j < m_levelSize->y; j++) {
            for (int k = 0; k < m_levelSize->x; k++) {
                m_grid.at(i)->m_tiles.at(j).push_back(new Tile(fileData.at(j).at(k), VectorF2D(k, j)));
            }
        }
    }
    
    m_levelTexture = m_textureManager->GetTexture(input, "tiles");

}

void LevelManager::UnloadLevel() {

}

Tile* LevelManager::GetTile(Vector2D pos) {
    return nullptr;
}

void LevelManager::ProcessTiles() {

}

void LevelManager::GenerateLevelList() {
    
    // This code can be seen in Helpers.h
    // Reference code - START
    stringvec fileList;

    read_directory(levelDir , fileList);
    // Reference code - END

    int hash;

    for (std::string i : fileList) {
        if(i.substr(i.find_last_of(".") + 1) == "lvl"){
            
            const char* cstr = i.c_str();

            hash = 0;
            for (int x = 0; x < i.size(); x++) {
                hash += int(i.at(x));

            }
            m_levelList.at(hash % m_maxLevels) = i;
        }
    }    
}

bool const LevelManager::SanityCheckLevelFile(std::vector<std::string>& file) {
    for (int i = 0; i < file.size(); i++) {
        if (file.at(i).length() != m_levelSize->x) {
            SDL_SetError("LoadLevel() - Level file structure is incorrect");
            return false;
        }
    }
}


void LevelManager::Update() {

}


void LevelManager::RenderTiles() {
    for (int i = 0; i < m_grid.size(); i++) {
        for (int j = 0; j < m_levelSize->y; j++) {
            for (int k = 0; k < m_levelSize->x; k++) {
                Tile* tile = m_grid.at(i)->m_tiles.at(j).at(k);
                SDL_RenderCopy(m_renderer, m_levelTexture->GetTexture(), tile->GetSrcRect(), tile->GetTransRect());
            }
        }
    }
}