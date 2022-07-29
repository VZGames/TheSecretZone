#ifndef __TILE_LAYER_H__
#define __TILE_LAYER_H__

#include <vector>
#include <string>
#include "Layer.h"

struct Tileset
{
    char *Name;
    std::string Source;
    int FirstID, LastID;
    int NumRows, NumCols;
    int TileCout, TileSize;
};

using TilesetsList = std::vector<Tileset>;
using TileMap = std::vector<std::vector<int>>;

class TileLayer : public Layer
{
private:
    int m_TileSize, m_NumRows, m_NumCols;
    TileMap m_TileMap;
    TilesetsList m_Tilesets;

public:
    TileLayer(int p_tileSize, int p_numRows, int p_numCols, TileMap p_TileMap, TilesetsList p_tilesets);
    virtual void Render();
    virtual void Update();
    inline TileMap GetTileMap() { return m_TileMap; }
};

#endif // __TILE_LAYER_H__