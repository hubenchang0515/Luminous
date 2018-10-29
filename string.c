/* zzz.h - String
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
#include "string.h"

/* USE    : Create String
 * 
 * PARAM  : cstr - a C style String  to init String
 *
 * RETURN : String of nullptr
 */
String stringCreate(const char_t* cstr)
{
    String string = (String)malloc(sizeof(StringInfo));
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



/* USE    : Delete String
 *
 * PARAM  : String - String to delete
 *
 * RETURN : void
 */
void stringDelete(String string)
{
    free(string->data);
    free(string);
}



/* USE    : Return length of String
 *
 * PARAM  : String - String to get length
 *
 * RETURN : length of String
 */
size_t stringLength(String string)
{
    return strlen(string->data);
}



/* USE    : Resize space of String
 *
 * PARAM  : String - String to resize
 *          size   - new size
 *
 * RETURN : true or false
 */
bool_t stringResize(String string, size_t size)
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
 * PARAM  : String - String to reduce
 *
 * RETURN : void
 */
void stringReduce(String string)
{
	string->data = (char_t*)realloc((void*)string->data, strlen(string->data) + 1);
}



/* USE    : Copy String
 *
 * PARAM  : String - String to copy
 *
 * RETURN : new String or nullptr
 */
String stringCopy(String string)
{
    return stringCreate(string->data);
}



/* USE    : Return readonly data of String
 *
 * PARAM  : String - String to get value
 *
 * RETURN : const char_t* to data
 */
const char_t* stringValue(String string)
{
    const char_t* data = string->data;
    return data;
}



/* USE    : Return pointer to data of String
 *
 * PARAM  : String - String - String to get data
 *
 * RETURN : char_t* to data
 */
char_t* stringData(String string)
{
    char_t* data = string->data;
    return data;
}



/* USE    : Set value of String
 *
 * PARAM  : String - String to set value
 *          cstr   - value
 * 
 * RETURN : true or false
 */
bool_t stringSetValue(String string, const char_t* cstr)
{
    if(stringResize(string,strlen(cstr)))
    {
        strcpy(string->data,cstr);
        return true;
    }
    else
    {
        return false;
    }
}



/* USE    : Get value of String
 *
 * PARAM  : String - String to get value
 *          cstr   - save value
 *          len    - length of cstr
 *
 * RETURN : void
 */
void stringGetValue(String String, char_t* cstr, size_t len)
{
    strncpy(cstr, String->data, len);
}



/* USE    : Remove a part of String
 *
 * PARAM  : String - String to remove
 *          site   - begin of part to remove
 *          len    - length of part
 *
 * RETURN : true or false
 */
bool_t stringRemove(String string, size_t site, size_t len)
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



/* USE    : Append String with cstr
 *
 * PARAM  : String - String append to
 *          cstr   - C style String appended
 *
 * RETURN : true or false
 */
bool_t stringAppend(String string, const char_t* cstr)
{
    if(stringResize(string, strlen(string->data) + strlen(cstr)))
    {
        strcat(string->data,cstr);
        return true;
    }
    else
    {
        return false;
    }
}



/* USE    : Insert to String
 * 
 * PARAM  : String - String to insert
 *          site   - site of String
 *          cstr   - C style String
 */
bool_t stringInsert(String string, size_t site, const char_t* cstr)
{
    if(stringResize(string, strlen(string->data) + strlen(cstr)))
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



/* USE    : Replace a part of String
 *
 * PARAM  : String - String to replace
 *          site   - site of String
 *          len    - length to remove
 *          cstr   - C style String to insert
 */
bool_t stringReplace(String string, size_t site, size_t len, const char_t* cstr)
{
    return stringRemove(string,site,len) && stringInsert(string,site,cstr);
}



/* USE    : Set String as sprintf
 *
 * PARAM  : String - String to save data
 *          fmt    - format String as sprintf in stdio.h
 *          ...    - va_arg list as sprintf in stdio.h
 *
 * RETURN : true or false
 */
bool_t stringSprintf(String string, const char* fmt,...)
{
    va_list args;
    while(1)
    {
        va_start(args,fmt);
        int bufsiz = string->space + 1;
        int len = vsnprintf(string->data, bufsiz, fmt, args);
        va_end(args);

        if(len >= 0 && len < bufsiz)
        {
            return true;
        }
        else if(len >= bufsiz  && stringResize(string,len))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
}