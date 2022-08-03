#include "Tileset.h"

Tileset::Tileset()
    : m_First_G_ID(0), m_Name(), m_TileWidth(0), m_TileHeight(0), m_TileCount(0), m_Columns(0), m_Image(nullptr)
{
}

Tileset::~Tileset()
{
    // Delete the image from memory if allocated.
    if (m_Image)
    {
        delete m_Image;
        m_Image = NULL;
    }
}

void Tileset::Parse(XMLNode *p_Node, const char *p_FilePath)
{
    const XMLElement *element = p_Node->ToElement();

    m_First_G_ID = element->IntAttribute("firstgid");
    m_TileHeight = element->IntAttribute("tileheight");
    m_TileWidth = element->IntAttribute("tilewidth");
    m_TileCount = element->IntAttribute("tilecount");
    m_Columns = element->IntAttribute("columns");

    XMLNode *imgNode = p_Node->FirstChildElement("image");
    m_Image = new Image();
    m_Image->Parse(imgNode);
}

unsigned int Tileset::GetFirstGID()
{
    return m_First_G_ID;
}

const char *Tileset::GetName()
{
    return m_Name;
}

unsigned int Tileset::GetTileWidth()
{
    return m_TileWidth;
}

unsigned int Tileset::GetTileHeight()
{
    return m_TileHeight;
}

unsigned int Tileset::GetTileCount()
{
    return m_TileCount;
}

unsigned int Tileset::GetColumns()
{
    return m_Columns;
}
