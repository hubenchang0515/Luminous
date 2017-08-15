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
#   ifndef __cplusplus
#		include <stdint.h>
#		include <stddef.h>
    	typedef signed char 	char_t;   // signed char
    	typedef unsigned char 	uchar_t;  // unsigned char
        typedef int 			bool_t;   // boolean
        typedef void*			ptr_t;    // pointer
        typedef void* const 	cstptr_t; // const pointer
#   else
#		include <stdint.h>
#		include <cstddef>
        typedef bool            bool_t;   // boolean
#       include "lPointer.hpp"  // in C++
#   endif // __cplusplus
#endif // LUMINOUS_NO_TYPE

/* Some macro definitions */
/* If you don't want to use these macro , please #define LUMINOUS_NO_JOKE */
#ifndef LUMINOUS_NO_JOKE
/* nullptr */
#   ifndef nullptr
#	    ifndef __cplusplus // nullptr in C 
#           define nullptr ( (void*) 0 )
#       elif __cplusplus < 201103L // nullptr before C++11
            cstptr_t lnullptr((void*)0);
#			define nullptr lnullptr
#       endif // __ cplusplus
#   endif // nullptr
/* true and false */
#	if !defined(__cplusplus) && !defined(true) && !defined(false) 
#		define true  1
#		define false 0
#	endif
#endif // LUMINOUS_NO_JOKE

#endif // LUMINOUS_CORE_H
