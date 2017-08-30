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
	size_t          datasize; // size of data
	size_t          length;   // length of list
	lListIterator   begin;    // first lListNode of list
	lListIterator   end;      // last lListNode of list
};

struct lListNode
{
	size_t          size;  // size of data
	lList           list;  // double-linked list
	lListIterator   prev;  // previous node
	lListIterator   next;  // next node
	ptr_t           data;  // pointer to data
};
```

## APIs Index

### Macro Difinitions
* [lListForEach](#llistforeach)
* [lListCreate](#llistcreate)

### Functions
* [lListCreateBySize](#llistcreatebysize)  
* [lListDelete](#llistdelete)  
* [lListCount](#llistcount)
* [lListIsEmpty](#llistisempty)
* [lListPushBack](#llistpushback)
* [lListPushFront](#llistpushfront)
* [lListPopBack](#llistpopback)
* [lListPopFront](#llistpopfront)
* [lListIndexAt](#llistindexat)
* [lListInverseAt](#llistinverseat)
* [lListBegin](#llistbegin)
* [lListEnd](#llistend)
* [lListSetValue](#llistsetvalue)  
* [lListGetValue](#llistgetvalue)  
* [lListGetDataPointer](#llistgetdatapointer)
* [lListAfter](#llistafter)  
* [lListBefore](#llistbefore)  
* [lListInsertAfter](#llistinsertafter)  
* [lListInsertBefore](#llistinsertbefore)  
* [lListRemove](#llistremove)  
* [lListClear](#llistclear)
* [lListHead](#llisthead)
* [lListTail](#llisttail)
* [lListFindAfter](#llistfindafter)
* [lListFindBefore](#llistfindbefore)

## Demo
```C
#include <stdio.h>
#include "lList.h"

int main()
{

	/* Create list */
	lList list = lListCreate(char[10]);
	
	/* Push 10 node */
	char str[10] = "string 1";
	for(size_t i = 0; i < 10; i++)
	{
		str[7] = i | 0x30;
		lListPushBack(list,str);
	}
	
	/* Remove first 2 node (0 , 1) */
	lListPopFront(list);
	lListPopFront(list);
	
	/* Remove last 2 node (8 , 9) */
	lListPopBack(list);
	lListPopBack(list);
	
	/* Remove 6 */
	lListRemove(lListInverseAt(list,1));
	
	/* Remove 5 */
	lListRemove(lListIndexAt(list,3));
	
	/* Insert hello after 2 */
	char hello[10] = "hello";
	lListIterator p = lListInsertAfter(lListBegin(list));
	lListSetValue(p,hello);
	
	/* Traverse and print */
	lListForEach(i,list)
	{
		lListGetValue(i,str);
		printf("%s\n",str);
	}
	
	/* Length */
	printf("List length is %lu\n",lListCount(list));
	
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

### lListIsEmpty
```C
/* USE    : check list if empty 
 *
 * PARAM  : list - lList you want to check
 *
 * RETURN : true of false
 */
bool_t lListIsEmpty(lList list);
```

### lListPushBack
```C
/* USE    : Insert a lListNode after end
 *
 * PARAM  : list  - lList you want to insert
 *          value - value you want to insert
 *
 * RETURN : lListIterator to lListNode inserted or nullptr
 */
lListIterator lListPushBack(lList list, ptr_t value);
```

### lListPushFront
```C
/* USE    : Insert a lListNode before begin
 *
 * PARAM  : list  - lList you want to insert
 *          value - value you want to insert
 *
 * RETURN : lListIterator to lListNode inserted or nullptr
 */
lListIterator lListPushFront(lList list, ptr_t value);
```

### lListPopBack
```C
/* USE    : Remove end lListNode
 *
 * PARAM  : list - list you want to remove end
 *
 * RETURN : true or false
 */
bool_t lListPopBack(lList list);
```

### lListPopFront
```C
/* USE    : Remove begin lListNode
 *
 * PARAM  : list - list you want to remove end
 *
 * RETURN : true or false
 */
bool_t lListPopFront(lList list);
```

### lListIndexAt
```C
/* USE    : Get lListNode from begin
 *
 * PARAM  : list    - which list you want to get lListNode
 *          ordinal - ordinal to begin
 *
 * RETURN : lListIterator or nullptr
 */
lListIterator lListIndexAt(lList list, size_t ordinal);
```

### lListInverseAt
```C
/* USE    : Get lListNode from end
 *
 * PARAM  : list    - which list you want to get lListNode
 *          ordinal - ordinal to end
 *
 * RETURN : lListIterator or nullptr
 */
lListIterator lListInverseAt(lList list, size_t ordinal);
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

### lListGetDataPointer
```C
/*
 * USE    : Get pointer to data
 *
 * PARAM  : node - lListIterator to lListNode you want to get 
 * 
 * RETURN : pointer to data
 */
ptr_t lListGetDataPointer(lListIterator node);
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

### lListClear
```C
/* USE    : Remove all node
 *
 * PARAM  : list - lList to clear
 *
 * RETURN : void
 */
void lListClear(lList list);
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



