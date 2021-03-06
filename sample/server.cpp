#include "util/inspire.h"
#include "util/assert.h"
#include "net.h"
#include "thread/threads.h"
#include "util/system/condition.h"

struct msgClient
{
   int64 id;
   char data[100];
};

class Server
{
public:
   Server() : _fd(-1), _stop(false)
   {}

   ~Server() 
   {
      if (!_sessions.empty())
      {
         for (int idx = 0; idx < _sessions.size(); ++idx)
         {
            ::closesocket(_sessions[idx]);
         }
      }
   }

   void stop()
   {
      _stop = true;
   }

   virtual const int run()
   {
      _fd = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
      STRONG_ASSERT(SOCKET_ERROR != _fd, "Failed to initialize socket");

      int port = 50000;
      sockaddr_in addr;
      memset(&addr, 0, sizeof(sockaddr_in));
      addr.sin_family = AF_INET;
      addr.sin_addr.s_addr = htonl(INADDR_ANY);
      addr.sin_port = htons(port);

      int rc = ::bind(_fd, (sockaddr*)&addr, 0);
      STRONG_ASSERT(SOCKET_ERROR != rc, "Failed to bind socket");

      rc = ::listen(_fd, 1000000);
      STRONG_ASSERT(SOCKET_ERROR != rc, "Failed to listen");

      _stop = false;
      while (!_stop)
      {
         int remote;
         sockaddr_in raddr;
         int len = sizeof(sockaddr);
         remote = ::accept(_fd, (sockaddr*)&raddr, &len);
         if (SOCKET_ERROR != remote)
         {
            msgClient cc;
            ::recv(remote, (char*)&cc, sizeof(int64) + 100, 0);
            std::cout << "Receive from client: " << cc.id << ", msg: " << cc.data << std::endl;
            _sessions.push_back(remote);
         }
      }

      return 0;
   }

private:
   bool _stop;
   int _fd;
   std::vector<int> _sessions;
};

int main(int argc, char** argv)
{
   Server serv;
   serv.run();
   return 0;
}