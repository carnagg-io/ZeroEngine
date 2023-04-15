#ifndef LOGGER_H
#define LOGGER_H

#include "ZeroEngineDefs.h"
#include "Logger\LoggerDefs.h"

#include <string>
/// <summary>
/// <code>LOGF_BASE</code> printf wrapper macro for easy, formatted logging.
/// </summary>
#define LOGF_BASE(logLevel, logFormat, ...) ZLogger::logFormatted((logLevel), (logFormat), ##__VA_ARGS__)

 /// <summary>
 /// <code>LOGF_INFO</code> No urgency associated with this call, used for tracking processes primarily.
 /// </summary>
#define LOGF_INFO(logFormat, ...) LOGF_BASE((ZLogger::LogLevel::LOG_LVL_INFO), (logFormat), ##__VA_ARGS__)

/// <summary>
/// <code>LOGF_WARN</code> Minor urgency associated with this call, used for warning.
/// </summary>
#define LOGF_WARN(logFormat, ...) LOGF_BASE((ZLogger::LogLevel::LOG_LVL_WARN), (logFormat), ##__VA_ARGS__)

/// <summary>
/// <code>LOGF_CRIT</code> Major urgency associated with this call, used for critical issues.
/// </summary>
#define LOGF_CRIT(logFormat, ...) LOGF_BASE((ZLogger::LogLevel::LOG_LVL_CRIT), (logFormat), ##__VA_ARGS__)

namespace ZLogger
{
    bool initializeChannelFlags();
    void logFormatted(LogLevel logLevel, const char* logFormat, ...);
    const char* getLogPrefix(LogLevel logLevel);
    const int getLogColor(LogLevel logLevel);
} // ZLogger

#endif // LOGGER_H