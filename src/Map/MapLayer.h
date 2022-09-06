#ifndef __MAPLAYER_H__
#define __MAPLAYER_H__

#include "Tileset.h"

class MapLayer
{
private:
    int *m_Matrix;
    TilesetList m_TileList;

public:
    MapLayer();
    MapLayer(int *p_Matrix, TilesetList &p_TileList);
    ~MapLayer();

    void Update();
    void Render();
};
#endif // __MAPLAYER_H__