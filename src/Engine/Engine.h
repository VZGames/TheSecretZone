#ifndef __ENGINE_H__
#define __ENGINE_H__
#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 640

#include <stdio.h>
#include <vector>
#include "SDL2/SDL.h"
#include "SDL2/SDL_net.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_mixer.h"
#include "../Graphics/TextureManager/TextureManager.h"
#include "../Input/Input.h"
#include "../Timer/Timer.h"

#include "../Objects/Player/Player.h"

class Player;

class Engine
{
private:
    int m_PlayerCount;
    SDL_Window *m_Window;
    static Engine *s_Instance;
    Player *m_PLayers;

private:
    Engine();
    void Render();
    void Update();
    void HandleEvents();

public:
    ~Engine();
    bool Init(const char *p_Title, int p_Width = WINDOW_WIDTH, int p_Height = WINDOW_HEIGHT);
    void Loop();
    void Clean();
    void Quit();
    static bool s_Running;
    static SDL_Renderer *s_Renderer;
    static Engine *GetInstance() { return s_Instance = (s_Instance == nullptr) ? new Engine() : s_Instance; }
};
#endif // __ENGINE_H__