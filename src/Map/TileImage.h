#ifndef __TILEIMAGE_H__
#define __TILEIMAGE_H__

class TileImage
{
private:
    const char *m_Source;
    int m_Width, m_Height;

public:
    TileImage();
    ~TileImage();

    /// encapsulation
    const char *getSource() const;
    void setSource(const char *p_Source);

    int getWidth() const;
    void setWidth(int p_Width);

    int getHeight() const;
    void setHeight(int p_Height);
};

#endif // __TILEIMAGE_H__