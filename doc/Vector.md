# Vector
Vector is an array can be changed length.

## Types
```C
typedef struct VectorInfo* Vector;

struct vectorInfo
{
    size_t size;      // size of one data
    size_t space;     // space of vector
    size_t used;      // length of used elements
    ptr_t  data;      // pointer to first data
};
```

## APIs index

### Macro Difinitions
* [VectorForEach](#vectorforeach)
* [vectorCreate](#vectorcreate)

### Functions
* [vectorCreateBySize](#vectorcreatebysize)
* [vectorDelete](#vectordelete)
* [vectorIncrease](#vectorincrease)
* [vectorReduce](#vectorreduce)
* [vectorLength](#vectorlength)
* [vectorIsEmpty](#vectorisempty)
* [vectorSpace](#vectorspace)
* [vectorResize](#vectorresize)
* [vectorPushBack](#vectorpushback)
* [vectorPopBack](#vectorpopback)
* [vectorInsert](#vectorinsert)
* [vectorRemove](#vectorremove)
* [vectorClear](#vectorclear)
* [vectorSetValue](#vectorsetvalue)
* [vectorGetValue](#vectorgetvalue)
* [vectorGetDataPointer](#vectorgetdatapointer)

## Demo
```C
#include <stdio.h>
#include "vector.h"

int main()
{
	/* Create vector */
	vector vector = vectorCreate(char[32]);
	
	/* Push 10 data to the vector */
	char str[32];	
	for(size_t i = 0; i < 10; i++)
	{
		sprintf(str,"string %lu",i);
		vectorPushBack(vector,str);
	}
	
	/* Remove 2 5 7 */
	vectorRemove(vector,7);
	vectorRemove(vector,5);
	vectorRemove(vector,2);
	
	/* Set Value of 3 */
	sprintf(str,"string 3 set");
	vectorSetValue(vector,2,str);
	
	/* Traverse */
	vectorForEach(i,vector)
	{
		printf("%s\n",(char*)i);
	}
	
	/* Length */
	printf("Space : %lu\n",vectorSpace(vector));
	printf("Used  : %lu\n",vectorLength(vector));
	
	/* Remove unused space */
	vectorReduce(vector);
	printf("Space : %lu\n",vectorSpace(vector));

	/* Delete */
	vectorDelete(vector);
	return 0;
}
```

## APIs

### VectorForEach
```C
/*
 * USE    : Traverse vector from start to the end
 * 
 * PARAM  : iter   - ptr_t to a data
 *          vector - vector
 */
#define VectorForEach(iter,vector) \
    for(ptr_t iter =  vector->data ; \
        iter < vector->data + vector->size * vector->used; \
        iter += vector->size)
```

### vectorCreateBySize
```C
/*
 * USE    : Create vector by size of data
 *
 * PARAM  : size - size of data
 *
 * RETURN : vector or nullptr
 */
vector vectorCreateBySize(size_t size);
```

### vectorCreate
```C
/*
 * USE    : Create vector by size of data
 *
 * PARAM  : T - type of data
 *
 * RETURN : vector or nullptr
 */
#define vectorCreate(T) vectorCreateBySize(sizeof(T))
```

### vectorDelete
```C
/*
 * USE    : Delete Vector
 *
 * PARAM  : vector - vector to delete
 *
 * RETURN : void
 */
void vectorDelete(vector vector);
```


### vectorIncrease
```C
/*
 * USE    : Increase length of vector
 *
 * PARAM  : vector - vector you want to increase
 *
 * RETURN : true or false
 */
bool_t vectorIncrease(vector vector);
```

### vectorReduce
```C
/*
 * USE    : Reduce space of vector to used
 *
 * PARAM  : vector - vector you want to reduce
 *
 * RETURN : void
 */
void vectorReduce(vector vector);
```

### vectorLength
```C
/*
 * USE    : Return length of vector
 *
 * PARAM  : vector - whose length you want 
 *
 * RETURN : length of vector
 */
size_t vectorLength(vector vector);
```

### vectorIsEmpty
```C
/* USE    : Check if empty
 *
 * PARAM  : vector - vector to check if empty
 *
 * RETURN : true or false
 */
bool_t vectorIsEmpty(vector vector);
```

### vectorSpace
```C
/*
 * USE    : Return space of vector
 *
 * PARAM  : vector - whose space you want
 *
 * RETURN : space of vector
 */
size_t vectorSpace(vector vector);
```

### vectorResize
```C
/* 
 * USE    : Resize the space of vector
 *
 * PARAM  : vector - vector to resize space
 *          space  - the new space
 *
 * RETURN : true or false
 */
bool_t vectorResize(vector vector, size_t space);
```

### vectorPushBack
```C
/*
 * USE    : Insert data after end
 *
 * PARAM  : vector - vector to insert
 *          value  - value to insert
 *
 * RETURN : true of false
 */
bool_t vectorPushBack(vector vector, ptr_t value);
```

### vectorPopBack
```C
/*
 * USE    : Remove the last data
 *
 * PARAM  : vector - vector to remove data
 *
 * RETURN : true or false
 */
bool_t vectorPopBack(vector vector);
```

### vectorInsert
```C
/* USE    : Insert data
 *
 * PARAM  : vector - vector to insert
 *          site   - site of data , interval [0 , vector->used]
 *          value  - value of data
 *
 * RETURN : ture or false
 */
bool_t vectorInsert(vector vector, size_t site, ptr_t value);
```

### vectorRemove
```C
/* USE    : Remove data
 *
 * PARAM  : vector - vector to remove
 *          site   - site of data , interval [0 , vector->used)
 *
 * RETURN : true or false
 */
bool_t vectorRemove(vector vector, size_t site);
```

### vectorClear
```C
/* USE    : Remove all data
 *
 * PARAM  : vector - vector to clear
 *
 * RETURN : void
 */
void vectorClear(vector vector);
```

### vectorSetValue
```C
/* USE    : Set value
 *
 * PARAM  : vector - vector to set value
 *          site   - site of data , interval [0 , vector->used)
 *          value  - value of data
 *
 * RETURN : true or false
 */
bool_t vectorSetValue(vector vector, size_t site, ptr_t value);
```

### vectorGetValue
```C
/* USE    : Get value
 *
 * PARAM  : vector - vector to get value
 *          site   - site of data , interval [0 , vector->used)
 *          value  - value of data
 *
 * RETURN : true or false
 */
bool_t vectorGetValue(vector vector, size_t site, ptr_t value);
```

### vectorGetDataPointer
```C
/* USE    : Get pointer to a data
 *
 * PARAM  : vector - vector to get
 *          site   - site of data , interval [0 , vector->used)
 *
 * RETURN : ptr_t to a data or nullptr
 */
ptr_t vectorGetDataPointer(vector vector,size_t site);
```