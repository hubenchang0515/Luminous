# lVector
lVector is an array can be changed length.

## Types
```C
typedef struct lVectorInfo* lVector;

struct lVectorInfo
{
    size_t size;      // size of one data
    size_t space;     // space of vector
    size_t used;      // length of used elements
    ptr_t  data;      // pointer to first data
};
```

## APIs index

### Macro Difinitions
* [lVectorForEach](#lvectorforeach)
* [lVectorCreate](#lvectorcreate)

### Functions
* [lVectorCreateBySize](#lvectorcreatebysize)
* [lVectorDelete](#lvectordelete)
* [lVectorIncrease](#lvectorincrease)
* [lVectorReduce](#lvectorreduce)
* [lVectorLength](#lvectorlength)
* [lVectorIsEmpty](#lvectorisempty)
* [lVectorSpace](#lvectorspace)
* [lVectorResize](#lvectorresize)
* [lVectorPushBack](#lvectorpushback)
* [lVectorPopBack](#lvectorpopback)
* [lVectorInsert](#lvectorinsert)
* [lVectorRemove](#lvectorremove)
* [lVectorClear](#lvectorclear)
* [lVectorSetValue](#lvectorsetvalue)
* [lVectorGetValue](#lvectorgetvalue)
* [lVectorGetDataPointer](#lvectorgetdatapointer)

## Demo
```C
#include <stdio.h>
#include "lVector.h"

int main()
{
	/* Create lVector */
	lVector vector = lVectorCreate(char[32]);
	
	/* Push 10 data to the vector */
	char str[32];	
	for(size_t i = 0; i < 10; i++)
	{
		sprintf(str,"string %lu",i);
		lVectorPushBack(vector,str);
	}
	
	/* Remove 2 5 7 */
	lVectorRemove(vector,7);
	lVectorRemove(vector,5);
	lVectorRemove(vector,2);
	
	/* Set Value of 3 */
	sprintf(str,"string 3 set");
	lVectorSetValue(vector,2,str);
	
	/* Traverse */
	lVectorForEach(i,vector)
	{
		printf("%s\n",(char*)i);
	}
	
	/* Length */
	printf("Space : %lu\n",lVectorSpace(vector));
	printf("Used  : %lu\n",lVectorLength(vector));
	
	/* Remove unused space */
	lVectorReduce(vector);
	printf("Space : %lu\n",lVectorSpace(vector));

	/* Delete */
	lVectorDelete(vector);
	return 0;
}
```

## APIs

### lVectorForEach
```C
/*
 * USE    : Traverse vector from start to the end
 * 
 * PARAM  : iter   - ptr_t to a data
 *          vector - lVector
 */
#define lVectorForEach(iter,vector) \
    for(ptr_t iter =  vector->data ; \
        iter < vector->data + vector->size * vector->used; \
        iter += vector->size)
```

### lVectorCreateBySize
```C
/*
 * USE    : Create lVector by size of data
 *
 * PARAM  : size - size of data
 *
 * RETURN : lVector or nullptr
 */
lVector lVectorCreateBySize(size_t size);
```

### lVectorCreate
```C
/*
 * USE    : Create lVector by size of data
 *
 * PARAM  : T - type of data
 *
 * RETURN : lVector or nullptr
 */
#define lVectorCreate(T) lVectorCreateBySize(sizeof(T))
```

### lVectorDelete
```C
/*
 * USE    : Delete Vector
 *
 * PARAM  : vector - lVector to delete
 *
 * RETURN : void
 */
void lVectorDelete(lVector vector);
```


### lVectorIncrease
```C
/*
 * USE    : Increase length of vector
 *
 * PARAM  : vector - lVector you want to increase
 *
 * RETURN : true or false
 */
bool_t lVectorIncrease(lVector vector);
```

### lVectorReduce
```C
/*
 * USE    : Reduce space of vector to used
 *
 * PARAM  : vector - lVector you want to reduce
 *
 * RETURN : void
 */
void lVectorReduce(lVector vector);
```

### lVectorLength
```C
/*
 * USE    : Return length of vector
 *
 * PARAM  : vector - whose length you want 
 *
 * RETURN : length of vector
 */
size_t lVectorLength(lVector vector);
```

### lVectorIsEmpty
```C
/* USE    : Check if empty
 *
 * PARAM  : vector - lVector to check if empty
 *
 * RETURN : true or false
 */
bool_t lVectorIsEmpty(lVector vector);
```

### lVectorSpace
```C
/*
 * USE    : Return space of vector
 *
 * PARAM  : vector - whose space you want
 *
 * RETURN : space of vector
 */
size_t lVectorSpace(lVector vector);
```

### lVectorResize
```C
/* 
 * USE    : Resize the space of vector
 *
 * PARAM  : vector - lVector to resize space
 *          space  - the new space
 *
 * RETURN : true or false
 */
bool_t lVectorResize(lVector vector, size_t space);
```

### lVectorPushBack
```C
/*
 * USE    : Insert data after end
 *
 * PARAM  : vector - lVector to insert
 *          value  - value to insert
 *
 * RETURN : true of false
 */
bool_t lVectorPushBack(lVector vector, ptr_t value);
```

### lVectorPopBack
```C
/*
 * USE    : Remove the last data
 *
 * PARAM  : vector - lVector to remove data
 *
 * RETURN : true or false
 */
bool_t lVectorPopBack(lVector vector);
```

### lVectorInsert
```C
/* USE    : Insert data
 *
 * PARAM  : vector - lVector to insert
 *          site   - site of data , interval [0 , vector->used]
 *          value  - value of data
 *
 * RETURN : ture or false
 */
bool_t lVectorInsert(lVector vector, size_t site, ptr_t value);
```

### lVectorRemove
```C
/* USE    : Remove data
 *
 * PARAM  : vector - lVector to remove
 *          site   - site of data , interval [0 , vector->used)
 *
 * RETURN : true or false
 */
bool_t lVectorRemove(lVector vector, size_t site);
```

### lVectorClear
```C
/* USE    : Remove all data
 *
 * PARAM  : vector - lVector to clear
 *
 * RETURN : void
 */
void lVectorClear(lVector vector);
```

### lVectorSetValue
```C
/* USE    : Set value
 *
 * PARAM  : vector - lVector to set value
 *          site   - site of data , interval [0 , vector->used)
 *          value  - value of data
 *
 * RETURN : true or false
 */
bool_t lVectorSetValue(lVector vector, size_t site, ptr_t value);
```

### lVectorGetValue
```C
/* USE    : Get value
 *
 * PARAM  : vector - lVector to get value
 *          site   - site of data , interval [0 , vector->used)
 *          value  - value of data
 *
 * RETURN : true or false
 */
bool_t lVectorGetValue(lVector vector, size_t site, ptr_t value);
```

### lVectorGetDataPointer
```C
/* USE    : Get pointer to a data
 *
 * PARAM  : vector - lVector to get
 *          site   - site of data , interval [0 , vector->used)
 *
 * RETURN : ptr_t to a data or nullptr
 */
ptr_t lVectorGetDataPointer(lVector vector,size_t site);
```