#include "MapParser.h"
MapParser::MapParser()
    : m_Doc(new XMLDocument())
{
}

MapParser::~MapParser()
{
}

void MapParser::parseXML()
{
    //<map version="1.8" tiledversion="1.8.5" orientation="orthogonal" renderorder="right-down" width="250" height="150" tilewidth="16" tileheight="16" infinite="0" nextlayerid="5" nextobjectid="1">
    XMLElement *root = m_Doc->RootElement();
    int width, height, tileSize;
    width = root->IntAttribute("width");
    height = root->IntAttribute("height");
    tileSize = root->IntAttribute("tilewidth");
    SDL_Log("Map Attribute \nWidth: %d, Height: %d, Tile Size: %d", width, height, tileSize);

    for (XMLElement *e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
    {
        if (e->Value() == std::string("tileset"))
        {
            parseTileset(e);
        }
    }
}

void MapParser::parseTileset(XMLElement *p_TilesetElement)
{
    // <tileset firstgid="1" name="Water" tilewidth="16" tileheight="16" tilecount="4" columns="4">
    int firstgid, width, height, count, columns;
    const char *name;

    name = p_TilesetElement->Attribute("name");
    firstgid = p_TilesetElement->IntAttribute("firstgid");
    width = p_TilesetElement->IntAttribute("tilewidth");
    height = p_TilesetElement->IntAttribute("tileheight");
    count = p_TilesetElement->IntAttribute("tilecount");
    columns = p_TilesetElement->IntAttribute("columns");

    parseImage(p_TilesetElement->FirstChildElement("image"));
    SDL_Log("Tileset Attribute \nName: %s, Width: %d, Height: %d, Count %d, Columns %d", name, width, height, count, columns);
}

void MapParser::parseImage(XMLElement *p_ImageElement)
{
    // <image source="../sprites/Tilesets/Water.png" width="64" height="16"/>
    int width, height;
    const char *source;
    source = p_ImageElement->Attribute("source");
    width = p_ImageElement->IntAttribute("width");
    height = p_ImageElement->IntAttribute("height");

    SDL_Log("Image Attribute \nSource: %s, Width: %d, Height: %d", source, width, height);
}

bool MapParser::loadXML(const char *p_filePath)
{
    XMLError error = m_Doc->LoadFile(p_filePath);
    if (error == XML_SUCCESS)
    {
        parseXML();
        return 1;
    }
    return 0;
}
