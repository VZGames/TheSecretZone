#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "SDL2/SDL.h"
#include "../Renderer/Renderer.h"
#include "../Physics/vector2D.h"

class Animation
{
private:
    int m_Angle = 0;
    int m_SpriteRow, m_SpriteFrame;
    int m_FrameCout, m_AnimationSpeed;
    const char *m_TextureID;
    SDL_RendererFlip m_Flip;

public:
    Animation();
    void SetProps(const char *p_TextureID, int p_Row, int p_Frames, int p_Speed, SDL_RendererFlip p_Flip = SDL_FLIP_NONE, int p_Angle = 0);
    void Update();
    void Draw(Vector2I p_Pos, int p_Width, int p_Height);
};
#endif // __ANIMATION_H__