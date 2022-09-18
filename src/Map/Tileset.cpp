#include "Tileset.h"
Tileset::Tileset()
{
}

const char *Tileset::getName() const
{
    return m_Name;
}

void Tileset::setName(const char *p_Name)
{
    m_Name = p_Name;
}

int Tileset::getFirstID() const
{
    return m_FirstID;
}

void Tileset::setFirstID(int p_FirstID)
{
    m_FirstID = p_FirstID;
}

int Tileset::getLastID() const
{
    return m_LastID;
}

void Tileset::setLastID(int p_LastID)
{
    m_LastID = p_LastID;
}

int Tileset::getWidth() const
{
    return m_Width;
}

void Tileset::setWidth(int p_Width)
{
    m_Width = p_Width;
}

int Tileset::getHeight() const
{
    return m_Height;
}

void Tileset::setHeight(int p_Height)
{
    m_Height = p_Height;
}

int Tileset::getCount() const
{
    return m_Count;
}

void Tileset::setCount(int p_Count)
{
    m_Count = p_Count;
}

int Tileset::getColumns() const
{
    return m_Columns;
}

void Tileset::setColumns(int p_Columns)
{
    m_Columns = p_Columns;
}

TileImage Tileset::getImage() const
{
    return m_Image;
}

void Tileset::setImage(TileImage &p_Image)
{
    m_Image = p_Image;
}

Tileset::~Tileset()
{
}
