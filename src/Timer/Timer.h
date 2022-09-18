#ifndef __TIMER_H__
#define __TIMER_H__

#include <SDL2/SDL.h>

const int TARGET_FPS = 60;
const float TARGET_DELTA_TIME = 1.5f;

class Timer
{
private:
    Timer();
    float m_LastTime;
    float m_DeltaTime;

    static Timer *s_Instance;

public:
    void Tick();
    static Timer *GetInstance() { return s_Instance = (s_Instance == nullptr) ? new Timer() : s_Instance; }
    float GetDeltaTime();
};

#endif // __TIMER_H__
