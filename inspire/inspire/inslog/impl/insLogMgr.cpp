/*******************************************************************************
   Copyright (C) 2015 tynia.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU Affero General Public License, version 3,
   as published by the Free Software Foundation.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU Affero General Public License for more details.

   You should have received a copy of the GNU Affero General Public License
   along with this program. If not, see <http://www.gnu.org/license/>.
   
   Any problem, please ping xduilib@gmail.com, free service may be supported.
*******************************************************************************/
#include "insLogMgr.h"

namespace inspire {

   insLogMgr::insLogMgr() : IControl(MOD_LOG), _path(NULL)
   {
   }

   insLogMgr::~insLogMgr()
   {
      _path = NULL;
   }

   void insLogMgr::initialize()
   {
      _path = DEFAULT_LOG;
   }

   void insLogMgr::active()
   {
      // init member
   }

   void insLogMgr::destroy()
   {
      // destroy member
      _path = NULL;
   }

   void insLogMgr::writeLog(const int priority, const char* data)
   {
      IWriteLog* inst = _logMap[priority];
      if (NULL != inst)
      {
         inst->writeLog(priority, data);
      }
   }

   //////////////////////////////////////////////////////////////////////////
   // !!!@ a global logMgr instance is needed
   static insLogMgr extLogMgr;
   ILog* getLogMgr()
   {
      return &extLogMgr;
   }
}