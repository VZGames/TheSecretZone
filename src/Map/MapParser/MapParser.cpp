#include "MapParser.h"

MapParser *MapParser::s_Instance = nullptr;
MapParser::MapParser()
{
}

bool MapParser::loadMap(const char *p_MapID, const char *p_Source)
{
    XMLDocument doc;
    XMLError result = doc.LoadFile(p_Source);
    if (result == XML_SUCCESS)
    {
        return 1;
    }
    return 0;
}

void MapParser::parse(const char *p_MapID)
{
}
