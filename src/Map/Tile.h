#ifndef __TILE_H__
#define __TILE_H__

class Tile
{
private:
    unsigned int m_ID;
    const char *m_Type;
    unsigned int m_Width, m_Height;

public:
    Tile();
    ~Tile();

    unsigned int GetID() const;
    void SetID(unsigned p_ID);

    const char *GetType() const;
    void SetType(const char *p_Type);

    unsigned int GetWidth() const;
    void SetWidth(unsigned int p_Width);

    unsigned int GetHeight() const;
    void SetHeight(unsigned int p_Height);
};
#endif // __TILE_H__