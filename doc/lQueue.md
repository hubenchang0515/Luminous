# lQueue
lStack is a stack make by lVector.

## Types
```C
typedef lList lQueue;
```

## APIs index

### Macro Difinitions
* [lQueueCreate](#lqueuecreate)

### Functions
* [lQueueCreateBySize](#lqueuecreatebysize)
* [lQueueDelete](#lqueuedelete)
* [lQueueClear](#lqueueclear)
* [lQueueIsEmpty](#lqueueisempty)
* [lQueuePush](#lqueuepush)
* [lQueuePop](#lqueuepop)
* [lQueuePushBack](#lqueuepushback)
* [lQueuePopBack](#lqueuepopback)
* [lQueuePushFront](#lqueuepushfront)
* [lQueuePopFront](#lqueuepopfront)
* [lQueueGetFront](#lqueuegetfront)
* [lQueueSetFront](#lqueuesetfront)
* [lQueueGetBack](#lqueuegetback)
* [lQueueSetBack](#lqueuesetback)
* [lQueueCount](#lqueuecount)

## Demo
```C
#include <stdio.h>
#include "lQueue.h"

int main()
{
	lQueue queue = lQueueCreate(char[100]);
	
	char str[100];
	
	for(size_t i = 0; i < 10; i++)
	{
		sprintf(str,"Queue %lu",i);
		lQueuePush(queue,str);
	}
	
	printf("Count : %lu\n",lQueueCount(queue));
	
	for(size_t i = 0; i < 10; i++)
	{
		lQueuePop(queue,str);
		printf("%s\n",str);
	}
	
	printf("Count : %lu\n",lQueueCount(queue));
	
	lQueueDelete(queue);
	
	return 0;
}
```

## APIs

### lQueueCreateBySize
```C
/* USE    : Create a lQueue
 *
 * PARAM  : size - size of one data
 *
 * RETURN : new lQueue or nullptr
 */
lQueue lQueueCreateBySize(size_t size);
```

### lQueueCreate
```C
/*
 * USE    : Create lQueue 
 *
 * PARAM  : T - type of data
 *
 * RETURN : lQueue or nullptr
 */
#define lStackCreate(T) lStackCreateBySize(sizeof(T))
```

### lQueueDelete
```C
/* USE    : Delete queue
 *
 * PARAM  : queue - lQueue to delete
 *
 * RETURN : void
 */
void lQueueDelete(lQueue queue);
```

### lQueueClear
```C
/* USE    : Remove all data
 *
 * PARAM  : queue - lQeueu to clear
 *
 * RETURN : void
 */
void lQueueClear(lQueue queue);
{
    lListClear(queue);
}
```

### lQueueIsEmpty
```C
/* USE    : Check Empty
 *
 * PARAM  : queue - lQueue to check
 *
 * RETURN : true or false
 */
bool_t lQueueIsEmpty(lQueue queue);
```

### lQueuePush
```C
/* USE    : Push Back 
 *
 * PARAM  : queue - lQueue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */
bool_t lQueuePush(lQueue queue, ptr_t value);
```

### lQueuePop
```C
/* USE    : Pop front
 *
 * PARAM  : queue - lQueue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */
bool_t lQueuePop(lQueue queue, ptr_t value);
```

### lQueuePushBack
```C
/* USR    : Push Back
 *
 * PARAM  : queue - lQueue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t lQueuePushBack(lQueue queue, ptr_t value);
```

### lQueuePopBack
```C
/* USE    : Pop Back
 *
 * PARAM  : queue - lQueue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t lQueuePopBack(lQueue queue, ptr_t value);
```

### lQueuePushFront
```C
/* USE    : Push Front
 *
 * PARAM  : queue - lQueue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t lQueuePushFront(lQueue queue, ptr_t value);
```

### lQueuePopFront
```C
/* USE    : Pop Front
 *
 * PARAM  : queue - lQueue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t lQueuePopFront(lQueue queue, ptr_t value);
```

### lQueueGetFront
```C
/* USE    : Get Front but not remove it
 *
 * PARAM  : queue - lQueue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t lQueueGetFront(lQueue queue, ptr_t value);
```

### lQueueSetFront
```C
/* USE    : Set Front rather than push
 *
 * PARAM  : queue - lQueue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t lQueueSetFront(lQueue queue, ptr_t value);
```

### lQueueGetBack
```C
/* USE    : Get Back but not remove it
 *
 * PARAM  : queue - lQueue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t lQueueGetBack(lQueue queue, ptr_t value);
```

### lQueueSetBack
```C
/* USE    : Set Back rather than push
 *
 * PARAM  : queue - lQueue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t lQueueSetBack(lQueue queue, ptr_t value);
```

### lQueueCount
```C
/* USE    : Count
 *
 * PARAM  : queue - lQueue to get count
 *
 * RETURN : count of queue
 */
size_t lQueueCount(lQueue queue);
```