#include "MapLayer.h"
#include "../Graphics/TextureManager/TextureManager.h"

MapLayer::MapLayer()
    :m_Matrix(nullptr), m_TileList()
{
}

MapLayer::MapLayer(int *p_Matrix, TilesetList &p_TileList)
    : m_Matrix(p_Matrix), m_TileList(p_TileList)
{
    for (Tileset &tile : m_TileList)
    {
        std::string src = tile.getImage().getSource();
        std::string path = "assets/" + src;
        TextureManager::GetInstance()->LoadTexture(tile.getName(), path.c_str());
    }
}

MapLayer::~MapLayer()
{
}

void MapLayer::Update()
{
    printf("Update");
}

void MapLayer::Render()
{
//    Tileset ts = m_TileList[0];
    // TextureManager::GetInstance()->DrawTile(ts.getName(), ts.TileSize, Vector2I(j * ts.TileSize, i * ts.TileSize), tileRow, tileCol);
}
