#ifndef __INPUT_H__
#define __INPUT_H__

#include <iostream>
#include "SDL2/SDL_events.h"

class Input
{
private:
    Input();
    const Uint8 *m_KeyBoardState;
    static Input *s_Instance;

public:
    ~Input();
    void Listen();
    bool GetKeyDown(SDL_Scancode p_NumKey);
    void KeyUP() {};
    void KeyDown() {};
    static Input *GetInstance() { return s_Instance = (s_Instance == nullptr) ? new Input() : s_Instance; }
};
#endif // __INPUT_H__
