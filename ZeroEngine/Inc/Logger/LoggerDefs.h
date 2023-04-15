#ifndef LOGGER_DEFS_H
#define LOGGER_DEFS_H

namespace ZLogger
{
    enum class LogLevel
    {
        LOG_LVL_NONE    = 0,
        LOG_LVL_INFO    = 1,
        LOG_LVL_WARN    = 2,
        LOG_LVL_CRIT    = 3,
        LOG_LVL_MAX     = 4
    };
    
    const int NUM_LOG_CHANNELS = 4;
    const BITFIELD MAX_MASK = 0xFFFFFFFF;
    
    /// <summary>
    /// <code>LogChannel</code> values are formatted for use as bit flags.
    /// </summary>
    enum LogChannel
    {
        LOG_CHAN_NONE       = 1 << 0,   // None             (0000 0000 0000 0000 0000 0000 0000 0001)
        LOG_CHAN_GRAPHICS   = 1 << 1,   // Graphics         (0000 0000 0000 0000 0000 0000 0000 0010)
        LOG_CHAN_UI         = 1 << 2,   // User Interface   (0000 0000 0000 0000 0000 0000 0000 0100)
        LOG_CHAN_AUDIO      = 1 << 3    // Audio            (0000 0000 0000 0000 0000 0000 0000 1000)
    };
} // ZLogger

#endif // LOGGER_DEFS_H