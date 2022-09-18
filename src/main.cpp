#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Engine/Engine.h"

int main(int argc, char *argv[])
{
    std::cout << "Hello Dev\n";
    if (Engine::GetInstance()->Init("The Secret Zone By BE-Studio"))
    {
        Engine::GetInstance()->Loop();
        Engine::GetInstance()->Clean();
        Engine::GetInstance()->Quit();
    }
    else
    {
        std::cout << "Can't initialize Game Engine\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
