#ifndef _DEFS_H_
#define _DEFS_H_

#include <stdbool.h>
#include <stdio.h>

#define _In_
#define _Out_
#define _In_Out_

#define ERR_OK                  0
#define ERR_INVALID_ARG        -2   // Invalid Argument Error
#define ERR_NO_IMPLENENTATION  -3   // No implementation Error
#define ERR_SEND               -4   // Send error
#define ERR_CONN_FAIL          -5   // Faile connection Error
#define ERR_CONN_PROB          -5   // Connection problem Error


#define  False false
#define  True  true

typedef unsigned char       UInt8;
typedef signed   char       Int8;
typedef unsigned short      UInt16;
typedef signed   short      Int16;
typedef unsigned int        UInt32;
typedef signed   int        Int32;
typedef unsigned long int   UInt64;
typedef signed long int     Int64;

typedef void                Void;
typedef float               Float;
typedef char                Char;
typedef bool                Bool;


#endif // _DEFS_H_