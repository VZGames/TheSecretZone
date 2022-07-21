#ifndef __INPUT_H__
#define __INPUT_H__

#include <iostream>
#include "SDL2/SDL_events.h"
#include "../Engine/Engine.h"

class Input
{
private:
    Input();
    const Uint8 *m_KeyBoardState;
    static SDL_Event s_Event;
    static Input *s_Instance;

public:
    void Listen();
    bool GetKeyDown(SDL_Scancode p_NumKey);
    static Input *GetInstance() { return s_Instance = (s_Instance == nullptr) ? new Input() : s_Instance; }
};
#endif // __INPUT_H__