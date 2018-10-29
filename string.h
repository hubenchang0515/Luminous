/* String.h - String
** https://github.com/hubenchang0515/Luminous
**
** Copyright (C) 2017 hubenchang0515
** Date    : 2017-8-23
** E-mail  : hubenchang0515@outlook.com
** Blog    : blog.kurukurumi.com
** LISENCE : LGPL v3.0
*/

#ifndef LUMINOUS_STRING_H
#define LUMINOUS_STRING_H

#include "core.h"

#ifdef __cplusplus 
	extern "C" {
#endif

typedef struct StringInfo* String;
typedef struct StringInfo StringInfo;

struct StringInfo
{
    size_t space;     // space of String
    char*  data;      // pointer to first character
};

/* Create String */
String stringCreate(const char* cstr);

/* Delete String */
void stringDelete(String string);

/* Length of String */
size_t stringLength(String string);

/* Resize space of String */
bool_t stringResize(String string, size_t size);

/* Reduce space of String */
void stringReduce(String string);

/* Copy a String */
String stringCopy(String string);

/* Return C style String of String */
const char* stringValue(String string);

/* Return data pointer of String */
char* stringData(String string);

/* Set Value */
bool_t stringSetValue(String string, const char* cstr);

/* Get value */
void stringGetValue(String string, char* cstr, size_t len);

/* Remove some data */
bool_t stringRemove(String string, size_t site, size_t len);

/* Append C style String */
bool_t stringAppend(String string, const char* cstr);

/* Insert C style String */
bool_t stringInsert(String string, size_t site, const char* cstr);

/* Repalce by C style String */
bool_t stringReplace(String string, size_t site, size_t len, const char* cstr);

/* Append String */
bool_t stringAppendL(String string, String lstr);

/* Insert String */
bool_t stringInsertL(String string, String lstr);

/* Repalce by String */
bool_t stringReplaceL(String string, size_t site, size_t len, String lstr);

/* Set String as sprintf */
bool_t stringSprintf(String string, const char* fmt,...);

#ifdef __cplusplus
    }
#endif

#endif // LUMINOUS_STRING_H