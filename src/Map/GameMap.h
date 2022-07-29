#ifndef __GAME_MAP_H__
#define __GAME_MAP_H__

#include <vector>
#include <iostream>
#include "Layer.h"
#include "SDL2/SDL.h"
class GameMap
{
private:
    std::vector<Layer *> m_MapLayers;
    friend class MapParser;

public:
    GameMap();
    void Render();
    void Update();

    std::vector<Layer *> GetMapLayers() { return m_MapLayers; }
    int CountMapLayers() { return m_MapLayers.size(); }
};

#endif // __GAME_MAP_H__