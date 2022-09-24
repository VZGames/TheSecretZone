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
    for (int i = 0; i < m_Row; i++)
    {
        for (int j = 0; j < m_Col; j++)
        {
            int tileID = *(m_Matrix + (i * m_Col) + j);
//            printf("[%d][%d]: %d,", i, j, *(m_Matrix + (i * m_Col) + j))); // 1 row unit <=> i * p_Width
        }
        printf("\n");
    }
//    for (int row = 0; row < m_Row; row++) {
//        for (int col = 0; col < m_Col; col++) {
//            Tileset ts = m_TileList[0];
//            int tileSize = ts.getWidth(); /// or ts.getHeight();
//            int tileID = *(m_Matrix + (row * m_Col) + col);
//            int tileRow = tileID / ts.getColumns();
//            int tileCol = tileID - tileRow * ts.getColumns() - 1;

//            if (tileID % ts.getColumns() == 0)
//            {
//                tileRow--;
//                tileCol = ts.getColumns() - 1;
//            }
////            printf("FirstID: %d, LastID: %d, TileID: %d\n", ts.getFirstID(), ts.getLastID(), tileID);
//            //            TextureManager::GetInstance()->DrawTile(ts.getName(), tileSize, Vector2I(col * tileSize, row * tileSize), tileRow, tileCol);
//        }
//    }
}
