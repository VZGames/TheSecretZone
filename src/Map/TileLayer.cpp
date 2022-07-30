#include "TileLayer.h"
#include "../Graphics/TextureManager/TextureManager.h"

TileLayer::TileLayer(int p_tileSize, int p_numRows, int p_numCols, TileMap p_TileMap, TilesetsList p_tilesets)
    : m_TileSize(p_tileSize), m_NumRows(p_numRows), m_NumCols(p_numCols), m_TileMap(p_TileMap), m_Tilesets(p_tilesets)
{
    for (unsigned int i = 0; i < m_Tilesets.size(); i++)
    {
        std::string path = "assets/maps/" + m_Tilesets[i].Source;
        TextureManager::GetInstance()->LoadTexture(m_Tilesets[i].Name, path.c_str());
    }
}

void TileLayer::Render()
{
    SDL_Log("TILE LAYER: RENDER");
    for (unsigned int i = 0; i < m_NumRows; i++)
    {
        for (unsigned int j = 0; j < m_NumCols; j++)
        {
            int tileID = m_TileMap[i][j];

            if (tileID == 0)
            {
                continue;
            }
            else
            {
                int index = 0;
                if (m_Tilesets.size() > 1)
                {
                    for (unsigned int k = 1; k < m_Tilesets.size(); k++)
                    {
                        if (tileID >= m_Tilesets[k].FirstID && tileID <= m_Tilesets[k].LastID)
                        {
                            tileID = tileID + m_Tilesets[k].TileCout - m_Tilesets[k].LastID;
                            index = k;
                            break;
                        }
                    }
                }

                Tileset ts = m_Tilesets[index];
                int tileRow = tileID / ts.NumCols;
                int tileCol = tileID - tileRow * ts.NumCols - 1;

                if (tileID % ts.NumCols == 0)
                {
                    tileRow--;
                    tileCol = ts.NumCols - 1;
                }

                TextureManager::GetInstance()->DrawTile(ts.Name, ts.TileSize, Vector2I(j * ts.TileSize, i * ts.TileSize), tileRow, tileCol);
            }
        }
    }
}
void TileLayer::Update()
{
    SDL_Log("TILE LAYER UPDATE");
}
