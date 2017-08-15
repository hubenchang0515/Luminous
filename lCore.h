/* lCore.h - Base types and macro definitions
** https://github.com/hubenchang0515/Luminous
**
** Copyright (C) 2017 hubenchang0515
** Date    : 2017-8-7
** E-mail  : hubenchang0515@outlook.com
** Blog    : blog.kurukurumi.com
** LISENCE : LGPL v3.0
*/

#ifndef LUMINOUS_CORE_H
#define LUMINOUS_CORE_H

/* Base Types , use stdint.h and srddef.h */
/* If you don't want to use these types , please #define LUMINOUS_NO_TYPE */
#ifndef LUMINOUS_NO_TYPE
#	include <stdint.h>
#	include <stddef.h>
typedef int 			bool_t;   // boolean
typedef signed char 	char_t;   // signed char
typedef unsigned char 	uchar_t;  // unsigned char
typedef void*			ptr_t;    // pointer
typedef void* const 	cstptr_t; // const pointer
typedef const void* 	ptrcst_t; // pointer to const
#endif // LUMINOUS_NO_TYPE

/* Some macro definitions */
/* If you don't want to use these macro , please #define LUMINOUS_NO_JOCK */
#ifndef LUMINOUS_NO_JOCK
/* nullptr */
#	if ( !defined(__cplusplus) || __cplusplus < 201103L ) && !defined(nullptr)
#		define nullptr ( (void*) 0 )
#	endif
/* true and false */
#	if !defined(__cplusplus) && !defined(true) && !defined(false) 
#		define true  1
#		define false 0
#	endif
#endif // LUMINOUS_NO_JOCK

#endif // LUMINOUS_CORE_H
