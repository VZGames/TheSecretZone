#ifndef __IMAGE_H__
#define __IMAGE_H__

#include "../thirdparty/TinyXML2/tinyxml2.h"

using namespace tinyxml2;

class Image
{
private:
    const char *m_Source;
    unsigned int m_Width, m_Height;

public:
    Image();
    ~Image();

    void Parse(XMLNode *p_Node);

    unsigned int GetWidth();
    unsigned int GetHeight();
};
#endif // __IMAGE_H__

/*
    <image source="../sprites/Tilesets/Grass.png" width="160" height="128"/>
*/