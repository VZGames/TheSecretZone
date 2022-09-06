#ifndef __GAMEMAP_H__
#define __GAMEMAP_H__

#include <vector>
#include "MapLayer.h"

class GameMap
{
private:
    std::vector<MapLayer> m_MapLayers;

public:
    GameMap();
    ~GameMap();

    void Render();
    void Update();

    void InsertMapLayer(const MapLayer &p_MapLayer);
};

#endif // __GAMEMAP_H__