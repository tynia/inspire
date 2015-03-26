#include "refStream.h"

namespace inspire {

   refStream::refStream() : _refCount(NULL), _capacity(0), _refData(NULL)
   {
      _refCount = new unsigned int(0);
      _inc();
   }

   refStream::refStream(const char* data, const size_t len)
   {
      _refCount = new unsigned int(0);
      _refData  = const_cast<char*>(data);
      _capacity = len;
      _inc();
   }

   refStream::refStream(const refStream& rhs)
   {
      _refCount = rhs._refCount;
      _capacity = rhs._capacity;
      _refData  = rhs._refData;
      _inc();
   }

   refStream::~refStream()
   {
      _release();
   }

   bool refStream::shared() const
   {
      return (*_refCount > 0);
   }

   char* refStream::data() const
   {
      return _refData;
   }

   const size_t refStream::capacity() const
   {
      return _capacity;
   }

   void refStream::_release()
   {
      _dec();
      if (0 == *_refCount)
      {
         if (_refData)
         {
            ::free(_refData);
            _refData = NULL;
         }
         delete _refCount;
         _refCount = NULL;
      }
   }

   void refStream::reverse(const size_t size)
   {
      if (size <= _capacity)
      {
         return;
      }

      if (0 == _capacity && NULL == _refData)
      {
         _alloc(size);
      }
      else
      {
         _realloc(size);
      }
   }

   refStream& refStream::operator= (const refStream& rhs)
   {
      _release();
      _refCount = rhs._refCount;
      _capacity = rhs._capacity;
      _refData = rhs._refData;
      _inc();

      return *this;
   }

   void refStream::_inc()
   {
      ++(*_refCount);
   }

   void refStream::_dec()
   {
      --(*_refCount);
   }

   void refStream::_alloc(const size_t size)
   {
      char* ptr = (char*)::malloc(size);
      if (NULL == ptr)
      {
         //LogError
      }
      _refData = ptr;
   }

   void refStream::_realloc(const size_t size)
   {
      char* ptr = (char*)::realloc(_refData, size);
      if (NULL == ptr)
      {
         //LogError
      }
      _refData = ptr;
      _capacity = size;
   }
}