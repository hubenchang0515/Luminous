# List
List is a double-linked list. 

## Types
```C
/* Double-linked List and Node */
typedef struct ListInfo  ListInfo;
typedef struct ListInfo* List;
typedef struct ListNode  ListNode;
typedef struct ListNode* ListIterator;

struct ListInfo
{
	size_t 			datasize; // size of data
	size_t 			length;   // length of list
	ListIterator 	begin;    // first ListNode of list
	ListIterator 	end;      // last ListNode of list
};

struct ListNode
{
	size_t      	size;  // size of data
	List 			list;  // double-linked list
	ListIterator 	prev;  // previous node
	ListIterator 	next;  // next node
	ptr_t       	data;  // pointer to data
};
```

## APIs Index

### Macro Difinitions
* [ListForEach](#listforeach)
* [listCreate](#listcreate)

### Functions
* [listCreateBySize](#listcreatebysize)  
* [listDelete](#listdelete)  
* [listCount](#listcount)
* [listIsEmpty](#listisempty)
* [listPushBack](#listpushback)
* [listPushFront](#listpushfront)
* [listPopBack](#listpopback)
* [listPopFront](#listpopfront)
* [listIndexAt](#listindexat)
* [listInverseAt](#listinverseat)
* [listBegin](#listbegin)
* [listEnd](#listend)
* [listSetValue](#listsetvalue)  
* [listGetValue](#listgetvalue)  
* [listGetDataPointer](#listgetdatapointer)
* [listAfter](#listafter)  
* [listBefore](#listbefore)  
* [listInsertAfter](#listinsertafter)  
* [listInsertBefore](#listinsertbefore)  
* [listRemove](#listremove)  
* [listClear](#listclear)
* [listHead](#listhead)
* [listTail](#listtail)
* [listFindAfter](#listfindafter)
* [listFindBefore](#listfindbefore)

## Demo
```C
#include <stdio.h>
#include "list.h"

int main()
{

	/* Create list */
	list list = listCreate(char[10]);
	
	/* Push 10 node */
	char str[10] = "string 1";
	for(size_t i = 0; i < 10; i++)
	{
		str[7] = i | 0x30;
		listPushBack(list,str);
	}
	
	/* Remove first 2 node (0 , 1) */
	listPopFront(list);
	listPopFront(list);
	
	/* Remove last 2 node (8 , 9) */
	listPopBack(list);
	listPopBack(list);
	
	/* Remove 6 */
	listRemove(listInverseAt(list,1));
	
	/* Remove 5 */
	listRemove(listIndexAt(list,3));
	
	/* Insert hello after 2 */
	char hello[10] = "hello";
	listIterator p = listInsertAfter(listBegin(list));
	listSetValue(p,hello);
	
	/* Traverse and print */
	listForEach(i,list)
	{
		listGetValue(i,str);
		printf("%s\n",str);
	}
	
	/* Length */
	printf("List length is %lu\n",listCount(list));
	
	/* Delete */
	listDelete(list);
	
	return 0;
}
```

## APIs
**WARNING** : Following content has name error  , because of refactoring

### ListForEach
```C
/*
 * USE    : Traverse list from start to the end
 *
 * PARAM  : iter - listIterator used to traverse list
 *          list - list
 */
#ifndef ListForEach 
#	define ListForEach(iter,list) \
		for(ListIterator iter = list->begin; iter != nullptr; iter = iter->next)
#endif
```

### listCreateBySize
```C
/*
 * USE    : Create linked list
 *
 * PARAM  : datasize - size of node's data
 *
 * RETURN : list or nullptr
 */
list listCreateBySize(size_t datasize);
```

### listCreate
```C
/*
 * USE    : Create linked list
 *
 * PARAM  : T - type of node's data
 *
 * RETURN : list or nullptr
 */
#define listCreate(T) listCreateBySize(sizeof(T))
```

### listDelete
```C
/*
 * USE    : Delete linked list
 *
 * PARAM  : list - list to delete
 *
 * RETURN : void
 */
void listDelete(list list);
```

### listCount
```C
/* USE    : listNode number of list
 *
 * PARAM  : list
 *
 * RETURN : listNode number of list
 */
size_t listCount(list list);
```

### listIsEmpty
```C
/* USE    : check list if empty 
 *
 * PARAM  : list - list you want to check
 *
 * RETURN : true of false
 */
bool_t listIsEmpty(list list);
```

### listPushBack
```C
/* USE    : Insert a listNode after end
 *
 * PARAM  : list  - list you want to insert
 *          value - value you want to insert
 *
 * RETURN : listIterator to listNode inserted or nullptr
 */
listIterator listPushBack(list list, ptr_t value);
```

### listPushFront
```C
/* USE    : Insert a listNode before begin
 *
 * PARAM  : list  - list you want to insert
 *          value - value you want to insert
 *
 * RETURN : listIterator to listNode inserted or nullptr
 */
listIterator listPushFront(list list, ptr_t value);
```

### listPopBack
```C
/* USE    : Remove end listNode
 *
 * PARAM  : list - list you want to remove end
 *
 * RETURN : true or false
 */
bool_t listPopBack(list list);
```

### listPopFront
```C
/* USE    : Remove begin listNode
 *
 * PARAM  : list - list you want to remove end
 *
 * RETURN : true or false
 */
bool_t listPopFront(list list);
```

### listIndexAt
```C
/* USE    : Get listNode from begin
 *
 * PARAM  : list    - which list you want to get listNode
 *          ordinal - ordinal to begin
 *
 * RETURN : listIterator or nullptr
 */
listIterator listIndexAt(list list, size_t ordinal);
```

### listInverseAt
```C
/* USE    : Get listNode from end
 *
 * PARAM  : list    - which list you want to get listNode
 *          ordinal - ordinal to end
 *
 * RETURN : listIterator or nullptr
 */
listIterator listInverseAt(list list, size_t ordinal);
```

### listBegin
```C
/* USE    : Begin of list
 *
 * PARAM  : list - which list you want to get begin
 *
 * RETURN : listIterator to begin listNode of list
 */
listIterator listBegin(list list);
```

### listEnd
```C
/* USE    : End of list
 * 
 * PARAM  : list - which list you want to get end
 *
 * RETURN : listIterator to end listNode of list
 */
listIterator listEnd(list list);
```

### listSetValue
```C
/*
 * USE    : Set value of node
 *
 * PARAM  : node  - listIterator to listNode you want to set value
 *          value - pointer to value to set
 *
 * RETURN : void
 */
void listSetValue(listIterator node, ptr_t value);
```

### listGetValue
```C
/*
 * USE    : Get value of node
 *
 * PARAM  : node  - listIterator to listNode you want to get value
 *          value - pointer to return value
 *
 * RETURN : void
 */
void listGetValue(listIterator node, ptr_t value);
```

### listGetDataPointer
```C
/*
 * USE    : Get pointer to data
 *
 * PARAM  : node - listIterator to listNode you want to get 
 * 
 * RETURN : pointer to data
 */
ptr_t listGetDataPointer(listIterator node);
```

### listAfter
```C
/*
 * USE    : Get a listNode after node
 *
 * PARAM  : node     - after this listNode
 *          distance - distance to node
 *
 * RETURN : listNode we want or nullptr
 */
listIterator listAfter(listIterator node, size_t distance);
```

### listBefore
```C
/*
 * USE    : Get a listNode before node
 *
 * PARAM  : node     - before this listNode
 *          distance - distance to node
 *
 * RETURN : listNode we want or nullptr
 */
listIterator listBefore(listIterator node, size_t distance);
```

### listInsertAfter
```C
/* USE    : Insert a listNode after node 
 *
 * PARAM  : node - after this listNode
 *
 * RETURN : listIterator to listNode inserted or nullptr
 */
listIterator listInsertAfter(listIterator node);
```

### listInsertBefore
```C
/* USE    : Insert a listNode before node 
 *
 * PARAM  : node - before this listNode
 *
 * RETURN : listIterator to listNode inserted or nullptr
 */
listIterator listInsertBefore(listIterator node);
```

### listRemove
```C
/* USE    : Remove node 
 *
 * PARAM  : node - listIterator to listNode you want to remove
 *
 * RETURN : void
 */
void listRemove(listIterator node);
```

### listClear
```C
/* USE    : Remove all node
 *
 * PARAM  : list - list to clear
 *
 * RETURN : void
 */
void listClear(list list);
```

### listHead
```C
/* USE    : Head of list 
 *
 * PARAM  : node - listIterator to any listNode of list
 *
 * RETURN : Head listNode of list
 */
listIterator listHead(listIterator node);
```

### listTail
```C
/* USE    : Tail of list
 *
 * PARAM  : node - listIterator to any listNode of list
 *
 * RETURN : Tail listNode of list
 */
listIterator listTail(listIterator node);
```

### listFindAfter
```C
/* USE    : Find a listNode after node
 * 
 * PARAM  : node   - after this listNode
 *          value  - pointer to value
 *          ordinal - ordinal number 
 *
 * RETURN : number ordinal listNode, whose data equals to value, 
 *          after node(inclusive) , or nullptr 
 */

listIterator listFindAfter(listIterator node, ptr_t value, size_t ordinal);
```

### listFindBefore
```C
/* USE    : Find a listNode before node
 * 
 * PARAM  : node   - before this listNode
 *          value  - pointer to value
 *          ordinal - ordinal number 
 *
 * RETURN : number ordinal listNode, whose data equals to value, 
 *          before node(inclusive) , or nullptr 
 */
listIterator listFindBefore(listIterator node, ptr_t value, size_t ordinal);
```



