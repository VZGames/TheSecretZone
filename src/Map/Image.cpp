#include "Image.h"
Image::Image()
    : m_Source(), m_Height(0), m_Width(0)
{
}

Image::~Image()
{
}

void Image::Parse(XMLNode *p_Node)
{
    const XMLElement *element = p_Node->ToElement();

    m_Source = element->Attribute("source");
    m_Width = element->IntAttribute("width");
    m_Height = element->IntAttribute("height");
}

unsigned int Image::GetWidth()
{
    return m_Width;
}

unsigned int Image::GetHeight()
{
    return m_Height;
}
