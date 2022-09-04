#include "MapLayer.h"
MapLayer::MapLayer()
{
}

MapLayer::MapLayer(int *p_Matrix, TilesetList &p_TileList)
    : m_Matrix(p_Matrix), m_TileList(p_TileList)
{
}

MapLayer::~MapLayer()
{
}
