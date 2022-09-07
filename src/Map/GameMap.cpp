#include "GameMap.h"

GameMap::GameMap()
{
}

GameMap::~GameMap()
{
}

void GameMap::Render()
{
    for (auto &layer : m_MapLayers)
    {
        layer.Render();
    }
}

void GameMap::Update()
{
    for (auto &layer : m_MapLayers)
    {
        layer.Update();
    }
}

void GameMap::InsertMapLayer(const MapLayer &p_MapLayer)
{
    m_MapLayers.push_back(p_MapLayer);
}
