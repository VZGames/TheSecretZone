#ifndef __MAPPARSER_H__
#define __MAPPARSER_H__

#include <bits/stdc++.h>
#include "tinyxml2.h"
#include "SDL2/SDL.h"
#include "TileImage.h"
#include "Tileset.h"

using namespace tinyxml2;
class MapParser
{
private:
    MapParser();
    static MapParser *s_Instance;
    XMLDocument *m_Doc;

private:
    void parseXML();
    void parseTileset(XMLElement *p_TilesetElement, TilesetList *p_TilesetList);
    void parseImage(XMLElement *p_ImageElement, Tileset &tileset);
    void parseLayer(XMLElement *p_LayerElement);
    void parseData(XMLElement *p_DataElement, int *matrix, int p_Count, int p_WorkerCount = 4);

public:
    ~MapParser();
    static MapParser *GetInstance() { return s_Instance = (s_Instance == nullptr) ? new MapParser() : s_Instance; }
    bool loadXML(const char *p_filePath);

    // operator
};

#endif // __MAPPARSER_H__