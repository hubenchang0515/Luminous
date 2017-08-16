# Luminous
Luminous is a DATA STRUCTURE and ALGORITHMIC library of C programming language.

## Base Types and Base Macro Definitions
Base Types and Base Macro Definitions are defined in file lCore.h
```C

/* This isn't the true code */

/* If you don't want to use these types , please #define LUMINOUS_NO_TYPE */
#ifndef LUMINOUS_NO_TYPE
#   include <stdint.h>            // intX_t uintX_t
#   include <stddef.h>            // size_t
typedef int             bool_t;   // boolean
typedef signed char     char_t;   // signed char
typedef unsigned char   uchar_t;  // unsigned char
typedef void*           ptr_t;    // pointer
typedef void* const     cstptr_t; // const pointer
typedef const void*     ptrcst_t; // pointer to const
#endif // LUMINOUS_NO_TYPE

/* Some macro definitions */
/* If you don't want to use these macro , please #define LUMINOUS_NO_JOKE */
#ifndef LUMINOUS_NO_JOKE
#define nullptr ((void*)0)
#define true    1
#define false   0
#endif // LUMINOUS_NO_JOKE
```


## DOC
[lList : A double-linked list](doc/lList.md)
