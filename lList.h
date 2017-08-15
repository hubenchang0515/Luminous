/* lList.h - Linked list.
** https://github.com/hubenchang0515/Luminous
**
** Copyright (C) 2017 hubenchang0515
** Date    : 2017-8-14
** E-mail  : hubenchang0515@outlook.com
** Blog    : blog.kurukurumi.com
** LISENCE : LGPL v3.0
*/

#ifndef LUMINOUS_LIST_H
#define LUMINOUS_LIST_H

#include "lCore.h"



/* Linked List Node */
typedef struct lListNode lListNode;
struct lListNode
{
	size_t      size;  // size of data
	lListNode*  prev;  // previous node
	lListNode*  next;  // next node
	ptr_t       data;  // pointer to data
};



/* for-each */
#ifndef lListFor 
# 	define lListFor(index,header) for(size_t index = header; index!=nullptr; index = index->next)
#endif // lListFor


/* Create linked list */
lListNode* lListCreateBySize(size_t datasize);
#ifndef lListCreate
#	define lListCreate(T) lListCreateBySize(sizeof(T))
#endif // lListCreate

/* Delete linked list */
void lListDelete(lListNode* list);

/* Set value of node */
void lListSetValue(lListNode* node, ptr_t value);

/* Get value of node */
void lListGetValue(lListNode* node, ptr_t value);

/* Get a lListNode after node */
lListNode* lListAfter(lListNode* node, size_t distance);

/* Get a lListNode before node */
lListNode* lListBefore(lListNode* node, size_t distance);

/* Insert a lListNode after node */
lListNode* lListInsterAfter(lListNode* node);

/* Insert a lListNode before node */
lListNode* lListInsterBefore(lListNode* node);

/* Remove node */
void lListRemove(lListNode* node);

#endif // LUMINOUS_LIST_H