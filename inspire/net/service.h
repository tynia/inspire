#ifndef _INSPIRE_NET_SERVICE_H_
#define _INSPIRE_NET_SERVICE_H_

#include "util/inspire.h"
#include "thread/thread.h"

namespace inspire {

   class IControl;
   class ISession;

   typedef std::map<int64, ISession*> SessionList;

   class IService : public IControl
   {
   public:
      virtual ~IService() {}

      virtual int addSession(ISession* s);

      virtual int removeSession(ISession* s);

      virtual bool stopped() const;

      virtual void init() = 0;

      virtual void run(uint service) = 0;

      virtual void destroy() = 0;
   };

   class IOService;
   class IThreadMgr;
   class Service : public IService//, public threadEntity
   {
   public:
      Service();
      virtual ~Service();

      void initService();
      void stop();

      virtual void init();
      virtual void run(uint service);
      virtual void destroy();

   protected:
      bool              _initialized;
      IAsyncConnection* _async;
      IOService*        _ioservice;
      thread*           _thd;
      SessionList       _sessions;
   };
}
#endif