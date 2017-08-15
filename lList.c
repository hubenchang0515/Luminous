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

/* Create a lListNode , return lListNode* or nnullptr */
static lListNode* lListCreateNodeBySize(size_t datasize)
{
	lListNode* node = malloc(sizeof(lListNode));
	if(node == nullptr)
	{
		return nullptr;
	}
	
	node->size = datasize;
	node->prev = nullptr;
	node->next = nullptr;
	node->data = malloc(datasize);
	
	if(node->data == nullptr)
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
 * RETURN : head lListNode of list or nullptr
 */
lListNode* lListCreateBySize(size_t datasize)
{
	return lListCreateNodeBySize(datasize);
}



/*
 * USE    : Delete linked list
 *
 * PARAM  : list - any lListNode of list
 *
 * RETURN : void
 */
void lListDelete(lListNode* list)
{
	lListNode* node = nullptr;

	/* free nodes before current node */
	if(list->prev != nullptr)
	{
		for(node = list->prev; node->prev != nullptr; free(node->next) )
		{
			free(node->data);
			node = node->prev;
		}
		free(node->data);
		free(node); // first node
	}
	
	/* free nodes after current node */
	if(list->next != nullptr)
	{
		for(node = list->next; node->next != nullptr; free(node->prev))
		{
			free(node->data);
			node = node->next;
		} 
		free(node->data);
		free(node); // last node
	}
	
	/* free current node */
	free(list->data);
	free(list);
} 



/*
 * USE    : Set value of node
 *
 * PARAM  : node  - lListNode to set
 *          value - pointer to value to set
 *
 * RETURN : void
 */
void lListSetValue(lListNode* node, ptr_t value)
{
	memcpy(node->data,value,node->size);
}



/*
 * USE    : Get value of node
 *
 * PARAM  : node  - lListNode to get
 *          value - pointer to return value
 *
 * RETURN : void
 */
void lListGetValue(lListNode* node, ptr_t value)
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
lListNode* lListAfter(lListNode* node, size_t distance)
{
	lListNode* p = node;
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
lListNode* lListBefore(lListNode* node, size_t distance)
{
	lListNode* p = node;
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
 * RETURN : lListNode inserted or nullptr
 */
lListNode* lListInsertAfter(lListNode* node)
{
	lListNode* p = lListCreateNodeBySize(node->size);
	if(p != nullptr)
	{
		if(node->next != nullptr)
		{
			p->next = node->next;
			node->next->prev = p;
		}
		p->prev = node;
		node->next = p;
	}
	
	return p;
}



/* USE    : Insert a lListNode before node 
 *
 * PARAM  : node - before this lListNode
 *
 * RETURN : lListNode inserted or nullptr
 */
lListNode* lListInsertBefore(lListNode* node)
{
	lListNode* p = lListCreateNodeBySize(node->size);
	if(p != nullptr)
	{
		if(node->prev != nullptr)
		{
			p->prev = node->prev;
			node->prev->next = p;
		}
		p->next = node;
		node->prev = p;
	}
	
	return p;
}



/* USE    : Remove node 
 *
 * PARAM  : node - lListNode to remove
 *
 * RETURN : void
 */
void lListRemove(lListNode* node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node->data);
	free(node);
}



/* USE    : Head of list 
 *
 * PARAM  : node - any lListNode of list
 *
 * RETURN : Head lListNode of list
 */
lListNode* lListHead(lListNode* node)
{
	lListNode* p = node;
	for( ; p->prev != nullptr; p = p->prev);
	
	return p;
}

/* USE    : Tail of list
 *
 * PARAM  : node - any lListNode of list
 *
 * RETURN : Tail lListNode of list
 */
lListNode* lListTail(lListNode* node)
{
	lListNode* p = node;
	for( ; p->next != nullptr; p = p->next);
	
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

lListNode* lListFindAfter(lListNode* node, ptr_t value, size_t ordinal)
{
	lListNode* p = node;
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
lListNode* lListFindBefore(lListNode* node, ptr_t value, size_t ordinal)
{
	lListNode* p = node;
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
 * PARAM  : any lListNode of list
 *
 * RETURN : lListNode number of list
 */
size_t lListCount(lListNode* node)
{
	size_t count = 0;
	lListNode*p = nullptr;
	
	for(p = node ; p != nullptr; p = p->prev)
	{
		count++;
	}
	
	for(p = node->next; p!= nullptr; p = p->next)
	{
		count++;
	}
	
	return count;
}



