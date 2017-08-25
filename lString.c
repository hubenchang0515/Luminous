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
#include "lString.h"

/* USE    : Create lString
 * 
 * PARAM  : cstr - a C style string  to init lString
 *
 * RETURN : lString of nullptr
 */
lString lStringCreate(const char* cstr)
{
    lString string = (lString)malloc(sizeof(lStringInfo));
    if(string != nullptr)
    {
        string->space  = strlen(cstr);  
        string->data   = (char*)malloc(string->space + 1);// also  end of 0

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
    char* p = realloc(string->data,size + 1);
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
    string->data = realloc(string->data, strlen(string->data) + 1);
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
 * RETURN : const char* to data
 */
const char* lStringValue(lString string)
{
    const char* data = string->data;
    return data;
}



/* USE    : Return pointer to data of string
 *
 * PARAM  : string - lString - lString to get data
 *
 * RETURN : char* to data
 */
char* lStringData(lString string)
{
    char* data = string->data;
    return data;
}



/* USE    : Set value of string
 *
 * PARAM  : string - lString to set value
 *          cstr   - value
 * 
 * RETURN : true or false
 */
bool_t lStringSetValue(lString string, const char* cstr)
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
void lStringGetValue(lString string, char* cstr, size_t len)
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
bool_t lStringAppend(lString string, const char* cstr)
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
bool_t lStringInsert(lString string, size_t site, const char* cstr)
{
    if(lStringResize(string, strlen(string->data) + strlen(cstr)))
    {
        size_t len = strlen(cstr);
        char* src  = string->data + site;
        char* dest = src + len;
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
bool_t lStringReplace(lString string, size_t site, size_t len, const char* cstr)
{
    return lStringRemove(string,site,len) && lStringInsert(string,site,cstr);
}