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
 * RETURN : pointer to header of linked list or nullptr
 */
lListNode* lListCreateBySize(size_t datasize)
{
	return lListCreateNodeBySize(datasize);
}



/*
 * USE    : Delete linked list
 *
 * PARAM  : list - any node of linked list
 *
 * RETURN : void
 */
void lListDelete(lListNode* list)
{
	lListNode* node = nullptr;

	/* free nodes before current node */
	for(node = list->prev; node != nullptr; free(node->next) )
	{
		free(node->data);
		node = node->prev;
	}
	free(node->data); // first node
	free(node);
	
	/* free nodes after current node */
	for(node = list->next; node != nullptr; free(node->prev))
	{
		free(node->data);
		node = node->next;
	}
	free(node->data); // last node
	free(node);
	
	/* free current node */
	free(list->data);
	free(list);
} 



/*
 * USE    : Set value of node
 *
 * PARAM  : node  - node to set
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
 * PARAM  : node  - node to get
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
 * PARAM  : node     - current node
 *          distance - distance to current node
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
 * PARAM  : node     - current node
 *          distance - distance to current node
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
 * PARAM  : node - current node
 *
 * RETURN : lListNode inserted or nullptr
 */
lListNode* lListInsterAfter(lListNode* node)
{
	lListNode* p = lListCreateNodeBySize(node->size);
	if(p != nullptr)
	{
		p->prev = node;
		p->next = node->next;
		node->next->prev = p;
		node->next = p;
	}
	
	return p;
}



/* USE    : Insert a lListNode before node 
 *
 * PARAM  : node - current node
 *
 * RETURN : lListNode inserted or nullptr
 */
lListNode* lListInsterBefore(lListNode* node)
{
	lListNode* p = lListCreateNodeBySize(node->size);
	if(p != nullptr)
	{
		p->next = node;
		p->prev = node->prev;
		node->prev->next = p;
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

