#include "LevelManager.h"
#include <Windows.h>
#include "Helpers.h"

LevelManager::LevelManager() {
    m_levelList.resize(m_maxLevels);
    GenerateLevelList();

}

LevelManager::~LevelManager() {

}

void LevelManager::Update() {

}

void LevelManager::LoadLevel() {

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
            std::cout << "Level found: " << levelDir+i << std::endl;
            m_levelList.at(hash % m_maxLevels) = levelDir+i;
        }
    }    
}

