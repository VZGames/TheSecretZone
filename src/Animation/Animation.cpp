#include "Animation.h"
#include "../Graphics/TextureManager/TextureManager.h"


Animation::Animation()
{
}
void Animation::SetProps(const char *p_TextureID, int p_Row, int p_Frames, int p_Speed, SDL_RendererFlip p_Flip, int p_Angle)
{
    m_Angle = 0;
    m_SpriteRow = p_Row;
    m_FrameCout = p_Frames;
    m_AnimationSpeed = p_Speed;
    m_TextureID = p_TextureID;
    m_Flip = p_Flip;
}

void Animation::Update()
{
    m_SpriteFrame = (SDL_GetTicks() / m_AnimationSpeed) % m_FrameCout;
}

void Animation::Draw(Vector2I p_Pos, int p_Width, int p_Height)
{
    TextureManager::GetInstance()->DrawFrame(m_TextureID, p_Pos, p_Width, p_Height, m_SpriteRow, m_SpriteFrame, m_Flip, m_Angle);
}
