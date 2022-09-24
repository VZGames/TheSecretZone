#ifndef __ENGINE_H__
#define __ENGINE_H__
#define WIN_WIDTH 960
#define WIN_HEIGHT 640

#include <stdio.h>
#include <vector>
#include <thread>
#include <time.h>
#include <map>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

class Player;
class GameMap;

class Engine
{
private:
    GameMap *m_CurrentGameMap;
    int m_PlayerCount, m_MapUrlCount;
    SDL_Window *m_Window;
    static Engine *s_Instance;
    char *m_MapUrls;
    Player *m_PLayers;

private:
    Engine();
    void Render();
    void Update();
    void HandleEvents();

public:
    ~Engine();
    bool Init(const char *p_Title, int p_Width = WIN_WIDTH, int p_Height = WIN_HEIGHT);
    void Loop();
    void Clean();
    void Quit();
    static bool s_Running;
    static SDL_Renderer *s_Renderer;
    static SDL_Event s_Event;
    static Engine *GetInstance() { return s_Instance = (s_Instance == nullptr) ? new Engine() : s_Instance; }
};
#endif // __ENGINE_H__
