#ifndef __MAPPARSER_H__
#define __MAPPARSER_H__

#include "SmartPtr.h"
#include "tinyxml2.h"
#include "SDL2/SDL.h"
#include "bits/stdc++.h"
using namespace tinyxml2;
class MapParser
{
private:
    MapParser();
    static MapParser *s_Instance;
    SmartPtr<XMLDocument> m_Doc;

private:
    void parseXML();
    void parseTileset(XMLElement *p_TilesetElement);
    void parseImage(XMLElement *p_ImageElement);
    // void parseLayer(XMLElement *e);

public:
    ~MapParser();
    static MapParser *GetInstance() { return s_Instance = (s_Instance == nullptr) ? new MapParser() : s_Instance; }
    bool loadXML(const char *p_filePath);

    // operator
};

#endif // __MAPPARSER_H__