# String
String is a incomplete string.

## Types
```C
typedef struct StringInfo* String;
typedef struct StringInfo StringInfo;

struct StringInfo
{
    size_t  space;     // space of String(withotr the terminating null )
    char*   data;      // pointer to first character
};
```

## APIs index

### Functions
* [stringCreate](#stringcreate)  
* [stringDelete](#stringdelete)
* [stringLength](#stringlength)
* [stringResize](#stringresize)
* [stringReduce](#stringreduce)
* [stringCopy](#stringcopy)
* [stringValue](#stringvalue)
* [stringData](#stringdata)
* [stringSetValue](#stringsetvalue)
* [stringGetValue](#stringgetvalue)
* [stringRemove](#stringremove)
* [stringAppend](#stringappend)
* [stringInsert](#stringinsert)
* [stringReplace](#stringreplace)
* [stringSprintf](#stringsprintf)


## Demo 
```C
#include <stdio.h>
#include "string.h"

int main()
{
	String str = stringCreate("");
	stringSprintf(str,"pi = %.2lf",3.14);
	stringAppend(str,"15926");
	stringReplace(str,0,2,"Circumference Ratio");
	printf("%s\n",stringValue(str));
	
	stringDelete(str);
	return 0;
}
```

## APIs
**WARNING** : Following content has name error  , because of refactoring

### stringCreate
```C
/* USE    : Create string
 * 
 * PARAM  : cstr - a C style string  to init string
 *
 * RETURN : string of nullptr
 */
string stringCreate(const char* cstr);
```

### stringDelete
```C
/* USE    : Delete string
 *
 * PARAM  : string - string to delete
 *
 * RETURN : void
 */
void stringDelete(string string);
```

### stringLength
```C
/* USE    : Return length of string
 *
 * PARAM  : string - string to get length
 *
 * RETURN : length of string
 */
size_t stringLength(string string);
```

### stringResize
```C
/* USE    : Resize space of string
 *
 * PARAM  : string - string to resize
 *          size   - new size
 *
 * RETURN : true or false
 */
bool_t stringResize(string string, size_t size);
```

### stringReduce
```C
/* USE    : Resize space to length
 *
 * PARAM  : string - string to reduce
 *
 * RETURN : void
 */
void stringReduce(string string);
```

### stringCopy
```C
/* USE    : Copy string
 *
 * PARAM  : string - string to copy
 *
 * RETURN : new string or nullptr
 */
string stringCopy(string string);
```

### stringValue
```C
/* USE    : Return readonly data of string
 *
 * PARAM  : string - string to get value
 *
 * RETURN : const char* to data
 */
const char* stringValue(string string);
```

### stringData
```C
/* USE    : Return pointer to data of string
 *
 * PARAM  : string - string - string to get data
 *
 * RETURN : char* to data
 */
char* stringData(string string);
```



### stringSetValue
```C
/* USE    : Set value of string
 *
 * PARAM  : string - string to set value
 *          cstr   - value
 * 
 * RETURN : true or false
 */
bool_t stringSetValue(string string, const char* cstr);
```

### stringGetValue
```C
/* USE    : Get value of string
 *
 * PARAM  : string - string to get value
 *          cstr   - save value
 *          len    - length of cstr
 *
 * RETURN : void
 */
void stringGetValue(string string, char* cstr, size_t len);
```

### stringRemove
```C
/* USE    : Remove a part of string
 *
 * PARAM  : string - string to remove
 *          site   - begin of part to remove
 *          len    - length of part
 *
 * RETURN : true or false
 */
bool_t stringRemove(string string, size_t site, size_t len);
```

### stringAppend
```C
/* USE    : Append string with cstr
 *
 * PARAM  : string - string append to
 *          cstr   - C style string appended
 *
 * RETURN : true or false
 */
bool_t stringAppend(string string, const char* cstr);
```

### stringInsert
```C
/* USE    : Insert to string
 * 
 * PARAM  : string - string to insert
 *          site   - site to insert
 *          cstr   - C style string
 */
bool_t stringInsert(string string, size_t site, const char* cstr);
```

### stringReplace
```C
/* USE    : Replace a part of string
 *
 * PARAM  : string - string to replace
 *          site   - site of string
 *          len    - length to remove
 *          cstr   - C style string to insert
 */
bool_t stringReplace(string string, size_t site, size_t len, const char* cstr);
```

### stringSprintf
```C
/* USE    : Set string as sprintf
 *
 * PARAM  : string - string to save data
 *          fmt    - format string as sprintf in stdio.h
 *          ...    - va_arg list as sprintf in stdio.h
 *
 * RETURN : true or false
 */
bool_t stringSprintf(string string, const char* fmt,...);
```