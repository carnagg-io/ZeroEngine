#include "FileHandle\FileHandle.h"

namespace ZEngine
{
    FileHandle::FileHandle(const char* filePath)
        : m_filePath(filePath)
    {
        this->openFile();
    }
    
    FileHandle::~FileHandle()
    {
        this->closeFile();
    }
    
    bool FileHandle::openFile()
    {
        return false;
    }
    
    bool FileHandle::closeFile()
    {
        return false;
    }
    
    bool FileHandle::isValid()
    {
        return false;
    }
}