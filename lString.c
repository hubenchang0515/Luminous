/* lString.h - string
** https://github.com/hubenchang0515/Luminous
**
** Copyright (C) 2017 hubenchang0515
** Date    : 2017-8-23
** E-mail  : hubenchang0515@outlook.com
** Blog    : blog.kurukurumi.com
** LISENCE : LGPL v3.0
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include "lString.h"

/* USE    : Create lString
 * 
 * PARAM  : cstr - a C style string  to init lString
 *
 * RETURN : lString of nullptr
 */
lString lStringCreate(const char_t* cstr)
{
    lString string = (lString)malloc(sizeof(lStringInfo));
    if(string != nullptr)
    {
        string->space  = strlen(cstr);  
        string->data   = (char_t*)malloc(string->space + 1);// also  end of 0

        if(string->data == nullptr)
        {
            free(string);
            string = nullptr;
        }
        else
        {
            strcpy(string->data,cstr);
        }
    }

    return string;
}



/* USE    : Delete string
 *
 * PARAM  : string - lString to delete
 *
 * RETURN : void
 */
void lStringDelete(lString string)
{
    free(string->data);
    free(string);
}



/* USE    : Return length of string
 *
 * PARAM  : string - lString to get length
 *
 * RETURN : length of string
 */
size_t lStringLength(lString string)
{
    return strlen(string->data);
}



/* USE    : Resize space of string
 *
 * PARAM  : string - lString to resize
 *          size   - new size
 *
 * RETURN : true or false
 */
bool_t lStringResize(lString string, size_t size)
{
    char_t* p = (char_t*)realloc((void*)string->data,size + 1);
    if(p != nullptr)
    {
        string->space = size;
        string->data = p;
        return true;
    }
    else
    {
        return false;
    }
}



/* USE    : Resize space to length
 *
 * PARAM  : string - lString to reduce
 *
 * RETURN : void
 */
void lStringReduce(lString string)
{
    string->data = (char_t*)realloc((void*)string->data, strlen(string->data) + 1);
}



/* USE    : Copy string
 *
 * PARAM  : string - lString to copy
 *
 * RETURN : new lString or nullptr
 */
lString lStringCopy(lString string)
{
    return lStringCreate(string->data);
}



/* USE    : Return readonly data of string
 *
 * PARAM  : string - lString to get value
 *
 * RETURN : const char_t* to data
 */
const char_t* lStringValue(lString string)
{
    const char_t* data = string->data;
    return data;
}



/* USE    : Return pointer to data of string
 *
 * PARAM  : string - lString - lString to get data
 *
 * RETURN : char_t* to data
 */
char_t* lStringData(lString string)
{
    char_t* data = string->data;
    return data;
}



/* USE    : Set value of string
 *
 * PARAM  : string - lString to set value
 *          cstr   - value
 * 
 * RETURN : true or false
 */
bool_t lStringSetValue(lString string, const char_t* cstr)
{
    if(lStringResize(string,strlen(cstr)))
    {
        strcpy(string->data,cstr);
        return true;
    }
    else
    {
        return false;
    }
}



/* USE    : Get value of string
 *
 * PARAM  : string - string to get value
 *          cstr   - save value
 *          len    - length of cstr
 *
 * RETURN : void
 */
void lStringGetValue(lString string, char_t* cstr, size_t len)
{
    strncpy(cstr, string->data, len);
}



/* USE    : Remove a part of string
 *
 * PARAM  : string - string to remove
 *          site   - begin of part to remove
 *          len    - length of part
 *
 * RETURN : true or false
 */
bool_t lStringRemove(lString string, size_t site, size_t len)
{
    size_t length = strlen(string->data);
    if(site <= length && len <= length - site)
    {
        strcpy(string->data + site, string->data + site + len);
        return true;
    }
    else if(site <= length && len > length - site)
    {
        *(string->data + site) = 0;
        return true;
    }
    else
    {
        return false;
    }
}



/* USE    : Append string with cstr
 *
 * PARAM  : string - lString append to
 *          cstr   - C style string appended
 *
 * RETURN : true or false
 */
bool_t lStringAppend(lString string, const char_t* cstr)
{
    if(lStringResize(string, strlen(string->data) + strlen(cstr)))
    {
        strcat(string->data,cstr);
        return true;
    }
    else
    {
        return false;
    }
}



/* USE    : Insert to string
 * 
 * PARAM  : string - lString to insert
 *          site   - site of string
 *          cstr   - C style string
 */
bool_t lStringInsert(lString string, size_t site, const char_t* cstr)
{
    if(lStringResize(string, strlen(string->data) + strlen(cstr)))
    {
        size_t len = strlen(cstr);
        char_t* src  = string->data + site;
        char_t* dest = src + len;
        memmove(dest,src,len);
        memcpy(src,cstr,len);
        return true;
    }
    else
    {
        return false;
    }
}



/* USE    : Replace a part of string
 *
 * PARAM  : string - lString to replace
 *          site   - site of string
 *          len    - length to remove
 *          cstr   - C style string to insert
 */
bool_t lStringReplace(lString string, size_t site, size_t len, const char_t* cstr)
{
    return lStringRemove(string,site,len) && lStringInsert(string,site,cstr);
}



/* USE    : Set lString as sprintf
 *
 * PARAM  : string - lString to save data
 *          fmt    - format string as sprintf in stdio.h
 *          ...    - va_arg list as sprintf in stdio.h
 *
 * RETURN : true or false
 */
bool_t lStringSprintf(lString string, const char* fmt,...)
{
#ifndef LSPRINTF_ORIGINAL_SPACE
#define LSPRINTF_ORIGINAL_SPACE 256
    char*   buf  = (char*)malloc(LSPRINTF_ORIGINAL_SPACE);
    int  size = LSPRINTF_ORIGINAL_SPACE; 

    va_list args;
    va_start(args,fmt);

    int len = 0;
    while(1)
    {
        len = vsnprintf(buf,size,fmt,args);
        
        if(len < 0) // failed
        {
            va_end(args);
            free(buf);
            return false;
        }
        else if(len >= size) // memory is not enough
        {
            char* p = realloc(buf,len + 1);
            if(p == nullptr)
            {
                va_end(args);
                free(buf);
                return false;
            }

            buf = p;
            size = len + 1;
            va_end(args);
            va_start(args,fmt);
            continue;
        }
        else // success
        {
            lStringSetValue(string,buf);
            va_end(args);
            free(buf);
            return true;
        }
    }

#undef LSPRINTF_ORIGINAL_SPACE
#endif
}