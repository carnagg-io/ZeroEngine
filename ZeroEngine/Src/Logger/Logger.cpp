#include "Logger\Logger.h"

#include <stdarg.h>

#if WINDOWS
static HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif // WINDOWS
static BITFIELD ChannelFlags = 0x00000000; // 32 bits

namespace ZLogger
{
    /// <summary>
    /// Initialize the channel flag bit field.
    /// </summary>
    bool initialize()
    {
#if DEBUG
#pragma message("TODO: INI file for logging channels. Printing to all channels now.\n")

        ChannelFlags = MAX_MASK;
        LOGF_INFO(LogFilter::LOG_FILTER_LOGGER, "Initialization complete.\n");
#endif // DEBUG
        return false;
    
    }

    /// <summary>
    /// Wrapper for printf to include log level indication and associated channel.
    /// </summary>
    void logFormatted(LogLevel logLevel, LogFilter logChannel, const char* logFormat, ...)
    {
#if DEBUG
        if ((ChannelFlags & logChannel) != logChannel)
        {
            return;
        }

#pragma message("TODO: Look at the cost of calling malloc for every log call. C++20 supports format!\n")

        const char* levelPrefix = getLogLevelPrefix(logLevel);
        const char* channelPrefix = getLogChannelPrefix(logChannel);
        size_t finalSize = strlen(levelPrefix) + strlen(channelPrefix) + strlen("\t") + strlen(logFormat) + (size_t)1;
        char* finalFormat = (char*)malloc(finalSize);

        memset(finalFormat, 0, sizeof(char) * finalSize);
        strcat_s(finalFormat, finalSize, levelPrefix);
        strcat_s(finalFormat, finalSize, channelPrefix);
        strcat_s(finalFormat, finalSize, "\t");
        strcat_s(finalFormat, finalSize, logFormat);

#if WINDOWS
        SetConsoleTextAttribute(hConsoleHandle, getLogColor(logLevel));
#endif // WINDOWS

        va_list args;
        va_start(args, logFormat);
        vprintf(finalFormat, args);
        va_end(args);

        free(finalFormat);
#endif // DEBUG
    }

    /// <summary>
    /// Returns a string associated with the logLevel passed in.
    /// </summary>
    const char* getLogLevelPrefix(LogLevel logLevel)
    {
#if DEBUG
        switch (logLevel)
        {
        case LogLevel::LOG_LVL_INFO:
            return "[LOGF_INFO]";
        case LogLevel::LOG_LVL_WARN:
            return "[LOGF_WARN]";
        case LogLevel::LOG_LVL_CRIT:
            return "[LOGF_CRIT]";
        default:
            return "[LOGF_NONE]";
        }
 #endif // DEBUG
    }

    /// <summary>
    /// Returns a string associated with the logChannel passed in.
    /// </summary>
    const char* getLogChannelPrefix(LogFilter logChannel)
    {
#if DEBUG
        switch (logChannel)
        {
        case LogFilter::LOG_FILTER_RENDERER:
            return "[RENDERER]";
        case LogFilter::LOG_FILTER_UI:
            return "[UI]";
        case LogFilter::LOG_FILTER_AUDIO:
            return "[AUDIO]";
        case LogFilter::LOG_FILTER_INPUT:
            return "[INPUT]";
        case LogFilter::LOG_FILTER_LOGGER:
            return "[LOGGER]";
        default:
            return "[NONE]";
        }
#endif // DEBUG
    }

    /// <summary>
    /// Returns an integer value for the color associated with the log level passed in.
    /// </summary>
    const int getLogColor(LogLevel logLevel)
    {
#if DEBUG && WINDOWS
        switch (logLevel)
        {
        case LogLevel::LOG_LVL_INFO:
            return 15;  // white
        case LogLevel::LOG_LVL_WARN:
            return 14;  // yellow
        case LogLevel::LOG_LVL_CRIT:
            return 12;  // red
        default:
            return 15;  // white
        }
#else // DEBUG && WINDOWS
        return 0;
#endif // DEBUG && WINDOWS
    }
} // ZLogger