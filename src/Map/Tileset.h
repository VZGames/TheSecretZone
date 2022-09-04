#ifndef __TILESET_H__
#define __TILESET_H__

#include <vector>
#include "TileImage.h"

class Tileset
{
private:
    const char *m_Name;
    int m_FirstID, m_LastID;
    int m_Width, m_Height;
    int m_Count;
    int m_Columns;
    TileImage *m_Image;

public:
    Tileset();
    ~Tileset();

    // encapsulation
    const char *getName() const;
    void setName(const char *p_Name);

    int getFirstID() const;
    void setFirstID(int p_FirstID);

    int getLastID() const;
    void setLastID(int p_LastID);

    int getWidth() const;
    void setWidth(int p_Width);

    int getHeight() const;
    void setHeight(int p_Height);

    int getCount() const;
    void setCount(int p_Count);

    int getColumns() const;
    void setColumns(int p_Columns);

    TileImage *getImage() const;
    void setImage(TileImage *p_Image);
};

using TilesetList = std::vector<Tileset>;

#endif // __TILESET_H__
