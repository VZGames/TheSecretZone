#include "MapLayer.h"
MapLayer::MapLayer()
{
}

MapLayer::MapLayer(int *p_Matrix, TilesetList &p_TileList)
    : m_Matrix(p_Matrix), m_TileList(p_TileList)
{
    for (Tileset &tile : m_TileList)
    {
        TextureManager::GetInstance()->LoadTexture(tile.getName(), tile.getImage()->getSource());
    }
}

MapLayer::~MapLayer()
{
}

void MapLayer::Update()
{
    SDL_Log("Update");
}

void MapLayer::Render()
{
    Tileset ts = m_TileList[0];
    // TextureManager::GetInstance()->DrawTile(ts.getName(), ts.TileSize, Vector2I(j * ts.TileSize, i * ts.TileSize), tileRow, tileCol);
}
