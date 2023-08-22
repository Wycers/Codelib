#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "utf8.h"

extern unsigned char *codepoint_to_utf8(const unsigned int  cp,
                                        unsigned char      *val) {

   if (cp <= 0x7f) {
      sprintf((char *)val, "%c", (char)cp);
   } else {
      if ((cp >= 0x80) && (cp <= 0x07ff)) {
         // 2-char UTF8 character
         val[0] = cp / 64 + 192;
         val[1] = cp % 64 + 128;
         val[2] = '\0';
      } else if (((cp >= 0x0800) && (cp <= 0xd7ff))
               || ((cp >= 0xe000) && (cp <= 0xffff))) {
         // 1110xxxx 10xxxxxx 10xxxxxx
         val[0] = cp / 4096 + 224;
         val[1] = (cp % 4096) / 64 + 128;
         val[2] = cp % 64 + 128;
         val[3] = '\0';
      } else {
         val[0] = cp / 262144 + 240;
         val[1] = (cp % 262144) / 4096 + 128;
         val[2] = (cp % 4096) / 64 + 128;
         val[3] = cp % 64 + 128;
         val[4] = '\0';
      } 
   }
   return val;
}

extern int  isutf8(const unsigned char *u) {
   // Validate utf8 character.
   // Returns the length, 0 if invalid.
   int len = 0;

   if (u) {
      if (*u < 0xc0) {
         len = 1;
      } else {
         if ((*u & 0xe0) == 0xc0) {
            // U-00000080 - U-000007FF : 110xxxxx 10xxxxxx
            len = 2;
         } else if ((*u & 0xf0) == 0xe0) {
            // U-00000800 - U-0000FFFF : 1110xxxx 10xxxxxx 10xxxxxx
            len = 3;
         } else if ((*u & 0xf8) == 0xf0) {
            // U-00010000 - U-001FFFFF : 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
            len = 4;
         } else {
            // malformed UTF-8 character
            return 0;
         }
         // Check that the UTF-8 character is OK
         int i;
         for (i = 1; i < len; i++ ) {
            if ((u[i] & 0xC0) != 0x80) {
               return 0;
            }
         }
      }
   }
   return len;
}

extern unsigned char *decimal_to_utf8(const unsigned int  d,
                                      unsigned char      *val) {
    // Works like chr() in Oracle: convert to hex, then convert hex to
    // character. Returns NULL if invalid UTF-8 character.
    char   hex[50];
    int    len;
    int    i;

    sprintf(hex, "%X", d);
    len = strlen(hex);
    if ((len > 8) || (len % 2)){
        return NULL;  // Invalid UTF-8
    } else {
       for (i = 0; i < len/2; i++) {
          val[i] = 16 * (isdigit(hex[2*i]) ? hex[2*i] - '0' : 
                                 10 + hex[2*i] - 'A')
                   + (isdigit(hex[2*i+1]) ? hex[2*i+1] - '0' : 
                                 10 + hex[2*i+1] - 'A');
       }
       val[i] = '\0';
    }
    if (isutf8(val) == 0) {
       return NULL;
    }
    return val;
}

extern unsigned int utf8_to_codepoint(const unsigned char *u,
                                      int                 *lenptr) {
   // Returns 0 if something goes wrong
   // Passes back the length
   unsigned int cp = 0;

   *lenptr = 0;
   if (u) {
      if (*u < 0xc0) {
         cp = (unsigned int)*u;
         *lenptr = 1;
      } else {
         *lenptr = isutf8(u);
         if (*lenptr == 0) {
            return 0;
         }
         switch (*lenptr) {
            case 2:
                 cp = (u[0] - 192) * 64 + u[1] - 128;
                 break;
            case 3:
                 cp = (u[0] - 224) * 4096
                    + (u[1] - 128) * 64 + u[2] - 128;
                 break;
            default:
                 cp = (u[0] - 240) * 262144
                     + (u[1] - 128) * 4096
                     + (u[2] - 128) * 64 + u[3] - 128;
                 break;
         }
      }
   }
   return cp;
}

//
//  Returns the length of s in CHARACTERS, not bytes
//
extern int utf8_charlen(unsigned char *s) {
   int len = 0;
   unsigned char *p = s;

   while (*p != '\0') {
      len++;
      // Beware that the macro increments p
      _utf8_incr(p);
   }
   return len;
}

extern int utf8_bytes_to_charpos(unsigned char *s, int pos) {
  unsigned char *p = s;
  int charcnt = 0;

  while (p < &(s[pos])) {
     _utf8_incr(p);
     charcnt++;
  }
  return charcnt;
}

extern int utf8_charpos_to_bytes(unsigned char *s, int pos) {
  int bytecnt = 0;
  int charcnt = 0;
  int len;

  while (charcnt < pos) {
     len = isutf8((const unsigned char *)&(s[bytecnt]));
     if (len == 0) {
        return -1; // Invalid UTF-8
     }
     bytecnt += len; 
     charcnt++;
  }
  return bytecnt;
}

// strchr-like function for utf8 characters. Returns NULL if
// "needle" is an invalid utf8 character.
extern unsigned char *utf8_search(const unsigned char *haystack,
                                  const unsigned char *needle) {
    unsigned char *p = (unsigned char *)NULL;

    if (haystack
        && needle
        && isutf8(needle)) {
      p = (unsigned char *)strstr((char *)haystack, (char *)needle);
    }
    return p;
} 
