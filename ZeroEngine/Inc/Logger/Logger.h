#ifndef LOGGER_H
#define LOGGER_H

#include "ZeroEngineDefs.h"
#include "Logger\LogLevel.h"

#include <string>

	/*****
	 * [LOGF_BASE] printf wrapper macro for easy, formatted logging.
	 * [LOGF_INFO] No urgency associated with this call, used for tracking processes primarily.
	 * [LOGF_WARN] Minor urgency associated with this call, used for warning.
	 * [LOGF_CRIT] Major urgency associated with this call, used for critical issues.
	 *****/
#define LOGF_BASE(logLevel, format, args) ZLogger::log((logLevel), (format), (args))
#define LOGF_INFO(format, ...) LOGF_BASE((LOG_LVL_INFO), (format), ##__VA_ARGS__)
#define LOGF_WARN(format, ...) LOGF_BASE((LOG_LVL_WARN), (format), ##__VA_ARGS__)
#define LOGF_CRIT(format, ...) LOGF_BASE((LOG_LVL_CRIT), (format), ##__VA_ARGS__)

namespace ZLogger
{
	void log(LogLevel logLevel, const char* format, ...);
	const char* getLogPrefix(LogLevel logLevel);
}

#endif