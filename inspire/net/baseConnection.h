#ifndef _INSPIRE_NET_CONNECTION_H_
#define _INSPIRE_NET_CONNECTION_H_

#include "endpoint.h"

namespace inspire {

   class baseConnection
   {
   public:
      const int native() const { return _fd; }

      const char* toString() const { return _addr.toString().c_str(); }

      bool alive();

      void close();

   protected:
      baseConnection();

      baseConnection(int sock);

      virtual ~baseConnection() { close(); }

   protected:
      int _fd;
      endpoint _addr;
   };

   class INetBase
   {
   public:
      virtual ~INetBase() {}
      virtual int doWrite() = 0;
      virtual int doRead() = 0;
   };
}
#endif