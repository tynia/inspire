#include "ossFile.h"

namespace inspire {

#ifdef _WIN32
   ossFile::ossFile() : _handle(NULL)
#else
   ossFile::ossFile() : _fd(-1)
#endif
   {
      memset(_filename, 0, MAX_LOG_FILE_NAME + 1);
   }

#ifdef _WIN32
    ossFile::ossFile(const char* filename) : _handle(NULL)
#else
    ossFile::ossFile() : _fd(-1)
#endif
    {
       memset(_filename, 0, MAX_LOG_FILE_NAME + 1);
    }

    ossFile::~ossFile()
    {
       close();
    }

    bool ossFile::isOpened() const
    {
#ifdef _WIN32
       return INVALID_HANDLE_VALUE != _handle;
#else
       return (0 != _fd) && (-1 != _fd);
#endif
    }

    void ossFile::open(const int mod)
    {
#ifdef _WIN32
#else
#endif
    }

    void ossFile::openFile( const char* filename )
    {
       memcpy(_filename, filename, MAX_LOG_FILE_NAME);
       _handle = ::CreateFileA(_filename, 0, 0, NULL, 0, 0, NULL );
       if (INVALID_HANDLE_VALUE == _handle)
       {
          //LogError
       }
    }

    void ossFile::read(char* buffer, const int bufferLen, const int toRead, int& readed)
    {

    }

    void ossFile::write(char* buffer, const int bufferLen, const int toWrite, int& readed)
    {

    }

    void ossFile::close()
    {
#ifdef _WIN32
       if (INVALID_HANDLE_VALUE == _handle)
       {
          ::CloseHandle(_handle);
          _handle = INVALID_HANDLE_VALUE;
       }
#else
      if (isOpened())
      {
         ::close(_fd);
         _fd = 0;
      }
#endif
    }
}