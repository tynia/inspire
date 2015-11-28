#ifndef _INSPIRE_NET_EVENT_ID_H_
#define _INSPIRE_NET_EVENT_ID_H_

#define MAKE_REPLY_EVENT(x) (0x10000000 | x)

enum EVENT_ID
{
   EVENT_INVALID          = -1,
   EVENT_BEGIN            = 0,
   EVENT_ENDIAN_REQ       = 0x00000001,
   EVENT_ENDIAN_RES       = MAKE_REPLY_EVENT(EVENT_ENDIAN_REQ),
};
#endif