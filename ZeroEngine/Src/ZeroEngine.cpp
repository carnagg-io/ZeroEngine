#include "ZeroEngine.h"
#include "Common.h"

namespace ZEngine
{
    /// <summary>
    /// Calls initialization for every subprocess of the engine.
    /// </summary>
    bool initialize()
    {
        LOGF_INFO("Beginning engine initialization.%s", "\n");
        if (Renderer* renderer = Renderer::instance())
        {
            return renderer->initialize();
        }
        return false;
    }
    
    /// <summary>
    /// Engine loop.
    /// </summary>
    bool loop()
    {
        LOGF_WARN("Beginning engine loop...\n", "");
        if (Renderer* renderer = Renderer::instance())
        {
            return renderer->loop();
        }
        return false;
    }
    
    /// <summary>
    /// Termination sequence to cleanup any loose ends.
    /// </summary>
    bool terminate()
    {
        LOGF_CRIT("Beginning engine termination sequence...\n", "");
        if (Renderer* renderer = Renderer::instance())
        {
            return renderer->terminate();
        }
        return false;
    }
}