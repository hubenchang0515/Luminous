/* Queue.h - deque
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

#include "core.h"
#include "list.h"

#ifdef __cplusplus 
	extern "C" {
#endif

typedef List Queue;

/* Create Queue */
Queue queueCreateBySize(size_t size);
#ifndef queueCreate
#   define queueCreate(T) listCreateBySize(sizeof(T))
#endif //queueCreate

/* Delete Queue */
void queueDelete(Queue queue);

/* Remove all data */
void queueClear(Queue queue);

/* Check Empty */
bool_t queueIsEmpty(Queue queue);

/* Push Back */
bool_t queuePush(Queue queue, ptr_t value);

/* Pop front */
bool_t queuePop(Queue queue, ptr_t value);

/* Push Back */
bool_t queuePushBack(Queue queue, ptr_t value);

/* Pop Back */
bool_t queuePopBack(Queue queue, ptr_t value);

/* Push Front */
bool_t queuePushFront(Queue queue, ptr_t value);

/* Pop Front */
bool_t queuePopFront(Queue queue, ptr_t value);

/* Get Front */
bool_t queueGetFront(Queue queue, ptr_t value);

/* Set Front */
bool_t queueSetFront(Queue queue, ptr_t value);

/* Get Back */
bool_t queueGetBack(Queue queue, ptr_t value);

/* Set Back */
bool_t queueSetBack(Queue queue, ptr_t value);

/* count */
size_t queueCount(Queue queue);

#ifdef __cplusplus
    }
#endif

#endif