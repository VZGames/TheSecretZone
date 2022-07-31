#include "MapParser.h"

MapParser *MapParser::s_Instance = nullptr;

bool MapParser::Load(const char *p_MapID, const char *p_FilePath)
{
    TiXmlDocument xml;
    bool loadOK = xml.LoadFile(p_FilePath);
    if (loadOK)
    {
        if (Parse(p_MapID, xml))
            return true;
        else
        {
            return false;
        }
    }
    std::cerr << "Failed to load: " << p_FilePath << std::endl;
    return false;
}

bool MapParser::Parse(const char *p_MapID, TiXmlDocument p_XML)
{
    // Get infomation node root
    TiXmlElement *root = p_XML.RootElement();
    int numRows, numCols, tileSize = 0;
    root->Attribute("width", &numCols);
    root->Attribute("height", &numRows);
    root->Attribute("tilewidth", &tileSize);

    TilesetsList tilesets;
    for (TiXmlElement *e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
    {
        if (e->Value() == std::string("tileset"))
        {
            tilesets.push_back(ParseTileset(e));
        }
        std::cout << "\n";
    }

    GameMap *gameMap = new GameMap();
    for (TiXmlElement *e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
    {
        if (e->Value() == std::string("layer"))
        {
            TileLayer *tileLayer = ParseTileLayer(e, tilesets, tileSize, numRows, numCols);
            gameMap->m_MapLayers.push_back(tileLayer);
        }
    }
    m_MapDict[p_MapID] = gameMap;
    return true;
}
Tileset MapParser::ParseTileset(TiXmlElement *p_xmlTileset)
{
    Tileset tileset;
    tileset.Name = (char *)p_xmlTileset->Attribute("name");
    p_xmlTileset->Attribute("firstgid", &tileset.FirstID);
    p_xmlTileset->Attribute("tilecount", &tileset.TileCout);
    tileset.LastID = (tileset.FirstID + tileset.TileCout) - 1;

    p_xmlTileset->Attribute("columns", &tileset.NumCols);
    tileset.NumRows = tileset.TileCout / tileset.NumCols;
    p_xmlTileset->Attribute("tilewidth", &tileset.TileSize);

    TiXmlElement *image = p_xmlTileset->FirstChildElement();
    tileset.Source = image->Attribute("source");
    std::cout << "Name: " << tileset.Name << "\n"
              << "FirstID: " << tileset.FirstID << "\n"
              << "LastID: " << tileset.LastID << "\n"
              << "Source: " << tileset.Source << std::endl;
    return tileset;
}

TileLayer *MapParser::ParseTileLayer(TiXmlElement *p_xmlPlayer, TilesetsList p_tilesets, int p_tileSize, int p_numRows, int p_numCols)
{
    TiXmlElement *data;
    for (TiXmlElement *e = p_xmlPlayer->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
    {
        if (e->Value() == std::string("data"))
        {
            data = e;
            SDL_Log("Reading Data");
            break;
        }
    }
    std::string matrix(data->GetText());
    std::istringstream iss(matrix);
    std::string id;
    // std::ofstream rc("assets/maps/test.txt");
    TileMap tilemap(p_numRows, std::vector<int>(p_numCols, 0));
    for (int row = 0; row < p_numRows; row++)
    {
        for (int col = 0; col < p_numCols; col++)
        {
            getline(iss, id, ',');
            std::stringstream convertor(id);
            convertor >> tilemap[row][col];
            if (!iss.good())
                break;
        }
    }
    return (new TileLayer(p_tileSize, p_numRows, p_numCols, tilemap, p_tilesets));
}

void MapParser::Clean()
{
    for (auto i : m_MapDict)
    {
        i.second = nullptr;
    }
    m_MapDict.clear();
    SDL_Log("\nGameMap cleaned");
}
