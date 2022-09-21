#include "GameMap.h"

GameMap::GameMap()
{
}

GameMap::~GameMap()
{
}

void GameMap::Render()
{
    for (Layer* layer : m_MapLayers)
    {
        layer->Render();
    }
}

void GameMap::Update()
{
    for (Layer* layer : m_MapLayers)
    {
        layer->Update();
    }
}

int GameMap::MapLayerCount()
{
    return m_MapLayers.size();
}

void GameMap::InsertMapLayer(Layer *p_MapLayer)
{
    m_MapLayers.push_back(p_MapLayer);
}
