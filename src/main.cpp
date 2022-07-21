#include <iostream>
#include "Engine/Engine.h"

int main(int argc, char *argv[])
{
    Engine::GetInstance()->Init("Mun");
    Engine::GetInstance()->Loop();
    Engine::GetInstance()->Clean();
    Engine::GetInstance()->Quit();

    return 0;
}
