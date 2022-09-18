#ifndef __TEXTURE_MANAGER_H__
#define __TEXTURE_MANAGER_H__

#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../../Engine/Engine.h"
#include "../../Physics/vector2D.h"
class TextureManager
{
private:
    std::map<const char *, SDL_Texture *> m_TextureDict;

    TextureManager();
    static TextureManager *s_Instance;

public:
    void LoadTexture(const char *p_TextureID, const char *p_FilePath);
    void Draw(char *p_TextureID, Vector2I p_Pos, int p_Width, int p_Height, SDL_RendererFlip p_Flip = SDL_FLIP_NONE);
    void DrawTile(const char *p_TileID, int p_TileSize, Vector2I p_Pos, int p_Row, int p_Frame, SDL_RendererFlip p_Flip = SDL_FLIP_NONE);
    void DrawFrame(const char *p_TextureID, Vector2I p_Pos, int p_Width, int p_Height, int p_Row, int p_Frame, SDL_RendererFlip p_Flip = SDL_FLIP_NONE, double p_Angle = 0);
    void Drop(const char *p_TextureID);
    void Clean();
    static TextureManager *GetInstance() { return s_Instance = (s_Instance == nullptr) ? new TextureManager() : s_Instance; }
};

#endif // __TEXTURE_MANAGER_H__
