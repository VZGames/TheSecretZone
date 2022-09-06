#include "GameMap.h"

GameMap::GameMap()
{
}

GameMap::~GameMap()
{
}

void GameMap::Render()
{
}

void GameMap::Update()
{
}

void GameMap::InsertMapLayer(const MapLayer &p_MapLayer)
{
    m_MapLayers.push_back(p_MapLayer);
}
