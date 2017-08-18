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

#ifdef __cplusplus 
	extern "C" {
#endif


/* Double-linked List and Node */
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



/* for-each */
#ifndef lListFor 
#	define lListForEach(iter,list) \
		for(lListIterator iter = list->begin; iter != nullptr; iter = iter->next)
#endif // lListFor


/* Create linked list */
lList lListCreateBySize(size_t datasize);
#ifndef lListCreate
#	define lListCreate(T) lListCreateBySize(sizeof(T))
#endif // lListCreate

/* Delete linked list */
void lListDelete(lList list);

/* Begin of list */
lListIterator lListBegin(lList list);

/* End of list */
lListIterator lListEnd(lList list);

/* Set value of node */
void lListSetValue(lListIterator node, ptr_t value);

/* Get value of node */
void lListGetValue(lListIterator node, ptr_t value);

/* Get pointer to data */
ptr_t lListGetDataPointer(lListIterator node);

/* Get a lListNode after node */
lListIterator lListAfter(lListIterator node, size_t distance);

/* Get a lListNode before node */
lListIterator lListBefore(lListIterator node, size_t distance);

/* Insert a lListNode after node */
lListIterator lListInsertAfter(lListIterator node);

/* Insert a lListNode before node */
lListIterator lListInsertBefore(lListIterator node);

/* Remove node */
void lListRemove(lListIterator node);

/* Head of list */
lListIterator lListHead(lListIterator node);

/* Tail of list */
lListIterator lListTail(lListIterator node);

/* Find a lListNode after node */
lListIterator lListFindAfter(lListIterator node, ptr_t value, size_t ordinal);

/* Find a lListNode before node */
lListIterator lListFindBefore(lListIterator node, ptr_t value, size_t ordinal);

/* Nodes number of list */
size_t lListCount(lList node);

/* check list if empty  */
bool_t lListIsEmpty(lList list);

/* Insert a lListNode after end */
lListIterator lListPushBack(lList list, ptr_t value);

/* Insert a lListNode before begin */
lListIterator lListPushFront(lList list, ptr_t value);

/* Remove end lListNode */
void lListPopBack(lList list);

/* Remove begin lListNode */
void lListPopFront(lList list);

/* Get lListNode from begin */
lListIterator lListIndexAt(lList list, size_t ordinal);

/* Get lListNode from end */
lListIterator lListInverseAt(lList list, size_t ordinal);

#ifdef __cplusplus 
	}
#endif

#endif // LUMINOUS_LIST_H
