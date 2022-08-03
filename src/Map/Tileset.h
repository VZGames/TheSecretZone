#ifndef __TILESET_H__
#define __TILESET_H__

#include "../thirdparty/TinyXML2/tinyxml2.h"
#include "Image.h"
using namespace tinyxml2;

class Tileset
{
private:
    unsigned int m_First_G_ID;
    const char *m_Name;
    unsigned int m_TileWidth, m_TileHeight;
    unsigned int m_TileCount;
    unsigned int m_Columns;

    Image *m_Image;

public:
    Tileset();
    ~Tileset();

    void Parse(XMLNode *p_Node, const char *p_FilePath);

    unsigned int GetFirstGID();
    const char *GetName();
    unsigned int GetTileWidth();
    unsigned int GetTileHeight();
    unsigned int GetTileCount();
    unsigned int GetColumns();
};
#endif // __TILESET_H__

/*
 <tileset firstgid="1" name="grass-tiles-2-small" tilewidth="16" tileheight="16" tilecount="80" columns="10">
*/