#ifndef __MAP_PARSER_H__
#define __MAP_PARSER_H__

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include "SDL2/SDL.h"
#include "GameMap.h"
#include "TileLayer.h"
#include "../thirdparty/TinyXML2_6_2/tinyxml.h"

class MapParser
{
private:
    static MapParser *s_Instance;
    std::map<const char *, GameMap *> m_MapDict;

private:
    bool Parse(const char *p_MapID, TiXmlDocument p_XML);
    Tileset ParseTileset(TiXmlElement *p_xmlTileset);
    TileLayer *ParseTileLayer(TiXmlElement *p_xmlPlayer, TilesetsList p_tilesets, int p_tileSize, int p_numRows, int p_numCols);

public:
    bool Load(const char *p_MapID, const char *m_FilePath);
    void Clean();
    int GetSizeDict() { return m_MapDict.size(); }
    static MapParser *GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new MapParser(); }
    GameMap *GetMap(const char *p_id) { return m_MapDict[p_id]; };
};

#endif // __MAP_PARSER_H__