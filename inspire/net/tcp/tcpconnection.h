#ifndef _INSPIRE_NET_TCP_CONNECTION_H_
#define _INSPIRE_NET_TCP_CONNECTION_H_

#include "network.h"

namespace inspire {

   class endpoint;

   class tcpConnection
   {
   public:
      const int native() const { return _fd; }
      bool alive() const;
      void close();

   protected:
      int initialize();
      int bind(const uint port, endpoint& addr);
      int listen(const uint maxconn = 10);
      int accept(int& fd, endpoint& remote);
      int connect(const char* hostname, const uint port, endpoint& remote);
      int writeTo(const char* data, const uint len);
      int readFrom(char* buffer, const uint bufferLen, uint &recvLen);

   protected:
      tcpConnection();
      tcpConnection(const int sock);
      virtual ~tcpConnection() {}

   protected:
      int _fd;
   };
}
#endif