#include "Engine.h"

SDL_Renderer *Engine::s_Renderer = nullptr;
Engine *Engine::s_Instance = nullptr;
bool Engine::s_Running = false;
Engine::Engine()
    : m_Window(nullptr)
{
}

void Engine::Init(const char *p_Title, int p_Width, int p_Height)
{
    // initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    /*
        Create Window with:
        - title
        - initial x position
        - initial y position
        - flags
    */
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    m_Window = SDL_CreateWindow(p_Title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, window_flags);
    // Check that the window was successfully created
    if (m_Window == NULL)
    {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
    }

    s_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);

    if (s_Renderer)
    {
        // Select the color for drawing.
        SDL_SetRenderDrawColor(s_Renderer, 255, 255, 255, 255);
    }

    s_Running = true;
}

void Engine::Loop()
{
    const int frameDelay = 1000 / TARGET_FPS;

    Uint32 frameStart;
    Uint32 frameTime;
    while (s_Running)
    {
        frameStart = SDL_GetTicks();
        HandleEvents();
        Update();
        Render();

        Timer::GetInstance()->Tick();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < frameDelay)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
}

void Engine::Clean()
{
    SDL_DestroyRenderer(s_Renderer);
    // Close and destroy the window
    SDL_DestroyWindow(m_Window);
}

void Engine::Quit()
{
    // Clean up
    SDL_Quit();
}

void Engine::Render()
{
    SDL_RenderClear(s_Renderer);
    /* code here */
    SDL_RenderPresent(s_Renderer);
}

void Engine::Update()
{
}

void Engine::HandleEvents()
{
    Input::GetInstance()->Listen();
}
