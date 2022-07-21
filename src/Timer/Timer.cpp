#include "Timer.h"

Timer::Timer()
    : m_LastTime(SDL_GetTicks()), m_DeltaTime(SDL_GetTicks() - m_LastTime)
{
}

void Timer::Tick()
{
}
