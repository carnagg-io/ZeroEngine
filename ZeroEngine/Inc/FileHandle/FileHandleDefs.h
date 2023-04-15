#ifndef FILE_HANDLE_DEFS_H
#define FILE_HANDLE_DEFS_H

namespace ZEngine
{
    enum FileMode
    {
        FILE_MODE_NONE  = 1 << 0,   // None (0000 0000 0000 0000 0000 0000 0000 0001)
        FILE_MODE_OPEN  = 1 << 1,   // Open     (0000 0000 0000 0000 0000 0000 0000 0010)
        FILE_MODE_READ  = 1 << 2,   // Read     (0000 0000 0000 0000 0000 0000 0000 0100)
        FILE_MODE_WRITE = 1 << 3,   // Write    (0000 0000 0000 0000 0000 0000 0000 0001)
        FILE_MODE_CLOSE = 1 << 4,   // Close    (0000 0000 0000 0000 0000 0000 0000 0010)
        FILE_MODE_MAX   = 1 << 5    // Max      (0000 0000 0000 0000 0000 0000 0000 0100)
    };
}

#endif // FILE_HANDLE_DEFS_H