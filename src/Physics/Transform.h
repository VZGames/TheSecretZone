#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include <iostream>
#include "Vector2D.h"

#define FORWARD 1
#define BACKWARD -1
#define UPWARD -1
#define DOWNWARD 1
class Transform
{
public:
    Vector2F m_Position;
    Vector2F m_Velocity;
    Transform()
    {
        m_Position.Zeros();
    }
    Transform(float p_posX, float p_posY)
    {
        m_Position.m_X = p_posX;
        m_Position.m_Y = p_posY;
    }

    void Log(char *msg)
    {
        std::cout << msg << "(X, Y) = (" << m_Position.m_X << "," << m_Position.m_Y << ")" << std::endl;
    }

    inline void TranslateX(float x) { m_Position.m_X += x; }
    inline void TranslateY(float y) { m_Position.m_Y += y; }
    inline void TranslateVector(Vector2F v)
    {
        m_Position += v;
    }
};
#endif // __TRANSFORM_H__