#include "Engine.h"

SDL_Renderer *Engine::s_Renderer = nullptr;
Engine *Engine::s_Instance = nullptr;
bool Engine::s_Running = false;
MapParser *MapParser::s_Instance = nullptr;

Engine::Engine()
    : m_Window(nullptr)
{
    m_MapUrlCount = 1;
    m_PlayerCount = 2;
    m_MapUrls = new char[m_MapUrlCount];
    m_PLayers = new Player[m_PlayerCount];
}

bool Engine::Init(const char *p_Title, int p_Width, int p_Height)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 0;
    }
    if (SDLNet_Init() != 0)
    {
        SDL_Log("Unable to initialize SDL Net: %s", SDL_GetError());
        return 0;
    }
    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        SDL_Log("Unable to initialize SDL Image: %s", SDL_GetError());
        return 0;
    }
    if (TTF_Init() != 0)
    {
        SDL_Log("Unable to initialize SDL Font: %s", SDL_GetError());
        return 0;
    }

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
        SDL_Log("Could not create window: %s\n", SDL_GetError());
    }

    s_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);

    if (s_Renderer)
    {
        // Select the color for drawing.
        SDL_SetRenderDrawColor(s_Renderer, 255, 255, 255, 255);
    }

    if (!MapParser::GetInstance()->loadXML("assets/maps/test.tmx"))
    {
        SDL_Log("Failed to load map");
        return 0;
    }

    m_CurrentGameMap = MapParser::GetInstance()->GetMap("PhuHoa");

    std::map<const char *, const char *> players;
    players["Player 1"] = "assets/sprites/Characters/BunnyCharacterSpriteSheet.png";
    players["Player 2"] = "assets/sprites/Characters/BunnyCharacterSpriteSheet.png";

    std::map<const char *, const char *>::iterator playerItr;
    int playerIndex = 0;
    for (playerItr = players.begin(); playerItr != players.end(); playerItr++)
    {
        TextureManager::GetInstance()
            ->LoadTexture(playerItr->first, playerItr->second);
        Player *player = new Player(new Properties(playerItr->first, Vector2I(100 + (playerIndex * 50), 100), 48, 48));
        m_PLayers[playerIndex] = *player;
        playerIndex++;
    }

    s_Running = true;

    return 1;
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
    TextureManager::GetInstance()->Clean();
    // Close and destroy the window and the renderer
    SDL_DestroyWindow(m_Window);
    SDL_DestroyRenderer(s_Renderer);
}

void Engine::Render()
{
    SDL_RenderClear(s_Renderer);
    for (int i = 0; i < m_PlayerCount; i++)
    {
        m_PLayers[i].Render();
    }

    SDL_RenderPresent(s_Renderer);
}

void Engine::Update()
{
    float dt = Timer::GetInstance()->GetDeltaTime();
    for (int i = 0; i < m_PlayerCount; i++)
    {
        m_PLayers[i].Update(dt);
    }
}

void Engine::HandleEvents()
{
    Input::GetInstance()->Listen();
}

Engine::~Engine()
{
    delete m_PLayers;
    m_PLayers = NULL;
}

void Engine::Quit()
{
    // Clean up
    SDL_Quit();
    TTF_Quit();
    IMG_Quit();
    SDLNet_Quit();
}