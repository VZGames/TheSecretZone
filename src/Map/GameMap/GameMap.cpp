#include "GameMap.h"

GameMap::GameMap()
{
}

void GameMap::Render()
{
    for (auto &layer : m_MapLayers)
    {
        layer->Render();
    }
}

void GameMap::Update()
{
    for (auto &layer : m_MapLayers)
    {
        layer->Update();
    }
}
