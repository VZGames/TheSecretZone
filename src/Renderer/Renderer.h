#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <map>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "../Engine/Engine.h"
#include "../Physics/vector2D.h"
class Renderer
{
private:
    std::map<const char *, SDL_Texture *> m_TextureDict;

    Renderer();
    static Renderer *s_Instance;

public:
    void LoadTexture(const char *p_TextureID, const char *p_FilePath);

    void DrawFrame(const char *p_TextureID, Vector2I p_Pos, int p_Width, int p_Height, int p_Row, int p_Frame, SDL_RendererFlip p_Flip = SDL_FLIP_NONE, double p_Angle = 0);
    void Drop(const char *p_TextureID);
    void Clean();
    static Renderer *GetInstance() { return s_Instance = (s_Instance == nullptr) ? new Renderer() : s_Instance; }
};
#endif // __RENDERER_H__