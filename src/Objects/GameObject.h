#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include <iostream>
#include <SDL2/SDL.h>
#include "../Physics/Transform.h"
#include "../Physics/vector2D.h"
struct Properties
{

    const char *m_TexTureID;
    SDL_RendererFlip m_Flip;
    Vector2I m_Position;
    int m_Width, m_Height;
    Properties()
        : m_TexTureID(""), m_Position(Vector2I()), m_Width(0), m_Height(0), m_Flip(SDL_FLIP_NONE)
    {
    }
    Properties(const char *p_TexTureID, Vector2I p_Position, int p_Width, int p_Height, SDL_RendererFlip p_Flip = SDL_FLIP_NONE)
        : m_TexTureID(p_TexTureID), m_Position(p_Position), m_Width(p_Width), m_Height(p_Height), m_Flip(p_Flip)
    {
    }
};

class GameObject
{
protected:
    Transform *m_Transform;
    Properties *m_Properties;

public:
    GameObject(Properties *p_Props)
        : m_Properties(p_Props)
    {
        m_Transform = new Transform(p_Props->m_Position.m_X, p_Props->m_Position.m_Y);
    }
    virtual void Render() = 0;
    virtual void Update(float p_DeltaTime) = 0;
    virtual void Clean() = 0;

    friend std::ostream &operator<<(std::ostream &p_Out, const GameObject &p_GameObject)
    {
        p_Out << "\n";
        return p_Out;
    }
};

#endif // __GAME_OBJECT_H__
