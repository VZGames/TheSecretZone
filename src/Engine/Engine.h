#ifndef __ENGINE_H__
#define __ENGINE_H__
#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 640

#include <stdio.h>
#include "SDL2/SDL.h"
#include "../Input/Input.h"

class Engine
{
private:
    Engine();
    void Render();
    void Update();
    void HandleEvents();
    SDL_Window *m_Window;
    static Engine *s_Instance;

public:
    void Init(const char *p_Title, int p_Width = WINDOW_WIDTH, int p_Height = WINDOW_HEIGHT);
    void Loop();
    void Clean();
    void Quit();

    static bool s_Running;
    static SDL_Renderer *s_Renderer;
    static Engine *GetInstance() { return s_Instance = (s_Instance == nullptr) ? new Engine() : s_Instance; }
};
#endif // __ENGINE_H__