# lLisk
lList is a double-linked list.

## APIs Index
* [lListCreateBySize](#llistcreatebysize)  
* [lListCreate](#llistcreate)
* [lListDelete](#llistdelete)  
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
	lListNode* node = lListCreate(char[100]);
	printf("Data size is %lu bytes\n",node->size);
	char hello[100] = "hello world";
	lListSetValue(node,hello);
	
	/* Insert 3 node before node */
	lListNode* head = lListInsertBefore(node);
	lListInsertBefore(node);
	lListInsertBefore(node);
	lListSetValue(head,hello);
	
	/* Find "hello world" */
	lListNode* find = lListFindAfter(head,hello,1);
	printf("%p %p\n",head,find);
	
	/* Get tail node */
	lListNode* tail = lListTail(head);
	find = lListFindAfter(head,hello,2);
	printf("%p %p %p\n",node,tail,find);
	
	/* Get data */
	char str[100];
	lListGetValue(tail,str);	
	printf("Data is \"%s\"\n",str);
	
	/* Get number of nodes */
	size_t len = lListCount(head);
	printf("Number of nodes is %lu\n",len);
	tail = lListAfter(head,len-1);
	printf("%p %p\n",node,tail);
	
	/* Insert after */
	tail = lListInsertAfter(tail);
	tail = lListInsertAfter(tail);
	
	/* Remove node */
	lListRemove(node);
	len = lListCount(head);
	printf("Number of nodes is %lu\n",len);
	printf("%p %p\n",tail,lListAfter(head,len-1));
	
	/* Delete */
	lListDelete(head);
	
	return 0;
}
```

## APIs
### lListCreateBySize
```C
/*
 * USE    : Create linked list
 *
 * PARAM  : datasize - size of node's data
 *
 * RETURN : head lListNode of list or nullptr
 */
lListNode* lListCreateBySize(size_t datasize);
```

### lListCreate
```C
/*
 * USE    : Create linked list
 *
 * PARAM  : T - type of node's data
 *
 * RETURN : head lListNode of list or nullptr
 */
#define lListCreate(T) lListCreateBySize(sizeof(T))
```

### lListDelete
```C
/*
 * USE    : Delete linked list
 *
 * PARAM  : list - any lListNode of list
 *
 * RETURN : void
 */
void lListDelete(lListNode* list);
```

### lListSetValue
```C
/*
 * USE    : Set value of node
 *
 * PARAM  : node  - lListNode to set
 *          value - pointer to value to set
 *
 * RETURN : void
 */
void lListSetValue(lListNode* node, ptr_t value);
```

### lListGetValue
```C
/*
 * USE    : Get value of node
 *
 * PARAM  : node  - lListNode to get
 *          value - pointer to return value
 *
 * RETURN : void
 */
void lListGetValue(lListNode* node, ptr_t value);
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
lListNode* lListAfter(lListNode* node, size_t distance);
```

### lListBefore
```C
/*
 * USE    : Get a lListNode before node
 *
 * PARAM  : node     - before lListNode
 *          distance - distance to node
 *
 * RETURN : lListNode we want or nullptr
 */
lListNode* lListBefore(lListNode* node, size_t distance);
```

### lListInsertAfter
```C
/* USE    : Insert a lListNode after node 
 *
 * PARAM  : node - after this lListNode
 *
 * RETURN : lListNode inserted or nullptr
 */
lListNode* lListInsertAfter(lListNode* node);
```

### lListInsertBefore
```C
/* USE    : Insert a lListNode before node 
 *
 * PARAM  : node - before this lListNode
 *
 * RETURN : lListNode inserted or nullptr
 */
lListNode* lListInsertBefore(lListNode* node);
```

### lListRemove
```C
/* USE    : Remove node 
 *
 * PARAM  : node - lListNode to remove
 *
 * RETURN : void
 */
void lListRemove(lListNode* node);
```

### lListHead
```C
/* USE    : Head of list 
 *
 * PARAM  : node - any lListNode of list
 *
 * RETURN : Head lListNode of list
 */
lListNode* lListHead(lListNode* node);
```

### lListTail
```C
/* USE    : Tail of list
 *
 * PARAM  : node - any lListNode of list
 *
 * RETURN : Tail lListNode of list
 */
lListNode* lListTail(lListNode* node);
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

lListNode* lListFindAfter(lListNode* node, ptr_t value, size_t ordinal);
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
lListNode* lListFindBefore(lListNode* node, ptr_t value, size_t ordinal);
```

### lListCount
```C
/* USE    : lListNode number of list
 *
 * PARAM  : any lListNode of list
 *
 * RETURN : lListNode number of list
 */
size_t lListCount(lListNode* node);
```
