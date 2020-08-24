#ifndef ZERO_ENGINE_DEFS_H
#define ZERO_ENGINE_DEFS_H

#define DEBUG !NDEBUG
#define WINDOWS _WIN32 || _WIN64

typedef unsigned int BITFIELD;

#if WINDOWS
#include <windows.h> 
#endif

#endif // ZERO_ENGINE_DEFS_H