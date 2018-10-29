/* List.c - Linked list.
** https://github.com/hubenchang0515/Luminous
**
** Copyright (C) 2017 hubenchang0515
** Date    : 2017-8-14
** E-mail  : hubenchang0515@outlook.com
** Blog    : blog.kurukurumi.com
** LISENCE : LGPL v3.0
*/

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "list.h"

/* WARNING : This is a UB(Undefined Behavior) */
#define SETCSTPTR(CSTPTR , ADDR) ((*(ptr_t*)(&(CSTPTR))) = ADDR)

/* Create a ListNode , return ListIterator or nnullptr */
static ListIterator lListCreateNodeBySize(size_t datasize)
{
	ListIterator node = (ListIterator)malloc(sizeof(ListNode));
	if(node == nullptr)
	{
		return nullptr;
	}
	
	node->size = datasize;
	node->prev = nullptr;
	node->next = nullptr;
	node->data = malloc(datasize);
	
	if(nullptr == node->data)
	{
		free(node);
		return nullptr;
	}
	
	return node;
}



/*
 * USE    : Create linked list
 *
 * PARAM  : datasize - size of node's data
 *
 * RETURN : List or nullptr
 */
List listCreateBySize(size_t datasize)
{
	List list = (List)malloc(sizeof(ListInfo));
	if(list == nullptr)
	{
		return nullptr;
	}
	
	list->datasize = datasize;
	list->begin = nullptr;
	list->end = nullptr;
	list->length = 0;
	return list;
}



/*
 * USE    : Delete linked list
 *
 * PARAM  : list - List to delete
 *
 * RETURN : void
 */
void listDelete(List list)
{
	ListForEach(iter,list)
	{
		free(iter->data);
		free(iter->prev);
	}
	free(list->end);
	free(list);
} 



/* USE    : Begin of list
 *
 * PARAM  : list - which list you want to get begin
 *
 * RETURN : ListIterator to begin ListNode of list
 */
ListIterator listBegin(List list)
{
	return list->begin;
}



/* USE    : End of list
 * 
 * PARAM  : list - which list you want to get end
 *
 * RETURN : ListIterator to end ListNode of list
 */
ListIterator listEnd(List list)
{
	return list->end;
}



/*
 * USE    : Set value of node
 *
 * PARAM  : node  - ListIterator to ListNode you want to set value
 *          value - pointer to value to set
 *
 * RETURN : void
 */
void listSetValue(ListIterator node, ptr_t value)
{
	memcpy(node->data,value,node->size);
}



/*
 * USE    : Get value of node
 *
 * PARAM  : node  - ListIterator to ListNode you want to get value
 *          value - pointer to return value
 *
 * RETURN : void
 */
void listGetValue(ListIterator node, ptr_t value)
{
	memcpy(value,node->data,node->size);
}



/*
 * USE    : Get pointer to data
 *
 * PARAM  : node - ListIterator to ListNode you want to get 
 * 
 * RETURN : pointer to data
 */
ptr_t listGetDataPointer(ListIterator node)
{
	return node->data;
}



/*
 * USE    : Get a ListNode after node
 *
 * PARAM  : node     - after this ListNode
 *          distance - distance to node
 *
 * RETURN : ListNode we want or nullptr
 */
ListIterator listAfter(ListIterator node, size_t distance)
{
	ListIterator p = node;
	for(size_t i = 0; i < distance && p != nullptr; i++)
	{
		p = p->next;
	}
	
	return p;
}



/*
 * USE    : Get a ListNode before node
 *
 * PARAM  : node     - before this ListNode
 *          distance - distance to node
 *
 * RETURN : ListNode we want or nullptr
 */
ListIterator listBefore(ListIterator node, size_t distance)
{
	ListIterator p = node;
	for(size_t i = 0; i < distance && p != nullptr; i++)
	{
		p = p->prev;
	}
	
	return p;
}



/* USE    : Insert a ListNode after node 
 *
 * PARAM  : node - after this ListNode
 *
 * RETURN : ListIterator to ListNode inserted or nullptr
 */
ListIterator listInsertAfter(ListIterator node)
{
	/* insert */
	ListIterator p = lListCreateNodeBySize(node->size);
	if(p != nullptr)
	{
		p->list = node->list;
		if(node->next != nullptr)
		{
			p->next = node->next;
			node->next->prev = p;
		}
		p->prev = node;
		node->next = p;
	
		/* update end of list */
		if(p->next == nullptr)
		{
			p->list->end = p;
		}
		
		/* update length of list */
		p->list->length += 1;
	}
	
	return p;
}



/* USE    : Insert a ListNode before node 
 *
 * PARAM  : node - before this ListNode
 *
 * RETURN : ListIterator to ListNode inserted or nullptr
 */
ListIterator listInsertBefore(ListIterator node)
{
	/* insert */
	ListIterator p = lListCreateNodeBySize(node->size);
	if(p != nullptr)
	{
		p->list = node->list;
		if(node->prev != nullptr)
		{
			p->prev = node->prev;
			node->prev->next = p;
		}
		p->next = node;
		node->prev = p;
	
		/* update begin of list */
		if(p->prev == nullptr)
		{
			p->list->begin = p;
		}
		
		/* update length of list */
		p->list->length += 1;
	}
	
	return p;
}



/* USE    : Remove node 
 *
 * PARAM  : node - ListIterator to ListNode you want to remove
 *
 * RETURN : void
 */
void listRemove(ListIterator node)
{
	/* update end of list */
	if(node->next == nullptr)
	{
		node->list->end = node->prev;
	}
	else // 
	{
		node->next->prev = node->prev;
	}
	
	/* update begin of list */
	if(node->prev == nullptr)
	{
		node->list->begin = node->next;
	}
	else
	{
		node->prev->next = node->next;
	}
	
	/* update length of list */
	node->list->length -= 1;
	
	/* remove */
	free(node->data);
	free(node);
	
}



/* USE    : Remove all node
 *
 * PARAM  : list - List to clear
 *
 * RETURN : void
 */
void listClear(List list)
{
	ListIterator p   = listEnd(list);
	ListIterator pre = listBefore(p,1);
	while(p != nullptr)
	{
		free(p->data);
		free(p);
		p = pre;
		pre = listBefore(p,1);
	}

	list->begin  = nullptr;
	list->end    = nullptr;
	list->length = 0;
}



/* USE    : Head of list 
 *
 * PARAM  : node - ListIterator to any ListNode of list
 *
 * RETURN : Head ListNode of list
 */
ListIterator listHead(ListIterator node)
{
	ListIterator p = node->list->begin;
	
	return p;
}

/* USE    : Tail of list
 *
 * PARAM  : node - ListIterator to any ListNode of list
 *
 * RETURN : Tail ListNode of list
 */
ListIterator listTail(ListIterator node)
{
	ListIterator p = node->list->end;
	
	return p;
}

/* USE    : Find a ListNode after node
 * 
 * PARAM  : node   - after this ListNode
 *          value  - pointer to value
 *          ordinal - ordinal number 
 *
 * RETURN : number ordinal ListNode, whose data equals to value, 
 *          after node(inclusive) , or nullptr 
 */

ListIterator listFindAfter(ListIterator node, ptr_t value, size_t ordinal)
{
	ListIterator p = node;
	for(size_t i = 0; i < ordinal && p != nullptr; p = p->next)
	{
		if(memcmp(p->data, value, p->size) == 0)
		{
			i++;
		}
		
		if( i >= ordinal )
		{
			break;
		}
	}
	
	return p;
}

/* USE    : Find a ListNode before node
 * 
 * PARAM  : node   - before this ListNode
 *          value  - pointer to value
 *          ordinal - ordinal number 
 *
 * RETURN : number ordinal ListNode, whose data equals to value, 
 *          before node(inclusive) , or nullptr 
 */
ListIterator listFindBefore(ListIterator node, ptr_t value, size_t ordinal)
{
	ListIterator p = node;
	for(size_t i = 0; i < ordinal && p != nullptr; p = p->prev)
	{
		if(memcmp(p->data, value, p->size) == 0)
		{
			i++;
		}
		
		if( i >= ordinal )
		{
			break;
		}
	}
	
	return p;
}

/* USE    : ListNode number of list
 *
 * PARAM  : List
 *
 * RETURN : ListNode number of list
 */
size_t listCount(List list)
{	
	return list->length;
}



/* USE    : check list if empty 
 *
 * PARAM  : list - List you want to check
 *
 * RETURN : true of false
 */
bool_t listIsEmpty(List list)
{
	return list->length == 0 ? true : false;
}



/* USE    : Insert a ListNode after end
 *
 * PARAM  : list  - List you want to insert
 *          value - value you want to insert
 *
 * RETURN : ListIterator to ListNode inserted or nullptr
 */
ListIterator listPushBack(List list, ptr_t value)
{
	ListIterator p = list->end;
	if(p != nullptr)
	{
		p = listInsertAfter(p);
		if(p != nullptr)
		{
			listSetValue(p,value);
		}
	}
	else // list is empty
	{
		assert(list->begin == nullptr); // list is empty
		
		/* Create first node */
		p = lListCreateNodeBySize(list->datasize);
		if(p != nullptr)
		{
			p->list = list;
			list->begin = p;
			list->end = p;
			list->length = 1;
			listSetValue(p,value);
		}
	}
	
	return p;
}



/* USE    : Insert a ListNode before begin
 *
 * PARAM  : list  - List you want to insert
 *          value - value you want to insert
 *
 * RETURN : ListIterator to ListNode inserted or nullptr
 */
ListIterator listPushFront(List list, ptr_t value)
{
	ListIterator p = list->begin;
	if(p != nullptr)
	{
		p = listInsertBefore(p);
		if(p != nullptr)
		{
			listSetValue(p,value);
		}
	}
	else // list is empty
	{
		assert(list->end == nullptr); // list is empty
		
		/* Create first node */
		p = lListCreateNodeBySize(list->datasize);
		if(p != nullptr)
		{
			p->list = list;
			list->begin = p;
			list->end = p;
			list->length = 1;
			listSetValue(p,value);
		}
	}
	
	return p;
}



/* USE    : Remove end ListNode
 *
 * PARAM  : list - list you want to remove end
 *
 * RETURN : true or false
 */
bool_t listPopBack(List list)
{
	if(list->end != nullptr)
	{
		listRemove(list->end);
		return true;
	}
	else
	{
		return false;
	}
}

/* USE    : Remove begin ListNode
 *
 * PARAM  : list - list you want to remove end
 *
 * RETURN : true or false
 */
bool_t listPopFront(List list)
{
	if(list->begin != nullptr)
	{
		listRemove(list->begin);
		return true;
	}
	else
	{
		return false;
	}
}



/* USE    : Get ListNode from begin
 *
 * PARAM  : list    - which list you want to get ListNode
 *          ordinal - ordinal to begin
 *
 * RETURN : ListIterator or nullptr
 */
ListIterator listIndexAt(List list, size_t ordinal)
{
	return listAfter(list->begin, ordinal);
}



/* USE    : Get ListNode from end
 *
 * PARAM  : list    - which list you want to get ListNode
 *          ordinal - ordinal to end
 *
 * RETURN : ListIterator or nullptr
 */
ListIterator listInverseAt(List list, size_t ordinal)
{
	return listBefore(list->end, ordinal);
}


