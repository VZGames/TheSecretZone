#ifndef __MAPLAYER_H__
#define __MAPLAYER_H__

#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include "Tileset.h"

#include "Layer.h"

class MapLayer: public Layer
{
private:
    int *m_Matrix;
    TilesetList m_TileList;

public:
    MapLayer();
    MapLayer(int *p_Matrix, TilesetList &p_TileList);
    ~MapLayer();

    void Update() override;
    void Render() override;
};
#endif // __MAPLAYER_H__
