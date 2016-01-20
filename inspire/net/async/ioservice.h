#ifndef _INSPIRE_NET_IO_SERVICE_H_
#define _INSPIRE_NET_IO_SERVICE_H_

#include "network.h"
#include "util/inspire.h"

namespace inspire {

   class asyncConnection;
   enum IOEvent;
   class IOServiceOverlapped;

   class IOService
   {
   public:
      IOService();
      virtual ~IOService();

      void init(const uint threadCount = 0);

      void bind(asyncConnection* conn);

      void run();

      void stop();

      void destroy();

      void associate(IOServiceOverlapped* ctx);

      int  addSession(asyncConnection* conn);

      int  removeSession(asyncConnection* conn);

      void postEvent(IOServiceOverlapped* ctx, IOEvent ioe);

      bool stopped() const;

   protected:
      void _initWorkThread();
      void _doAccept();
      void _doSend();
      void _doRecv();

   protected:
      bool              _stopService;
      HANDLE            _hIOCP;
      uint              _threadCount;
      asyncConnection*  _conn;
      int64*            _threadID;
      LPFN_ACCEPTEX     _lpfnAcceptEx;
      
   private:
      OverlappedContext _overlappedContext[MAX_POST_ACCEPT];
   };
}
#endif