#ifndef __GAMEMAP_H__
#define __GAMEMAP_H__

#include <vector>
#include "Layer.h"

class GameMap
{
private:
    std::vector<Layer*> m_MapLayers;

public:
    GameMap();
    ~GameMap();

    void Render();
    void Update();

    int MapLayerCount();
    void InsertMapLayer(Layer *p_MapLayer);
};

#endif // __GAMEMAP_H__
