#include "TextureManager.h"

TextureManager *TextureManager::s_Instance = nullptr;
TextureManager::TextureManager()
{
}

void TextureManager::LoadTexture(const char *p_TextureID, const char *p_FilePath)
{
    SDL_Log(p_FilePath);
    SDL_Surface *surface = IMG_Load(p_FilePath);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(Engine::s_Renderer, surface);

    m_TextureDict[p_TextureID] = tex;
    SDL_FreeSurface(surface);

    surface = nullptr;
}

void TextureManager::Draw(char *p_TextureID, Vector2I p_Pos, int p_Width, int p_Height, SDL_RendererFlip p_Flip)
{
    SDL_Rect srcRect = {0, 0, p_Width, p_Height};
    SDL_Rect dstRect = {p_Pos.m_X, p_Pos.m_Y, p_Width, p_Height};
    SDL_RenderCopyEx(Engine::s_Renderer, m_TextureDict[p_TextureID], &srcRect, &dstRect, 0, NULL, p_Flip);
}

void TextureManager::DrawTile(const char *p_TileID, int p_TileSize, Vector2I p_Pos, int p_Row, int p_Frame, SDL_RendererFlip p_Flip)
{
    SDL_Rect srcRect = {p_TileSize * p_Frame, p_TileSize * (p_Row - 1), p_TileSize, p_TileSize};
    SDL_Rect dstRect = {p_Pos.m_X, p_Pos.m_Y, p_TileSize, p_TileSize};
    SDL_RenderCopyEx(Engine::s_Renderer, m_TextureDict[p_TileID], &srcRect, &dstRect, 0, 0, p_Flip);
}

void TextureManager::DrawFrame(const char *p_TextureID, Vector2I p_Pos, int p_Width, int p_Height, int p_Row, int p_Frame, SDL_RendererFlip p_Flip, double p_Angle)
{
    /*
    row 1
    frame 0    1    2
        [***][***][***]
    */
    SDL_Rect srcRect = {
        p_Width * p_Frame,
        p_Height * (p_Row - 1),
        p_Width,
        p_Height,
    };
    SDL_Rect dstRect = {
        p_Pos.m_X,
        p_Pos.m_Y,
        p_Width,
        p_Height,
    };
    SDL_RenderCopyEx(Engine::s_Renderer,
                     m_TextureDict[p_TextureID],
                     &srcRect,
                     &dstRect,
                     p_Angle,
                     nullptr,
                     p_Flip);
}

void TextureManager::Drop(const char *p_TextureID)
{
    SDL_DestroyTexture(m_TextureDict[p_TextureID]);
    m_TextureDict.erase(p_TextureID);
}

void TextureManager::Clean()
{
    for (auto i : m_TextureDict)
    {
        SDL_DestroyTexture(i.second);
    }
    m_TextureDict.clear();
    SDL_Log("\nTexture cleaned");
}
