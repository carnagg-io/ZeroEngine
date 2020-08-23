#include "Logger\Logger.h"

#include <stdarg.h>

namespace ZLogger
{
	/*****
	 * [log]
	 * Wrapper for printf to include log level indication.
	 *****/
	void log(LogLevel logLevel, const char* format, ...)
	{
		const char* prefix = getLogPrefix(logLevel);
		int finalSize = strlen(prefix) + strlen("\t") + strlen(format) + (size_t)100;
		char* finalFormat = (char*)malloc(finalSize);
		
		strcpy_s(finalFormat, finalSize, prefix);
		strcat_s(finalFormat, finalSize, "\t");
		strcat_s(finalFormat, finalSize, format);

		va_list args;
		va_start(args, format);
		vprintf(finalFormat, args);
		va_end(args);

		free(finalFormat);
	}

	/*****
	 * [getLogPrefix]
	 * Returns a string associated with the logLevel passed in.
	 *****/
	const char* getLogPrefix(LogLevel logLevel)
	{
		switch (logLevel)
		{
		case LOG_LVL_INFO:
			return "[LOG_INFO]";
		case LOG_LVL_WARN:
			return "[LOG_WARN]";
		case LOG_LVL_CRIT:
			return "[LOG_CRIT]";
		default:
			return "[LOG_UNKN]";
		}
	}
}