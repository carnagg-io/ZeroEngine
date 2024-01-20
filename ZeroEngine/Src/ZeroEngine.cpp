#include "ZeroEngine.h"
#include "Common.h"

namespace ZEngine
{
    /// <summary>
    /// Calls initialization for every subprocess of the engine.
    /// </summary>
    bool initialize()
    {
        // LOGGER
        ZLogger::initialize();

        LOGF_INFO(ZLogger::LogFilter::LOG_FILTER_NONE, "Beginning engine initialization.%s", "\n");
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
        LOGF_WARN(ZLogger::LogFilter::LOG_FILTER_NONE, "Beginning engine loop...\n", "");
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
        LOGF_CRIT(ZLogger::LogFilter::LOG_FILTER_NONE, "Beginning engine termination sequence...\n", "");
        if (Renderer* renderer = Renderer::instance())
        {
            return renderer->terminate();
        }
        return false;
    }
}