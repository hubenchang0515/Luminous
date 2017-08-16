/* lList.c - Linked list.
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
#include "lList.h"

/* WARNING : This is a UB(Undefined Behavior) */
#define SETCSTPTR(CSTPTR , ADDR) ((*(ptr_t*)(&(CSTPTR))) = ADDR)

/* Create a lListNode , return lListIterator or nnullptr */
static lListIterator lListCreateNodeBySize(size_t datasize)
{
	lListIterator node = (lListIterator)malloc(sizeof(lListNode));
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
 * RETURN : lList or nullptr
 */
lList lListCreateBySize(size_t datasize)
{
	lList list = (lList)malloc(sizeof(lListInfo));
	if(list == nullptr)
	{
		return nullptr;
	}
	
	list->begin = lListCreateNodeBySize(datasize);
	list->begin->list = list;
	if(list->begin == nullptr)
	{
		free(list);
		return nullptr;
	}
	
	list->end = list->begin;
	list->length = 1;
	return list;
}



/*
 * USE    : Delete linked list
 *
 * PARAM  : list - lList to delete
 *
 * RETURN : void
 */
void lListDelete(lList list)
{
	lListForEach(iter,list)
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
 * RETURN : lListIterator to begin lListNode of list
 */
lListIterator lListBegin(lList list)
{
	return list->begin;
}



/* USE    : End of list
 * 
 * PARAM  : list - which list you want to get end
 *
 * RETURN : lListIterator to end lListNode of list
 */
lListIterator lListEnd(lList list)
{
	return list->end;
}



/*
 * USE    : Set value of node
 *
 * PARAM  : node  - lListIterator to lListNode you want to set value
 *          value - pointer to value to set
 *
 * RETURN : void
 */
void lListSetValue(lListIterator node, ptr_t value)
{
	memcpy(node->data,value,node->size);
}



/*
 * USE    : Get value of node
 *
 * PARAM  : node  - lListIterator to lListNode you want to get value
 *          value - pointer to return value
 *
 * RETURN : void
 */
void lListGetValue(lListIterator node, ptr_t value)
{
	memcpy(value,node->data,node->size);
}



/*
 * USE    : Get a lListNode after node
 *
 * PARAM  : node     - after this lListNode
 *          distance - distance to node
 *
 * RETURN : lListNode we want or nullptr
 */
lListIterator lListAfter(lListIterator node, size_t distance)
{
	lListIterator p = node;
	for(size_t i = 0; i < distance && p != nullptr; i++)
	{
		p = p->next;
	}
	
	return p;
}



/*
 * USE    : Get a lListNode before node
 *
 * PARAM  : node     - before this lListNode
 *          distance - distance to node
 *
 * RETURN : lListNode we want or nullptr
 */
lListIterator lListBefore(lListIterator node, size_t distance)
{
	lListIterator p = node;
	for(size_t i = 0; i < distance && p != nullptr; i++)
	{
		p = p->prev;
	}
	
	return p;
}



/* USE    : Insert a lListNode after node 
 *
 * PARAM  : node - after this lListNode
 *
 * RETURN : lListIterator to lListNode inserted or nullptr
 */
lListIterator lListInsertAfter(lListIterator node)
{
	/* insert */
	lListIterator p = lListCreateNodeBySize(node->size);
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



/* USE    : Insert a lListNode before node 
 *
 * PARAM  : node - before this lListNode
 *
 * RETURN : lListIterator to lListNode inserted or nullptr
 */
lListIterator lListInsertBefore(lListIterator node)
{
	/* insert */
	lListIterator p = lListCreateNodeBySize(node->size);
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
 * PARAM  : node - lListIterator to lListNode you want to remove
 *
 * RETURN : void
 */
void lListRemove(lListIterator node)
{
	/* update end of list */
	if(node->next == nullptr)
	{
		node->list->end = node->prev;
	}
	
	/* update begin of list */
	if(node->prev == nullptr)
	{
		node->list->begin = node->next;
	}
	
	/* update length of list */
	node->list->length -= 1;
	
	/* remove */
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node->data);
	free(node);
	
}



/* USE    : Head of list 
 *
 * PARAM  : node - lListIterator to any lListNode of list
 *
 * RETURN : Head lListNode of list
 */
lListIterator lListHead(lListIterator node)
{
	lListIterator p = node->list->begin;
	
	return p;
}

/* USE    : Tail of list
 *
 * PARAM  : node - lListIterator to any lListNode of list
 *
 * RETURN : Tail lListNode of list
 */
lListIterator lListTail(lListIterator node)
{
	lListIterator p = node->list->end;
	
	return p;
}

/* USE    : Find a lListNode after node
 * 
 * PARAM  : node   - after this lListNode
 *          value  - pointer to value
 *          ordinal - ordinal number 
 *
 * RETURN : number ordinal lListNode, whose data equals to value, 
 *          after node(inclusive) , or nullptr 
 */

lListIterator lListFindAfter(lListIterator node, ptr_t value, size_t ordinal)
{
	lListIterator p = node;
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

/* USE    : Find a lListNode before node
 * 
 * PARAM  : node   - before this lListNode
 *          value  - pointer to value
 *          ordinal - ordinal number 
 *
 * RETURN : number ordinal lListNode, whose data equals to value, 
 *          before node(inclusive) , or nullptr 
 */
lListIterator lListFindBefore(lListIterator node, ptr_t value, size_t ordinal)
{
	lListIterator p = node;
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

/* USE    : lListNode number of list
 *
 * PARAM  : lList
 *
 * RETURN : lListNode number of list
 */
size_t lListCount(lList list)
{	
	return list->length;
}



