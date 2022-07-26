#include "Engine.h"
#include "../Graphics/TextureManager/TextureManager.h"
#include "../Input/Input.h"
#include "../Timer/Timer.h"
#include "../Objects/Player/Player.h"
#include "../Map/GameMap.h"
#include "../Map/MapParser.h"

SDL_Event Engine::s_Event;
SDL_Renderer *Engine::s_Renderer = nullptr;
Engine *Engine::s_Instance = nullptr;
bool Engine::s_Running = false;

Engine::Engine()
    : m_Window(nullptr)
{
    m_MapUrlCount = 1;
    m_PlayerCount = 1;
    m_MapUrls = new char[m_MapUrlCount];
    m_PLayers = new Player[m_PlayerCount];
}

bool Engine::Init(const char *p_Title, int p_Width, int p_Height)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
        return 0;
    }
    if (SDLNet_Init() != 0)
    {
        printf("Unable to initialize SDL Net: %s\n", SDL_GetError());
        return 0;
    }
    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        printf("Unable to initialize SDL Image: %s\n", SDL_GetError());
        return 0;
    }
    if (TTF_Init() != 0)
    {
        printf("Unable to initialize SDL Font: %s\n", SDL_GetError());
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
    m_Window = SDL_CreateWindow(p_Title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_Width, p_Height, window_flags);
    // Check that the window was successfully created
    if (m_Window == NULL)
    {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n\n", SDL_GetError());
    }

    s_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);

    if (s_Renderer)
    {
        // Select the color for drawing.
        SDL_SetRenderDrawColor(s_Renderer, 0, 0, 0, 255);
    }

    if (!MapParser::GetInstance()->LoadXML("assets/maps/phu_hoa.tmx"))
    {
        printf("Failed to load map");
        return 0;
    }
    m_CurrentGameMap = MapParser::GetInstance()->GetMap("PhuHoa");
    if(m_CurrentGameMap == nullptr)
    {
        printf("Game Map is Null\n");
        return 0;
    }

    printf("Current Map have %d Layers\n", m_CurrentGameMap->MapLayerCount());

    std::map<const char *, const char *> players;
    players["Player1"] = "assets/sprites/Characters/BunnyCharacterSpriteSheet.png";
    players["Player2"] = "assets/sprites/Characters/BunnyCharacterSpriteSheet.png";

    std::map<const char *, const char *>::iterator playerItr;
    for (playerItr = players.begin(); playerItr != players.end(); playerItr++)
    {
        TextureManager::GetInstance()->LoadTexture(playerItr->first, playerItr->second);
    }
    m_PLayers[0] = Player(new Properties("Player1", Vector2I(100 + (0 * 50), 100), 48, 48));


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

void Engine::Render()
{
    SDL_RenderClear(s_Renderer);
    m_CurrentGameMap->Render();
    m_PLayers[0].Render();
    SDL_RenderPresent(s_Renderer);
}

void Engine::Update()
{
    float dt = Timer::GetInstance()->GetDeltaTime();
    m_CurrentGameMap->Update();
    m_PLayers[0].Update(dt);
}

void Engine::HandleEvents()
{
    Input::GetInstance()->Listen();
}

Engine::~Engine()
{
    delete m_MapUrls;
    m_MapUrls = NULL;

    delete m_PLayers;
    m_PLayers = NULL;

    delete m_CurrentGameMap;
    m_CurrentGameMap = NULL;
}


void Engine::Clean()
{
    printf("Engine::Clean\n");
    MapParser::GetInstance()->Clean();
    TextureManager::GetInstance()->Clean();
    // Close and destroy the window and the renderer
    SDL_DestroyWindow(m_Window);
    SDL_DestroyRenderer(s_Renderer);
}

void Engine::Quit()
{
    printf("Engine::Quit\n");

    SDL_Quit();
    TTF_Quit();
    IMG_Quit();
    SDLNet_Quit();
}
