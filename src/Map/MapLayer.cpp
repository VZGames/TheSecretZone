#include "MapLayer.h"
#include "../Graphics/TextureManager/TextureManager.h"

MapLayer::MapLayer()
    :m_Matrix(nullptr), m_TileList(), m_Row(0), m_Col(0)
{
}

MapLayer::MapLayer(int *p_Matrix, TilesetList &p_TileList, int p_Row, int p_Col)
    : m_Matrix(p_Matrix), m_TileList(p_TileList), m_Row(p_Row), m_Col(p_Col)
{
    for (Tileset &tile : m_TileList)
    {
        std::string src = tile.getImage().getSource();
        std::string path = "assets/" + src;
        TextureManager::GetInstance()->LoadTexture(tile.getName(), path.c_str());
    }
}

void MapLayer::Update()
{
    //    printf("MapLayer::Update\n");
}

void MapLayer::Render()
{
    //    printf("MapLayer::Render\n");
    for (int row = 0; row < m_Row; row++) {
        for (int col = 0; col < m_Col; col++) {
            Tileset ts = m_TileList[0];
            printf("FirstID: %d, LastID: %d\n", ts.getFirstID(), ts.getLastID());
            int tileSize = ts.getWidth(); /// or ts.getHeight();
            int tileID = ts.getFirstID();
            TextureManager::GetInstance()->DrawTile(ts.getName(), tileSize, Vector2I(col * tileSize, row * tileSize), row, 1);
        }
    }
}
