#include "ZeroEngine.h"
#include "Logger\Logger.h"

namespace ZEngine
{
    /// <summary>
    /// Calls initialization for every subprocess of the engine.
    /// </summary>
    bool initialize()
    {
        LOGF_INFO("Beginning engine initialization.%s", "\n");
        return false;
    }
    
    /// <summary>
    /// Engine loop.
    /// </summary>
    bool loop()
    {
        LOGF_WARN("Beginning engine loop...\n", "");
        return false;
    }
    

    /// <summary>
    /// Termination sequence to cleanup any loose ends.
    /// </summary>
    bool terminate()
    {
        LOGF_CRIT("Beginning engine termination sequence...\n", "");
        return false;
    }
}