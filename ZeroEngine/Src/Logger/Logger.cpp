#include "Logger\Logger.h"

#include <stdarg.h>

static BITFIELD ChannelFlags = 0x00000000; // 32 bits

#pragma message("TODO: Probably going to have to make this a class. :( How else will the logger bitfield be safe?\n")
namespace ZLogger
{
	/*****
	 * [initializeChannelFlags]
	 * Initialize the channel flag bit field.
	 *****/
	bool initializeChannelFlags()
	{
		// This needs file IO! Do it. Eventually.
		LOGF_WARN("Unable to initialize the channel flags. All channels enabled my default.\n", "");
		ChannelFlags = MAX_MASK;
		return false;
	}

	/*****
	 * [log]
	 * Wrapper for printf to include log level indication.
	 *****/
	void log(LogLevel logLevel, const char* format, ...)
	{
#if DEBUG

#pragma message("TODO: Look at the cost of calling malloc for every log call. C++20 supports format!\n")

		const char* prefix = getLogPrefix(logLevel);
		size_t finalSize = strlen(prefix) + strlen("\t") + strlen(format) + (size_t)1;
		char* finalFormat = (char*)malloc(finalSize);
		
		memset(finalFormat, 0, sizeof(char) * finalSize);
		strcat_s(finalFormat, finalSize, prefix);
		strcat_s(finalFormat, finalSize, "\t");
		strcat_s(finalFormat, finalSize, format);

#if WINDOWS
		SetConsoleTextAttribute(hConsoleHandle, getLogColor(logLevel));
#endif // WINDOWS

		va_list args;
		va_start(args, format);
		vprintf(finalFormat, args);
		va_end(args);

		free(finalFormat);
#endif // DEBUG
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

#if WINDOWS
	/*****
	 * [getLogColor]
	 * Returns an integer value for the color associated with the log level passed in.
	 *****/
	const int getLogColor(LogLevel logLevel)
	{
		switch (logLevel)
		{
		case LOG_LVL_INFO:
			return 15;
		case LOG_LVL_WARN:
			return 14;
		case LOG_LVL_CRIT:
			return 12;
		default:
			return 15;
		}
	}
#endif // WINDOWS
#endif // DEBUG
} // ZLogger