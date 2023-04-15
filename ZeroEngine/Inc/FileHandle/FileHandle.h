#ifndef FILE_HANDLE_H
#define FILE_HANDLE_H

#include "ZeroEngineDefs.h"
#include "FileHandleDefs.h"

#include <fstream>

namespace ZEngine
{
    class FileHandle
    {
    private:
        std::fstream m_fileStream;
        const char* m_filePath;
        BITFIELD m_fileMode = FileMode::FILE_MODE_NONE;
    
    public:
        FileHandle(const char* filePath);
        ~FileHandle();
     
        bool openFile();
        bool closeFile();
        bool isValid();
    };
}

#endif // FILE_HANDLE_H