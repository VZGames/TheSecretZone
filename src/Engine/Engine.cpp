#include "Engine.h"
#include "../Objects/Player/Player.h"

SDL_Renderer *Engine::s_Renderer = nullptr;
Engine *Engine::s_Instance = nullptr;
bool Engine::s_Running = false;
Player *player = nullptr;

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
        SDL_SetRenderDrawColor(s_Renderer, 0, 0, 0, 255);
    }

    Renderer::GetInstance()->LoadTexture("Player1", "assets/sprites/Characters/BunnyCharacterSpriteSheet.png");
    player = new Player(new Properties("Player1", Vector2I(100, 200), 48, 48));
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
    Renderer::GetInstance()->Clean();
    // Close and destroy the window
    SDL_DestroyWindow(m_Window);
}

void Engine::Render()
{
    SDL_RenderClear(s_Renderer);
    player->Render();
    SDL_RenderPresent(s_Renderer);
}

void Engine::Update()
{
    float dt = Timer::GetInstance()->GetDeltaTime();
    player->Update(dt);
}

void Engine::HandleEvents()
{
    Input::GetInstance()->Listen();
}

void Engine::Quit()
{
    // Clean up
    SDL_Quit();
}