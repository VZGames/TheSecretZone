#include "TileImage.h"
TileImage::TileImage()
{
}

TileImage::~TileImage()
{
}

const char *TileImage::getSource() const
{
    return m_Source;
}

void TileImage::setSource(const char *p_Source)
{
    m_Source = p_Source;
}

int TileImage::getWidth() const
{
    return m_Width;
}

void TileImage::setWidth(int p_Width)
{
    m_Width = p_Width;
}

int TileImage::getHeight() const
{
    return m_Height;
}

void TileImage::setHeight(int p_Height)
{
    m_Height = p_Height;
}
