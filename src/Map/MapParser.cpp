#include "MapParser.h"
#include "MapLayer.h"
#include "TileImage.h"
#include "Layer.h"

MapParser *MapParser::s_Instance = nullptr;

MapParser::MapParser()
    : m_Doc(new XMLDocument())
{
}

void MapParser::parseXML()
{
    printf("MapParser::parseXML Begin\n");
    //<map version="1.8" tiledversion="1.8.5" orientation="orthogonal" renderorder="right-down" width="250" height="150" tilewidth="16" tileheight="16" infinite="0" nextlayerid="5" nextobjectid="1">
    XMLElement *root = m_Doc->RootElement();
    int rowCount, colCount, tileSize;
    colCount = root->IntAttribute("width");
    rowCount = root->IntAttribute("height");
    tileSize = root->IntAttribute("tilewidth");
    printf("Map Attribute Width: %d, Height: %d, Tile Size: %d\n", colCount, rowCount, tileSize);

    TilesetList tileList;                  // store tileset in vector
    GameMap *gameMap = new GameMap();      // dynamic allocated

    for (XMLElement *e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
    {
        if (e->Value() == std::string("tileset"))
        {
            parseTileset(e, tileList);
        }

        else if (e->Value() == std::string("layer"))
        {
            int mtrxSize = colCount * rowCount; // init matrix size
            int *matrix = new int[mtrxSize]; // tileset ID matrix
            parseLayer(e, matrix);
            Layer *layer =  new MapLayer(matrix, tileList, colCount, rowCount);
            m_MatrixPtrs.push_back(matrix);
            gameMap->InsertMapLayer(layer);
        }
    }
    m_GameMapDict["PhuHoa"] = gameMap;
    printf("MapParser::parseXML exit\n");
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
    printf("Tileset Attribute Name: %s, First ID: %d, Last ID: %d, Image: %s\n",
           tileset.getName(),
           tileset.getFirstID(),
           tileset.getLastID(),
           tileset.getImage().getSource());
    p_TilesetList.push_back(tileset);
}

void MapParser::parseImage(XMLElement *p_ImageElement, Tileset &tileset)
{
    // <image source="../sprites/Tilesets/Water.png" width="64" height="16"/>
    TileImage image;
    image.setSource(p_ImageElement->Attribute("source"));
    image.setWidth(p_ImageElement->IntAttribute("width"));
    image.setHeight(p_ImageElement->IntAttribute("height"));


    tileset.setImage(image);
    printf("Image Attribute Source: %s, Width: %d, Height: %d\n",
           tileset.getImage().getSource(),
           tileset.getImage().getWidth(),
           tileset.getImage().getHeight());
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

    printf("Layer Attribute Source: %s, Width: %d, Height: %d\n", name, width, height);
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
        convertor >> *(matrix + i); /// matrix[i]; (matrix <=> address 0th element of 1-D array )
    }

    // examples

    /*
     * 1
    for (int i = 0; i < p_Count; i++)
    {
        getline(iss, id, ',');
        std::stringstream convertor(id);
        convertor >> *(matrix + i); /// matrix[i]; (matrix <=> address 0th element of 1-D array )
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("[%d][%d]: %d,", i, j, *(p_Matrix + (i * width) + j)); // 1 row unit <=> i * p_Width
        }
        printf("\n");
    }


    *2
    int arr[p_Height][p_Width]; // arr <=> (*)[p_Width]
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
            printf("matrix[%d][%d]: %d", i, j, matrix[i][j]);
        }
    } */

    t = clock() - t;

    printf("It took time %f\n", ((float)t / CLOCKS_PER_SEC));
}

bool MapParser::LoadXML(const char *p_filePath)
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
    printf("MapParser::GetMap ID: %s\n", p_MapID);
    GameMap *gameMap = m_GameMapDict["PhuHoa"];
    return gameMap;
}

void MapParser::Clean()
{
    printf("MapParser::Clean");

    delete m_Doc;
    m_Doc = NULL;

    for (int* ptr: m_MatrixPtrs) {
        delete []ptr;
        ptr = nullptr;
    }
    std::map<const char *, GameMap *>::iterator it;
    for (it = m_GameMapDict.begin(); it != m_GameMapDict.end(); ++it) {
        delete it->second;
        it->second = NULL;
    }
    m_GameMapDict.clear();
}
