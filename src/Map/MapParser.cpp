#include "MapParser.h"
MapParser::MapParser()
    : m_Doc(new XMLDocument())
{
}

MapParser::~MapParser()
{
    delete m_Doc;
    m_Doc = NULL;
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

        if (e->Value() == std::string("layer"))
        {
            parseLayer(e);
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

void MapParser::parseLayer(XMLElement *p_LayerElement)
{
    // <layer id="4" name="grass" width="250" height="150">
    int width, height;
    const char *name;
    name = p_LayerElement->Attribute("name");
    width = p_LayerElement->IntAttribute("width");
    height = p_LayerElement->IntAttribute("height");

    parseData(p_LayerElement->FirstChildElement("data"), width, height);
    SDL_Log("Layer Attribute \nSource: %s, Width: %d, Height: %d", name, width, height);
}

void MapParser::parseData(XMLElement *p_DataElement, int p_Width, int p_Height, int p_WorkerCount)
{
    std::clock_t t;
    t = clock();
    //   <data encoding="csv">
    /*     const char *encoding = p_DataElement->Attribute("encoding");
        if (encoding == std::string("base64"))
        {

        }
        else if (encoding == std::string("csv"))
        {

        } */

    std::string id;
    std::istringstream iss(p_DataElement->GetText());
    int count = p_Height * p_Width;
    int *matrix = new int[count];
    for (int i = 0; i < count; i++)
    {
        getline(iss, id, ',');
        std::stringstream convertor(id);
        convertor >> *(matrix + i); // matrix[i]; (matrix <=> address 0th element of 1-D array )
    }

    /* int arr[p_Height][p_Width];
    int(*matrix)[p_Width] = arr;

    for (int i = 0; i < p_Height; i++)
    {
        for (int j = 0; j < p_Width; j++)
        {
            int k;
            getline(iss, id, ',');
            std::stringstream convertor(id);
            convertor >> k;
            *(matrix[i] + j) = k; // *(*(matrix + i) + j), *(matrix + i) <=> matrix[i] <=> address 0th element of ith 1-D array of 2-D array
        }
    }

    for (int i = 0; i < p_Height; i++)
    {
        for (int j = 0; j < p_Width; j++)
        {
            SDL_Log("matrix[%d][%d]: %d", i, j, matrix[i][j]);
        }
    } */
    t = clock() - t;

    SDL_Log("It took time %f", (float)t / CLOCKS_PER_SEC);
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
