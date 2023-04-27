#include "ZeroEngine.h"

int main()
{
    // Load INI here?
    
    ZEngine::initialize();
    ZEngine::loop();
    ZEngine::terminate();
    return 0;
}