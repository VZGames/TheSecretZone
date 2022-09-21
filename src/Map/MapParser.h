#ifndef __MAPPARSER_H__
#define __MAPPARSER_H__

#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <SDL2/SDL.h>
#include "tinyxml2.h"
#include "GameMap.h"
#include "Tileset.h"

using namespace tinyxml2;
class GameMap;
class MapParser
{

private:
    MapParser();
private:
    XMLDocument *m_Doc;
    std::map<const char *, GameMap *> m_GameMapDict;
    std::vector<int*> m_MatrixPtrs;
    static MapParser *s_Instance;

private:
    void parseXML();
    void parseTileset(XMLElement *p_TilesetElement, TilesetList &p_TilesetList);
    void parseImage(XMLElement *p_ImageElement, Tileset &p_Tileset);
    void parseLayer(XMLElement *p_LayerElement, int *p_Matrix);
    void parseData(XMLElement *p_DataElement, int *matrix, int p_Count, int p_WorkerCount = 4);

public:
    bool LoadXML(const char *p_filePath);
    void Clean();
    GameMap *GetMap(const char *p_MapID);
    static MapParser *GetInstance() { return s_Instance = (s_Instance == nullptr) ? new MapParser() : s_Instance; }
};

#endif // __MAPPARSER_H__
