#include "Input.h"

SDL_Event Input::s_Event;
Input *Input::s_Instance = nullptr;

void Input::Listen()
{
    while (SDL_PollEvent(&s_Event))
    {
        switch (s_Event.type)
        {
        case SDL_QUIT:
            Engine::s_Running = false;
            break;
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            m_KeyBoardState = SDL_GetKeyboardState(nullptr);
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
