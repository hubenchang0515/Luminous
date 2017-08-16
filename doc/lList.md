# lList
lList is a double-linked list.

## Types
```C
typedef struct lListInfo  lListInfo;
typedef struct lListInfo* lList;
typedef struct lListNode  lListNode;
typedef struct lListNode* lListIterator;

struct lListInfo
{
	size_t 			datasize; // size of data
	size_t 			length;   // length of list
	lListIterator 	begin;    // first lListNode of list
	lListIterator 	end;      // last lListNode of list
};

struct lListNode
{
	size_t      	size;  // size of data
	lList 			list;  // double-linked list
	lListIterator 	prev;  // previous node
	lListIterator 	next;  // next node
	ptr_t       	data;  // pointer to data
};
```

## APIs Index

### Macro Difinitions
* [lListForEach](#llistforeach)
* [lListCreate](#llistcreate)

### Functions
* [lListCreateBySize](#llistcreatebysize)  
* [lListDelete](#llistdelete)  
* [lListBegin](#llistbegin)
* [lListEnd](#llistend)
* [lListSetValue](#llistsetvalue)  
* [lListGetValue](#llistgetvalue)  
* [lListAfter](#llistafter)  
* [lListBefore](#llistbefore)  
* [lListInsertAfter](#llistinsertafter)  
* [lListInsertBefore](#llistinsertbefore)  
* [lListRemove](#llistremove)  
* [lListHead](#llisthead)
* [lListTail](#llisttail)
* [lListFindAfter](#llistfindafter)
* [lListFindBefore](#llistfindbefore)
* [lListCount](#llistcount)

## Demo
```C
#include <stdio.h>
#include "lList.h"

int main()
{
	/* Create list and set value to node */
	lList list = lListCreate(char[100]);
	lListIterator node = lListBegin(list);
	printf("Data size is %lu bytes\n",node->size);
	char hello[100] = "hello world";
	lListSetValue(node,hello);
	
	/* Insert 3 node before node */
	lListIterator head = lListInsertBefore(node);
	lListInsertBefore(node);
	lListInsertBefore(node);
	lListSetValue(head,hello);
	
	/* Find "hello world" */
	lListIterator find = lListFindAfter(head,hello,1);
	printf("%p %p\n",head,find);
	
	/* Get tail node */
	lListIterator tail = lListTail(head);
	find = lListFindAfter(head,hello,2);
	printf("%p %p %p\n",node,tail,find);
	
	/* Get data */
	char str[100];
	lListGetValue(tail,str);	
	printf("Data is \"%s\"\n",str);
	
	/* Get number of nodes */
	size_t len = lListCount(list);
	printf("Number of nodes is %lu\n",len);
	tail = lListAfter(head,len-1);
	printf("%p %p\n",node,tail);
	
	/* Insert after */
	tail = lListInsertAfter(tail);
	tail = lListInsertAfter(tail);
	
	/* Remove node */
	lListRemove(node);
	len = lListCount(list);
	printf("Number of nodes is %lu\n",len);
	printf("%p %p\n",tail,lListAfter(head,len-1));
	
	/* Traverse list */
	lListForEach(i,list)
	{
		lListSetValue(i,hello);
	}
	
	lListForEach(i,list)
	{
		lListGetValue(i,str);
		printf("%s\n",str);
	}
	
	/* Delete */
	lListDelete(list);
	
	return 0;
}
```

## APIs

### lListForEach
```C
/*
 * USE    : Traverse list from start to the end
 *
 * PARAM  : iter - lListIterator used to traverse list
 *          list - lList
 */
#ifndef lListFor 
#	define lListForEach(iter,list) \
		for(lListIterator iter = list->begin; iter != nullptr; iter = iter->next)
#endif
```

### lListCreateBySize
```C
/*
 * USE    : Create linked list
 *
 * PARAM  : datasize - size of node's data
 *
 * RETURN : lList or nullptr
 */
lList lListCreateBySize(size_t datasize);
```

### lListCreate
```C
/*
 * USE    : Create linked list
 *
 * PARAM  : T - type of node's data
 *
 * RETURN : lList or nullptr
 */
#define lListCreate(T) lListCreateBySize(sizeof(T))
```

### lListDelete
```C
/*
 * USE    : Delete linked list
 *
 * PARAM  : list - lList to delete
 *
 * RETURN : void
 */
void lListDelete(lList list);
```

### lListBegin
```C
/* USE    : Begin of list
 *
 * PARAM  : list - which list you want to get begin
 *
 * RETURN : lListIterator to begin lListNode of list
 */
lListIterator lListBegin(lList list);
```

### lListEnd
```C
/* USE    : End of list
 * 
 * PARAM  : list - which list you want to get end
 *
 * RETURN : lListIterator to end lListNode of list
 */
lListIterator lListEnd(lList list);
```

### lListSetValue
```C
/*
 * USE    : Set value of node
 *
 * PARAM  : node  - lListIterator to lListNode you want to set value
 *          value - pointer to value to set
 *
 * RETURN : void
 */
void lListSetValue(lListIterator node, ptr_t value);
```

### lListGetValue
```C
/*
 * USE    : Get value of node
 *
 * PARAM  : node  - lListIterator to lListNode you want to get value
 *          value - pointer to return value
 *
 * RETURN : void
 */
void lListGetValue(lListIterator node, ptr_t value);
```

### lListAfter
```C
/*
 * USE    : Get a lListNode after node
 *
 * PARAM  : node     - after this lListNode
 *          distance - distance to node
 *
 * RETURN : lListNode we want or nullptr
 */
lListIterator lListAfter(lListIterator node, size_t distance);
```

### lListBefore
```C
/*
 * USE    : Get a lListNode before node
 *
 * PARAM  : node     - before this lListNode
 *          distance - distance to node
 *
 * RETURN : lListNode we want or nullptr
 */
lListIterator lListBefore(lListIterator node, size_t distance);
```

### lListInsertAfter
```C
/* USE    : Insert a lListNode after node 
 *
 * PARAM  : node - after this lListNode
 *
 * RETURN : lListIterator to lListNode inserted or nullptr
 */
lListIterator lListInsertAfter(lListIterator node);
```

### lListInsertBefore
```C
/* USE    : Insert a lListNode before node 
 *
 * PARAM  : node - before this lListNode
 *
 * RETURN : lListIterator to lListNode inserted or nullptr
 */
lListIterator lListInsertBefore(lListIterator node);
```

### lListRemove
```C
/* USE    : Remove node 
 *
 * PARAM  : node - lListIterator to lListNode you want to remove
 *
 * RETURN : void
 */
void lListRemove(lListIterator node);
```

### lListHead
```C
/* USE    : Head of list 
 *
 * PARAM  : node - lListIterator to any lListNode of list
 *
 * RETURN : Head lListNode of list
 */
lListIterator lListHead(lListIterator node);
```

### lListTail
```C
/* USE    : Tail of list
 *
 * PARAM  : node - lListIterator to any lListNode of list
 *
 * RETURN : Tail lListNode of list
 */
lListIterator lListTail(lListIterator node);
```

### lListFindAfter
```C
/* USE    : Find a lListNode after node
 * 
 * PARAM  : node   - after this lListNode
 *          value  - pointer to value
 *          ordinal - ordinal number 
 *
 * RETURN : number ordinal lListNode, whose data equals to value, 
 *          after node(inclusive) , or nullptr 
 */

lListIterator lListFindAfter(lListIterator node, ptr_t value, size_t ordinal);
```

### lListFindBefore
```C
/* USE    : Find a lListNode before node
 * 
 * PARAM  : node   - before this lListNode
 *          value  - pointer to value
 *          ordinal - ordinal number 
 *
 * RETURN : number ordinal lListNode, whose data equals to value, 
 *          before node(inclusive) , or nullptr 
 */
lListIterator lListFindBefore(lListIterator node, ptr_t value, size_t ordinal);
```

### lListCount
```C
/* USE    : lListNode number of list
 *
 * PARAM  : lList
 *
 * RETURN : lListNode number of list
 */
size_t lListCount(lList list);
```


