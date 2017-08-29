# lString
lString is a incomplete string.

## Types
```C
typedef struct lStringInfo* lString;
typedef struct lStringInfo lStringInfo;

struct lStringInfo
{
    size_t  space;     // space of String(withotr the terminating null )
    char*   data;      // pointer to first character
};
```

## APIs index

### Functions
* [lStringCreate](#lstringcreate)  
* [lStringDelete](#lstringdelete)
* [lStringLength](#lstringlength)
* [lStringResize](#lstringresize)
* [lStringReduce](#lstringreduce)
* [lStringCopy](#lstringcopy)
* [lStringValue](#lstringvalue)
* [lStringData](#lstringdata)
* [lStringSetValue](#lstringsetvalue)
* [lStringGetValue](#lstringgetvalue)
* [lStringRemove](#lstringremove)
* [lStringAppend](#lstringappend)
* [lStringInsert](#lstringinsert)
* [lStringReplace](#lstringreplace)


## Demo 
```C
#include <stdio.h>
#include "lString.h"

int main()
{
	lString str = lStringCreate("Hello World");
	lStringReplace(str,6,-1,"Luminouse");
	lStringAppend(str," String");
	printf("%s\n",lStringValue(str));
	lStringDelete(str);

	return 0;
}
```

## APIs

### lStringCreate
```C
/* USE    : Create lString
 * 
 * PARAM  : cstr - a C style string  to init lString
 *
 * RETURN : lString of nullptr
 */
lString lStringCreate(const char* cstr);
```

### lStringDelete
```C
/* USE    : Delete string
 *
 * PARAM  : string - lString to delete
 *
 * RETURN : void
 */
void lStringDelete(lString string);
```

### lStringLength
```C
/* USE    : Return length of string
 *
 * PARAM  : string - lString to get length
 *
 * RETURN : length of string
 */
size_t lStringLength(lString string);
```

### lStringResize
```C
/* USE    : Resize space of string
 *
 * PARAM  : string - lString to resize
 *          size   - new size
 *
 * RETURN : true or false
 */
bool_t lStringResize(lString string, size_t size);
```

### lStringReduce
```C
/* USE    : Resize space to length
 *
 * PARAM  : string - lString to reduce
 *
 * RETURN : void
 */
void lStringReduce(lString string);
```

### lStringCopy
```C
/* USE    : Copy string
 *
 * PARAM  : string - string to copy
 *
 * RETURN : new lString or nullptr
 */
lString lStringCopy(lString string);
```

### lStringValue
```C
/* USE    : Return readonly data of string
 *
 * PARAM  : string - lString to get value
 *
 * RETURN : const char* to data
 */
const char* lStringValue(lString string);
```

### lStringData
```C
/* USE    : Return pointer to data of string
 *
 * PARAM  : string - lString - lString to get data
 *
 * RETURN : char* to data
 */
char* lStringData(lString string);
```



### lStringSetValue
```C
/* USE    : Set value of string
 *
 * PARAM  : string - lString to set value
 *          cstr   - value
 * 
 * RETURN : true or false
 */
bool_t lStringSetValue(lString string, const char* cstr);
```

### lStringGetValue
```C
/* USE    : Get value of string
 *
 * PARAM  : string - string to get value
 *          cstr   - save value
 *          len    - length of cstr
 *
 * RETURN : void
 */
void lStringGetValue(lString string, char* cstr, size_t len);
```

### lStringRemove
```C
/* USE    : Remove a part of string
 *
 * PARAM  : string - string to remove
 *          site   - begin of part to remove
 *          len    - length of part
 *
 * RETURN : true or false
 */
bool_t lStringRemove(lString string, size_t site, size_t len);
```

### lStringAppend
```C
/* USE    : Append string with cstr
 *
 * PARAM  : string - lString append to
 *          cstr   - C style string appended
 *
 * RETURN : true or false
 */
bool_t lStringAppend(lString string, const char* cstr);
```

### lStringInsert
```C
/* USE    : Insert to string
 * 
 * PARAM  : string - lString to insert
 *          site   - site to insert
 *          cstr   - C style string
 */
bool_t lStringInsert(lString string, size_t site, const char* cstr);
```

### lStringReplace
```C
/* USE    : Replace a part of string
 *
 * PARAM  : string - lString to replace
 *          site   - site of string
 *          len    - length to remove
 *          cstr   - C style string to insert
 */
bool_t lStringReplace(lString string, size_t site, size_t len, const char* cstr);
```