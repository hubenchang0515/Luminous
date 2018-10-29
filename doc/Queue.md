# Queue
Queue is a deque make by Vector.

## Types
```C
typedef List Queue;
```

## APIs index

### Macro Difinitions
* [queueCreate](#queuecreate)

### Functions
* [queueCreateBySize](#queuecreatebysize)
* [queueDelete](#queuedelete)
* [queueClear](#queueclear)
* [queueIsEmpty](#queueisempty)
* [queuePush](#queuepush)
* [queuePop](#queuepop)
* [queuePushBack](#queuepushback)
* [queuePopBack](#queuepopback)
* [queuePushFront](#queuepushfront)
* [queuePopFront](#queuepopfront)
* [queueGetFront](#queuegetfront)
* [queueSetFront](#queuesetfront)
* [queueGetBack](#queuegetback)
* [queueSetBack](#queuesetback)
* [queueCount](#queuecount)

## Demo
```C
#include <stdio.h>
#include "queue.h"

int main()
{
	queue queue = queueCreate(char[100]);
	
	char str[100];
	
	for(size_t i = 0; i < 10; i++)
	{
		sprintf(str,"Queue %lu",i);
		queuePush(queue,str);
	}
	
	printf("Count : %lu\n",queueCount(queue));
	
	for(size_t i = 0; i < 10; i++)
	{
		queuePop(queue,str);
		printf("%s\n",str);
	}
	
	printf("Count : %lu\n",queueCount(queue));
	
	queueDelete(queue);
	
	return 0;
}
```

## APIs
**WARNING** : Following content has name error  , because of refactoring

### queueCreateBySize
```C
/* USE    : Create a queue
 *
 * PARAM  : size - size of one data
 *
 * RETURN : new queue or nullptr
 */
queue queueCreateBySize(size_t size);
```

### queueCreate
```C
/*
 * USE    : Create queue 
 *
 * PARAM  : T - type of data
 *
 * RETURN : queue or nullptr
 */
#define lStackCreate(T) lStackCreateBySize(sizeof(T))
```

### queueDelete
```C
/* USE    : Delete queue
 *
 * PARAM  : queue - queue to delete
 *
 * RETURN : void
 */
void queueDelete(queue queue);
```

### queueClear
```C
/* USE    : Remove all data
 *
 * PARAM  : queue - lQeueu to clear
 *
 * RETURN : void
 */
void queueClear(queue queue);
{
    lListClear(queue);
}
```

### queueIsEmpty
```C
/* USE    : Check Empty
 *
 * PARAM  : queue - queue to check
 *
 * RETURN : true or false
 */
bool_t queueIsEmpty(queue queue);
```

### queuePush
```C
/* USE    : Push Back 
 *
 * PARAM  : queue - queue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */
bool_t queuePush(queue queue, ptr_t value);
```

### queuePop
```C
/* USE    : Pop front
 *
 * PARAM  : queue - queue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */
bool_t queuePop(queue queue, ptr_t value);
```

### queuePushBack
```C
/* USR    : Push Back
 *
 * PARAM  : queue - queue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t queuePushBack(queue queue, ptr_t value);
```

### queuePopBack
```C
/* USE    : Pop Back
 *
 * PARAM  : queue - queue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t queuePopBack(queue queue, ptr_t value);
```

### queuePushFront
```C
/* USE    : Push Front
 *
 * PARAM  : queue - queue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t queuePushFront(queue queue, ptr_t value);
```

### queuePopFront
```C
/* USE    : Pop Front
 *
 * PARAM  : queue - queue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t queuePopFront(queue queue, ptr_t value);
```

### queueGetFront
```C
/* USE    : Get Front but not remove it
 *
 * PARAM  : queue - queue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t queueGetFront(queue queue, ptr_t value);
```

### queueSetFront
```C
/* USE    : Set Front rather than push
 *
 * PARAM  : queue - queue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t queueSetFront(queue queue, ptr_t value);
```

### queueGetBack
```C
/* USE    : Get Back but not remove it
 *
 * PARAM  : queue - queue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t queueGetBack(queue queue, ptr_t value);
```

### queueSetBack
```C
/* USE    : Set Back rather than push
 *
 * PARAM  : queue - queue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t queueSetBack(queue queue, ptr_t value);
```

### queueCount
```C
/* USE    : Count
 *
 * PARAM  : queue - queue to get count
 *
 * RETURN : count of queue
 */
size_t queueCount(queue queue);
```