# Luminous
Luminous is a DATA STRUCTURE and ALGORITHMIC library of C programming language.

## Base Type and Base Macro Definitions
Base Type and Base Macro Definitions are defined in file lCore.h 
which is included by all source files in this project.
```C

/* This isn't the true code */
/* The true code supports C and C++ */

/* If you don't want to use these types , please #define LUMINOUS_NO_TYPE */
#ifndef LUMINOUS_NO_TYPE
#	include <stdint.h>                // intX_t uintX_t
#	include <stddef.h>                // size_t
	typedef int             bool_t;   // boolean
	typedef char            char_t;   // char
	typedef signed char     schar_t;  // signed char
	typedef unsigned char   uchar_t;  // unsigned char
	typedef void*           ptr_t;    // pointer
	typedef void* const     cstptr_t; // const pointer
#endif // LUMINOUS_NO_TYPE

/* If you don't want to use these macro , please #define LUMINOUS_NO_JOKE */
#ifndef LUMINOUS_NO_JOKE
#	define nullptr ((void*)0)
#	define true    1
#	define false   0
#endif // LUMINOUS_NO_JOKE
```

## Note
Every parameters , with type ptr_t , must have the same size as element of data structure at least. In some way , parameters with type ptr_t shouldn't be a literal.

## Document
**WARNING** : Following content may has mistake  , because of refactoring.  
[List](doc/List.md) : A double-linked list  
[Queue](doc/Queue.md) : A deque made by lList  
[Stack](doc/Stack.md) : A stack made by lVector  
[String](doc/String.md) : A incomplete string ``[DEPRECATED]``  
[Vector](doc/Vector.md) : A sequence list  

