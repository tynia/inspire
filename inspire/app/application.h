#ifndef _INSPIRE_APPLICATION_INTERFACE_H_
#define _INSPIRE_APPLICATION_INTERFACE_H_

#include "inspire.h"
#include "control.h"

namespace inspire {

   class IApplication
   {
   public:
      IApplication() {}
      virtual ~IApplication() {}

      virtual void run() = 0;
   };
}
#endif