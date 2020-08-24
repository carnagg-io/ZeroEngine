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
#if DEBUG

#pragma message("TODO: Look at the cost of calling malloc for every log call.")

		const char* prefix = getLogPrefix(logLevel);
		int finalSize = strlen(prefix) + strlen("\t") + strlen(format) + 1;
		char* finalFormat = (char*)malloc(finalSize);
		
		memset(finalFormat, 0, sizeof(char) * finalSize);
		strcat_s(finalFormat, finalSize, prefix);
		strcat_s(finalFormat, finalSize, "\t");
		strcat_s(finalFormat, finalSize, format);

		va_list args;
		va_start(args, format);
		vprintf(finalFormat, args);
		va_end(args);

		free(finalFormat);
#endif
	}

#if DEBUG
	/*****
	 * [getLogPrefix]
	 * Returns a string associated with the logLevel passed in.
	 *****/
	const char* getLogPrefix(LogLevel logLevel)
	{
		switch (logLevel)
		{
		case LOG_LVL_INFO:
			return "[LOGF_INFO]";
		case LOG_LVL_WARN:
			return "[LOGF_WARN]";
		case LOG_LVL_CRIT:
			return "[LOGF_CRIT]";
		default:
			return "[LOGF_NONE]";
		}
		return "";
	}
#endif
}