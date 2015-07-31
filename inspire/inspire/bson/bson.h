#ifndef _INSPIRE_BSON_H_
#define _INSPIRE_BSON_H_

#include "inspire.h"

namespace inspire {

   namespace bson {

      enum vType
      {
         VT_MINKEY           = 0xFF,  /* min key */
         VT_EOO              = 0x00,  /* end of object */
         VT_DOUBLE           = 0x01,  /* 64 bit floating point */
         VT_STRING           = 0x02,  /* UTF-8 string */
         VT_OBJECT           = 0x03,  /* embedded object */
         VT_ARRAY            = 0x04,  /* array */
         VT_BINDATA          = 0x05,  /* binary data */
         VT_UNDEFINED        = 0x06,  /* undefined value, deprecated */
         VT_OID              = 0x07,  /* object id */
         VT_BOOL             = 0x08,  /* boolean 0x00 = false, 0x01 = true */
         VT_DATE             = 0x09,  /* UTC date */
         VT_NULL             = 0x0A, /* value of null */
         VT_REGEX            = 0x0B, /* regular expression */
         VT_DBREF_DEPRECATED = 0x0C, /* deprecated */
         VT_CODE_DEPRECATED  = 0x0D, /* deprecated */
         VT_SYMBOL           = 0x0E, /* deprecated */
         VT_CODE             = 0x0F, /* javascript code*/
         VT_INT              = 0x10, /* 32 bit number */
         VT_TIMESTAMP        = 0x11, /* int64 */
         VT_LONG             = 0x12, /* int64 */
         VT_MAXTYPE          = VT_LONG,
         VT_MAXKEY           = 0x7F, /* max key */
      };

      class binData;
      class kvMap
      {
      public:
         const char* toString();

         const unsigned valueLen() const
         {
            return 0;
         }

         const char* key() const
         {
            return _key;
         }

      protected:
         kvMap();
         virtual ~kvMap();

         const int _type() const
         {
            return _vtype;
         }

      private:
         void put(const char* k, bool v);
         void put(const char* k, int v);
         void put(const char* k, int64 v);
         void put(const char* k, double v);
         void put(const char* k, const char* v);
         void put(const char* k, const std::string& v);

         // date
         // oid
         // array
         // null
         void put(const char type, const char* k,
                  const char* pValue, const unsigned len);

      protected:
         char _vtype;
         const char* _key;
         char* _value;
      };
   }
}

#endif