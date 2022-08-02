#include <iostream>
#include "Engine/Engine.h"

int main(int argc, char *argv[])
{
    std::cout << "\n";
    if (Engine::GetInstance()->Init("The Secret Zone"))
    {
        Engine::GetInstance()->Loop();
        Engine::GetInstance()->Clean();
        Engine::GetInstance()->Quit();
    }
    else
    {
        SDL_Log("Can't initialize Game Engine");
        return 1;
    }

    return 0;
}
