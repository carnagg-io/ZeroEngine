#include "ZeroEngine.h"

int main()
{
    ZEngine::initialize();
    ZEngine::loop();
    ZEngine::terminate();
    return 0;
}