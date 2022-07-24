#ifndef __GAME_MAP_H__
#define __GAME_MAP_H__

#include <vector>
#include "../Layer/Layer.h"

class GameMap
{
private:
    std::vector<Layer *> m_MapLayers;

public:
    GameMap();
    void Render();
    void Update();

    std::vector<Layer *> GetMapLayers() { return m_MapLayers; };
};
#endif // __GAME_MAP_H__