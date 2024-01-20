#ifndef LOGGER_H
#define LOGGER_H

#include "ZeroEngineDefs.h"
#include "Logger\LoggerDefs.h"

#include <string>
/// <summary>
/// <code>LOGF_BASE</code> printf wrapper macro for easy, formatted logging.
/// </summary>
#define LOGF_BASE(logLevel, logChannel, logFormat, ...) ZLogger::logFormatted((logLevel), (logChannel), (logFormat), ##__VA_ARGS__)

 /// <summary>
 /// <code>LOGF_INFO</code> No urgency associated with this call, used for tracking processes primarily.
 /// </summary>
#define LOGF_INFO(logChannel, logFormat, ...) LOGF_BASE((ZLogger::LogLevel::LOG_LVL_INFO), (logChannel), (logFormat), ##__VA_ARGS__)

/// <summary>
/// <code>LOGF_WARN</code> Minor urgency associated with this call, used for warning.
/// </summary>
#define LOGF_WARN(logChannel, logFormat, ...) LOGF_BASE((ZLogger::LogLevel::LOG_LVL_WARN), (logChannel), (logFormat), ##__VA_ARGS__)

/// <summary>
/// <code>LOGF_CRIT</code> Major urgency associated with this call, used for critical issues.
/// </summary>
#define LOGF_CRIT(logChannel, logFormat, ...) LOGF_BASE((ZLogger::LogLevel::LOG_LVL_CRIT), (logChannel), (logFormat), ##__VA_ARGS__)

namespace ZLogger
{
    bool initialize();
    void logFormatted(LogLevel logLevel, LogFilter logChannel, const char* logFormat, ...);
    const char* getLogLevelPrefix(LogLevel logLevel);
    const char* getLogChannelPrefix(LogFilter logChannel);
    const int getLogColor(LogLevel logLevel);
} // ZLogger

#endif // LOGGER_H