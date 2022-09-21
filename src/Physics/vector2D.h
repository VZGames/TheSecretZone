#ifndef __VECTOR2D_H__
#define __VECTOR2D_H__

#include <iostream>
template <typename T>
class Vector2D
{
private:
    Vector2D<T> &m_Add(const Vector2D<T> &p_Vec)
    {
        this->m_X += p_Vec.m_X;
        this->m_Y += p_Vec.m_Y;
        return *this;
    }
    Vector2D<T> &m_Subtract(const Vector2D<T> &p_Vec)
    {
        this->m_X -= p_Vec.m_X;
        this->m_Y -= p_Vec.m_Y;
        return *this;
    }
    Vector2D<T> &m_Multiply(const Vector2D<T> &p_Vec)
    {
        this->m_X *= p_Vec.m_X;
        this->m_Y *= p_Vec.m_Y;
        return *this;
    }
    Vector2D<T> &m_Divide(const Vector2D<T> &p_Vec)
    {
        this->m_X /= p_Vec.m_X;
        this->m_Y /= p_Vec.m_Y;
        return *this;
    }

public:
    T m_X;
    T m_Y;
    Vector2D(const Vector2D<T> &p_Copy) {
        this->m_X = p_Copy.m_X;
        this->m_Y = p_Copy.m_Y;
    }
    Vector2D() : m_X(0), m_Y(0) {}
    Vector2D(T p_X, T p_Y) : m_X(p_X), m_Y(p_Y) {}

    Vector2D<T> &Ones()
    {
        this->m_X = static_cast<T>(1);
        this->m_Y = static_cast<T>(1);
        return *this;
    }
    Vector2D<T> &Zeros()
    {
        this->m_X = static_cast<T>(0);
        this->m_Y = static_cast<T>(0);
        return *this;
    }

    friend Vector2D<T> &operator+(Vector2D<T> &p_A, const Vector2D<T> &p_B)
    {
        return p_A.m_Add(p_B);
    }
    friend Vector2D<T> &operator-(Vector2D<T> &p_A, const Vector2D<T> &p_B)
    {

        return p_A.m_Subtract(p_B);
    }
    friend Vector2D<T> &operator*(Vector2D<T> &p_A, const Vector2D<T> &p_B)
    {

        return p_A.m_Multiply(p_B);
    }
    friend Vector2D<T> &operator/(Vector2D<T> &p_A, const Vector2D<T> &p_B)
    {

        return p_A.m_Divide(p_B);
    }

    Vector2D<T> &operator+=(const Vector2D<T> &p_B)
    {
        return this->m_Add(p_B);
    }
    Vector2D<T> &operator-=(const Vector2D<T> &p_B)
    {
        return this->m_Subtract(p_B);
    }
    Vector2D<T> &operator*=(const Vector2D<T> &p_B)
    {
        return this->m_Multiply(p_B);
    }
    Vector2D<T> &operator/=(const Vector2D<T> &p_B)
    {
        return this->m_Divide(p_B);
    }

    Vector2D<T> &operator*(T i)
    {
        this->m_X *= i;
        this->m_Y *= i;
        return *this;
    }
    Vector2D<T> &operator=(const Vector2D<T> &p_B)
    {
        this->m_X = p_B.m_X;
        this->m_Y = p_B.m_Y;
        return *this;
    }
    void print()
    {
        std::cout << m_X << ", " << m_Y << std::endl;
    }
    friend std::ostream &operator<<(std::ostream &p_Out, const Vector2D &p_Vec)
    {
        p_Out << "(" << p_Vec.m_X << ", " << p_Vec.m_Y << ")\n";
        return p_Out;
    }
};

using Vector2I = Vector2D<int>;
using Vector2U = Vector2D<unsigned int>;
using Vector2F = Vector2D<float>;
using Vector2LF = Vector2D<double>;

#endif // __VECTOR2D_H__
