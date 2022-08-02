#include "Tile.h"
Tile::Tile()
{
}

Tile::~Tile()
{
}

unsigned int Tile::GetID() const
{
    return m_ID;
}

void Tile::SetID(unsigned p_ID)
{
    m_ID = p_ID;
}

const char *Tile::GetType() const
{
    return m_Type;
}

void Tile::SetType(const char *p_Type)
{
    m_Type = p_Type;
}

unsigned int Tile::GetWidth() const
{
    return m_Width;
}

void Tile::SetWidth(unsigned int p_Width)
{
    m_Width = p_Width;
}

unsigned int Tile::GetHeight() const
{
    return m_Height;
}

void Tile::SetHeight(unsigned int p_Height)
{
    m_Height = p_Height;
}
