#include "ZeroEngine.h"
#include "Logger\Logger.h"

namespace ZEngine
{
	bool initialize()
	{
		LOG_INFO("Beginning engine initialization...\n", "");
		return false;
	}

	bool loop()
	{
		LOG_INFO("Beginning engine loop...\n", "");
		return false;
	}

	bool terminate()
	{
		LOG_INFO("Beginning engine termination sequence...\n", "");
		return false;
	}
}