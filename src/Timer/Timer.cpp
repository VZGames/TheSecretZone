#include "Timer.h"

Timer::Timer()
    : m_LastTime(SDL_GetTicks()), m_DeltaTime(SDL_GetTicks() - m_LastTime)
{
}

void Timer::Tick()
{
    m_DeltaTime = SDL_GetTicks() - m_LastTime;

    m_LastTime = SDL_GetTicks();
}
