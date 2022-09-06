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

    TilesetList tileList;             // store tileset in vector
    GameMap *gameMap = new GameMap(); // dynamic allocated
    int *matrix = new int[width * height];
    for (XMLElement *e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
    {
        if (e->Value() == std::string("tileset"))
        {
            parseTileset(e, tileList);
        }

        if (e->Value() == std::string("layer"))
        {
            parseLayer(e, matrix);
            MapLayer layer(matrix, tileList);
            gameMap->InsertMapLayer(layer);
        }
    }

    m_GameMapDict["PhuHoa"] = gameMap;
}

void MapParser::parseTileset(XMLElement *p_TilesetElement, TilesetList &p_TilesetList)
{
    // <tileset firstgid="1" name="Water" tilewidth="16" tileheight="16" tilecount="4" columns="4">
    Tileset tileset;

    tileset.setName(p_TilesetElement->Attribute("name"));
    tileset.setWidth(p_TilesetElement->IntAttribute("tilewidth"));
    tileset.setHeight(p_TilesetElement->IntAttribute("tileheight"));
    tileset.setCount(p_TilesetElement->IntAttribute("tilecount"));
    tileset.setColumns(p_TilesetElement->IntAttribute("columns"));
    tileset.setFirstID(p_TilesetElement->IntAttribute("firstgid"));
    tileset.setLastID(tileset.getFirstID() + tileset.getCount() - 1);
    parseImage(p_TilesetElement->FirstChildElement("image"), tileset);

    p_TilesetList.push_back(tileset);
}

void MapParser::parseImage(XMLElement *p_ImageElement, Tileset &tileset)
{
    // <image source="../sprites/Tilesets/Water.png" width="64" height="16"/>
    TileImage image;
    int width, height;
    const char *source;
    image.setSource(p_ImageElement->Attribute("source"));
    image.setWidth(p_ImageElement->IntAttribute("width"));
    image.setHeight(p_ImageElement->IntAttribute("height"));

    // SDL_Log("Image Attribute \nSource: %s, Width: %d, Height: %d", source, width, height);

    tileset.setImage(&image);
}

void MapParser::parseLayer(XMLElement *p_LayerElement, int *p_Matrix)
{
    // <layer id="4" name="grass" width="250" height="150">
    int width, height;
    const char *name;
    name = p_LayerElement->Attribute("name");
    width = p_LayerElement->IntAttribute("width");
    height = p_LayerElement->IntAttribute("height");

    int count = width * height;

    parseData(p_LayerElement->FirstChildElement("data"), p_Matrix, count);

    // SDL_Log("Layer Attribute \nSource: %s, Width: %d, Height: %d", name, width, height);

    /*    for (int i = 0; i < height; i++)
       {
           for (int j = 0; j < width; j++)
           {
               SDL_Log("matrix[%d][%d]: %d", i, j, *(p_Matrix + (i * width) + j)); // 1 unit <=> i * p_Width
           }
       } */
}

void MapParser::parseData(XMLElement *p_DataElement, int *matrix, int p_Count, int p_WorkerCount)
{
    std::clock_t t;
    t = clock();

    std::string id;
    std::istringstream iss(p_DataElement->GetText());
    for (int i = 0; i < p_Count; i++)
    {
        getline(iss, id, ',');
        std::stringstream convertor(id);
        convertor >> *(matrix + i); // matrix[i]; (matrix <=> address 0th element of 1-D array )
    }

    /// examples

    /* int arr[p_Height][p_Width]; // arr <=> (*)[p_Width]
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

GameMap *MapParser::GetMap(const char *p_MapID)
{
    return m_GameMapDict[p_MapID];
}
