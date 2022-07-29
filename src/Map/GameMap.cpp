#include "GameMap.h"

GameMap::GameMap()
{
}

void GameMap::Render()
{
    SDL_Log("RENDER: GameMap");
    for (unsigned int i = 0; i < m_MapLayers.size(); i++)
    {
        m_MapLayers[i]->Render();
    }
}

void GameMap::Update()
{
    SDL_Log("UPDATE: GameMap");
    for (unsigned int i = 0; i < m_MapLayers.size(); i++)
    {
        m_MapLayers[i]->Update();
    }
}