#include "ZeroEngine.h"
#include "Logger\Logger.h"

namespace ZEngine
{
	/*****
	 * [initializae]
	 * Calls initialization for every subprocess of the engine.
	 *****/
	bool initialize()
	{
		LOGF_INFO("Beginning engine initialization...\n", "");
		return false;
	}

	/*****
	 * [loop]
	 * Engine loop.
	 *****/
	bool loop()
	{
		LOGF_INFO("Beginning engine loop...\n", "");
		return false;
	}

	/*****
	 * [log]
	 * Termination sequence to cleanup any loose ends.
	 *****/
	bool terminate()
	{
		LOGF_INFO("Beginning engine termination sequence...\n", "");
		return false;
	}
}