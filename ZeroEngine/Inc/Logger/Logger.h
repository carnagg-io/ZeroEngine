#ifndef LOGGER_H
#define LOGGER_H

#include "ZeroEngineDefs.h"
#include "Logger\LoggerDefs.h"

#include <string>

/*****
 * [LOGF_BASE] printf wrapper macro for easy, formatted logging.
 * [LOGF_INFO] No urgency associated with this call, used for tracking processes primarily.
 * [LOGF_WARN] Minor urgency associated with this call, used for warning.
 * [LOGF_CRIT] Major urgency associated with this call, used for critical issues.
 *****/
#pragma message("TODO: Implement log text color per platform. Start with Windows.")

#define LOGF_BASE(logLevel, format, ...) ZLogger::log((logLevel), (format), ##__VA_ARGS__)
#define LOGF_INFO(format, ...) LOGF_BASE((ZLogger::LOG_LVL_INFO), (format), ##__VA_ARGS__)
#define LOGF_WARN(format, ...) LOGF_BASE((ZLogger::LOG_LVL_WARN), (format), ##__VA_ARGS__)
#define LOGF_CRIT(format, ...) LOGF_BASE((ZLogger::LOG_LVL_CRIT), (format), ##__VA_ARGS__)

namespace ZLogger
{
#if WINDOWS
	static HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif // WINDOWS

	bool initializeChannelFlags();
	void log(LogLevel logLevel, const char* format, ...);
	const char* getLogPrefix(LogLevel logLevel);
	const int getLogColor(LogLevel logLevel);
} // ZLogger

#endif // LOGGER_H