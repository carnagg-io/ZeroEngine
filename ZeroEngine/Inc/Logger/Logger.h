#ifndef LOGGER_H
#define LOGGER_H

#include "Logger\LogLevel.h"

#include <string>

#define LOG_BASE(logLevel, format, args) ZLogger::log((logLevel), (format), (args))
#define LOG_INFO(format, ...) LOG_BASE((LOG_LVL_INFO), (format), ##__VA_ARGS__)
#define LOG_WARN(format, ...) LOG_BASE((LOG_LVL_WARN), (format), ##__VA_ARGS__)
#define LOG_CRIT(format, ...) LOG_BASE((LOG_LVL_CRIT), (format), ##__VA_ARGS__)

namespace ZLogger
{
	void log(LogLevel logLevel, const char* format, ...);
	const char* getLogPrefix(LogLevel logLevel);
}

#endif