/* List.h - Linked list.
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

#include "core.h"

#ifdef __cplusplus 
	extern "C" {
#endif


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



/* for-each */
#ifndef ListForEach 
#	define ListForEach(iter,list) \
		for(ListIterator iter = list->begin; iter != nullptr; iter = iter->next)
#endif // lListFor


/* Create linked list */
List listCreateBySize(size_t datasize);
#ifndef listCreate
#	define listCreate(T) listCreateBySize(sizeof(T))
#endif // listCreate

/* Delete linked list */
void listDelete(List list);

/* Begin of list */
ListIterator listBegin(List list);

/* End of list */
ListIterator listEnd(List list);

/* Set value of node */
void listSetValue(ListIterator node, ptr_t value);

/* Get value of node */
void listGetValue(ListIterator node, ptr_t value);

/* Get pointer to data */
ptr_t listGetDataPointer(ListIterator node);

/* Get a ListNode after node */
ListIterator listAfter(ListIterator node, size_t distance);

/* Get a ListNode before node */
ListIterator listBefore(ListIterator node, size_t distance);

/* Insert a ListNode after node */
ListIterator listInsertAfter(ListIterator node);

/* Insert a ListNode before node */
ListIterator listInsertBefore(ListIterator node);

/* Remove node */
void listRemove(ListIterator node);

/* Remove all node */
void listClear(List list);

/* Head of list */
ListIterator listHead(ListIterator node);

/* Tail of list */
ListIterator listTail(ListIterator node);

/* Find a ListNode after node */
ListIterator listFindAfter(ListIterator node, ptr_t value, size_t ordinal);

/* Find a ListNode before node */
ListIterator listFindBefore(ListIterator node, ptr_t value, size_t ordinal);

/* Nodes number of list */
size_t listCount(List node);

/* check list if empty  */
bool_t listIsEmpty(List list);

/* Insert a ListNode after end */
ListIterator listPushBack(List list, ptr_t value);

/* Insert a ListNode before begin */
ListIterator listPushFront(List list, ptr_t value);

/* Remove end ListNode */
bool_t listPopBack(List list);

/* Remove begin ListNode */
bool_t listPopFront(List list);

/* Get ListNode from begin */
ListIterator listIndexAt(List list, size_t ordinal);

/* Get ListNode from end */
ListIterator listInverseAt(List list, size_t ordinal);

#ifdef __cplusplus 
	}
#endif

#endif // LUMINOUS_LIST_H
