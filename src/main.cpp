#include <iostream>
#include "Engine/Engine.h"

int main(int argc, char *argv[])
{
    Engine::GetInstance()->Init("The Secret Zone");
    Engine::GetInstance()->Loop();
    Engine::GetInstance()->Clean();
    Engine::GetInstance()->Quit();

    return 0;
}
