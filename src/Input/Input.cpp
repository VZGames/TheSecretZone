#include "Input.h"
#include "../Engine/Engine.h"


Input *Input::s_Instance = nullptr;

void Input::Listen()
{
    while (SDL_PollEvent(&Engine::s_Event))
    {
        switch (Engine::s_Event.type)
        {
        case SDL_QUIT:
            Engine::s_Running = false;
            break;
        default:
            break;
        }
    }
}

bool Input::GetKeyDown(SDL_Scancode p_NumKey)
{
    if (m_KeyBoardState[p_NumKey])
    {
        return 1;
    }
    return 0;
}

Input::Input()
{
    m_KeyBoardState = SDL_GetKeyboardState(nullptr);
}

Input::~Input()
{

}
