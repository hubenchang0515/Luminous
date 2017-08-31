/* lString.h - string
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

#include "lCore.h"

#ifdef __cplusplus 
	extern "C" {
#endif

typedef struct lStringInfo* lString;
typedef struct lStringInfo lStringInfo;

struct lStringInfo
{
    size_t space;     // space of String
    char*  data;      // pointer to first character
};

/* Create lString */
lString lStringCreate(const char* cstr);

/* Delete lString */
void lStringDelete(lString string);

/* Length of string */
size_t lStringLength(lString string);

/* Resize space of lString */
bool_t lStringResize(lString string, size_t size);

/* Reduce space of lString */
void lStringReduce(lString string);

/* Copy a lString */
lString lStringCopy(lString string);

/* Return C style string of lString */
const char* lStringValue(lString string);

/* Return data pointer of lString */
char* lStringData(lString string);

/* Set Value */
bool_t lStringSetValue(lString string, const char* cstr);

/* Get value */
void lStringGetValue(lString string, char* cstr, size_t len);

/* Remove some data */
bool_t lStringRemove(lString string, size_t site, size_t len);

/* Append C style string */
bool_t lStringAppend(lString string, const char* cstr);

/* Insert C style string */
bool_t lStringInsert(lString string, size_t site, const char* cstr);

/* Repalce by C style string */
bool_t lStringReplace(lString string, size_t site, size_t len, const char* cstr);

/* Append lString */
bool_t lStringAppendL(lString string, lString lstr);

/* Insert lString */
bool_t lStringInsertL(lString string, lString lstr);

/* Repalce by lString */
bool_t lStringReplaceL(lString string, size_t site, size_t len, lString lstr);

/* Set lString as sprintf */
bool_t lStringSprintf(lString string, const char* fmt,...);

#ifdef __cplusplus
    }
#endif

#endif // LUMINOUS_STRING_H