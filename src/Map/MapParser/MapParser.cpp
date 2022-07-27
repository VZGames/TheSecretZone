#include "MapParser.h"

MapParser *MapParser::s_Instance = nullptr;
MapParser::MapParser()
{
}

bool MapParser::loadMap(const char *p_MapID, const char *p_Source)
{
    XMLDocument doc;
    doc.LoadFile(p_Source);
    if (doc.ErrorID() == XML_SUCCESS)
    {
        XMLElement *root = doc.RootElement();
        int root_Width, root_Height;
        int tile_Width, tile_Height;
        root_Width = root->IntAttribute("width");
        root_Height = root->IntAttribute("height");
        tile_Width = root->IntAttribute("tilewidth");
        tile_Height = root->IntAttribute("tileheight");

        GameMap *gameMap = new GameMap();

        m_DictMaps[p_MapID] = gameMap;
        doc.Clear();
        delete gameMap;
        return 1;
    }
    return 0;
}

void MapParser::parse(const char *p_MapID)
{
    m_DictMaps[p_MapID];
}
