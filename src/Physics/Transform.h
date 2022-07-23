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
    Vector2I m_Position;
    Vector2I m_Velocity;
    Transform()
    {
        m_Position.Zeros();
    }
    Transform(float p_PosX, float p_PosY)
    {
        m_Position.m_X = p_PosX;
        m_Position.m_Y = p_PosY;
    }

    void Log(char *p_Msg)
    {
        std::cout << p_Msg << "(X, Y) = (" << m_Position.m_X << "," << m_Position.m_Y << ")" << std::endl;
    }

    inline void TranslateX(float x) { m_Position.m_X += x; }
    inline void TranslateY(float y) { m_Position.m_Y += y; }
    inline void TranslateVector(Vector2I p_Vec)
    {
        m_Position += p_Vec;
    }
};
#endif // __TRANSFORM_H__