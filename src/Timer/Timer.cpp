#include "Timer.h"

Timer *Timer::s_Instance = nullptr;
Timer::Timer()
    : m_LastTime(SDL_GetTicks()), m_DeltaTime(SDL_GetTicks() - m_LastTime)
{
}

float Timer::GetDeltaTime()
{
    return m_DeltaTime;
}

void Timer::Tick()
{
    m_DeltaTime = (SDL_GetTicks() - m_LastTime) * (TARGET_FPS / 1000.0f);

    if (m_DeltaTime > TARGET_DELTA_TIME)
    {
        m_DeltaTime = TARGET_DELTA_TIME;
    }

    m_LastTime = SDL_GetTicks();
}
