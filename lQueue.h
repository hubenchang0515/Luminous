/* lQueue.h - deque
** https://github.com/hubenchang0515/Luminous
**
** Copyright (C) 2017 hubenchang0515
** Date    : 2017-8-30
** E-mail  : hubenchang0515@outlook.com
** Blog    : blog.kurukurumi.com
** LISENCE : LGPL v3.0
*/

#ifndef LUMINOUS_QUEUE_H
#define LUMINOUS_QUEUE_H

#include "lCore.h"
#include "lList.h"

#ifdef __cplusplus 
	extern "C" {
#endif

typedef lList lQueue;

/* Create lQueue */
lQueue lQueueCreateBySize(size_t size);
#ifndef lQueueCreate
#   define lQueueCreate(T) lListCreateBySize(sizeof(T))
#endif //lQueueCreate

/* Delete lQueue */
void lQueueDelete(lQueue queue);

/* Push Back */
bool_t lQueuePush(lQueue queue, ptr_t value);

/* Pop front */
bool_t lQueuePop(lQueue queue, ptr_t value);

/* Push Back */
bool_t lQueuePushBack(lQueue queue, ptr_t value);

/* Pop Back */
bool_t lQueuePopBack(lQueue queue, ptr_t value);

/* Push Front */
bool_t lQueuePushFront(lQueue queue, ptr_t value);

/* Pop Front */
bool_t lQueuePopFront(lQueue queue, ptr_t value);

/* Get Front */
bool_t lQueueGetFront(lQueue queue, ptr_t value);

/* Set Front */
bool_t lQueueSetFront(lQueue queue, ptr_t value);

/* Get Back */
bool_t lQueueGetBack(lQueue queue, ptr_t value);

/* Set Back */
bool_t lQueueSetBack(lQueue queue, ptr_t value);

/* count */
size_t lQueueCount(lQueue queue);

#ifdef __cplusplus
    }
#endif

#endif