#ifndef LOGGER_DEFS_H
#define LOGGER_DEFS_H

namespace ZLogger
{
	enum LogLevel
	{
		LOG_LVL_NONE = 0,
		LOG_LVL_INFO = 1,
		LOG_LVL_WARN = 2,
		LOG_LVL_CRIT = 3,
		LOG_LVL_MAX = 4
	};

	const int NUM_LOG_CHANNELS = 4;
	const BITFIELD MAX_MASK = 0xFFFFFFFF;

	enum LogChannel
	{
#pragma message("TODO: Need to create a bitfield with possible channels.\n");
		LOG_CHAN_NONE = 1 << 0, // None (0001)
		LOG_CHAN_GRAPHICS = 1 << 1, // Graphics (0010)
		LOG_CHAN_UI = 1 << 2, // User Interface (0100)
		LOG_CHAN_AUDIO = 1 << 3 // Audio (1000)
	};
} // ZLogger

#endif // LOGGER_DEFS_H