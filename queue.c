/* Queue.c - deque
** https://github.com/hubenchang0515/Luminous
**
** Copyright (C) 2017 hubenchang0515
** Date    : 2017-8-30
** E-mail  : hubenchang0515@outlook.com
** Blog    : blog.kurukurumi.com
** LISENCE : LGPL v3.0
*/

#include "queue.h"

/* USE    : Create a Queue
 *
 * PARAM  : size - size of one data
 *
 * RETURN : new Queue or nullptr
 */
Queue queueCreateBySize(size_t size)
{
    return listCreateBySize(size);
}



/* USE    : Delete queue
 *
 * PARAM  : queue - Queue to delete
 *
 * RETURN : void
 */
void queueDelete(Queue queue)
{
    listDelete(queue);
}



/* USE    : Remove all data
 *
 * PARAM  : queue - lQeueu to clear
 *
 * RETURN : void
 */
void queueClear(Queue queue)
{
    listClear(queue);
}



/* USE    : Check Empty
 *
 * PARAM  : queue - Queue to check
 *
 * RETURN : true or false
 */
bool_t queueIsEmpty(Queue queue)
{
    return listIsEmpty(queue);
}



/* USE    : Push Back 
 *
 * PARAM  : queue - Queue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */
bool_t queuePush(Queue queue, ptr_t value)
{
    return listPushBack(queue,value) != nullptr;
}

/* USE    : Pop front
 *
 * PARAM  : queue - Queue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */
bool_t queuePop(Queue queue, ptr_t value)
{
    ListIterator p = listBegin(queue);
    if(p != nullptr)
    {
        listGetValue(p,value);
        listPopFront(queue); 
        return true;
    }
    else
    {
        return false;
    } 
}



/* USR    : Push Back
 *
 * PARAM  : queue - Queue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t queuePushBack(Queue queue, ptr_t value)
{
    return listPushBack(queue,value) != nullptr;
}

/* USE    : Pop Back
 *
 * PARAM  : queue - Queue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t queuePopBack(Queue queue, ptr_t value)
{
    ListIterator p = listEnd(queue);
    if(p != nullptr)
    {
        listGetValue(p,value);
        listPopBack(queue);
        return true;
    }
    else
    {
        return false;
    }
}

/* USE    : Push Front
 *
 * PARAM  : queue - Queue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t queuePushFront(Queue queue, ptr_t value)
{
    return listPushFront(queue,value) != nullptr;
}

/* USE    : Pop Front
 *
 * PARAM  : queue - Queue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t queuePopFront(Queue queue, ptr_t value)
{
    ListIterator p = listBegin(queue);
    if(p != nullptr)
    {
        listGetValue(p,value);
        listPopFront(queue); 
        return true;
    }
    else
    {
        return false;
    } 
}

/* USE    : Get Front but not remove it
 *
 * PARAM  : queue - Queue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t queueGetFront(Queue queue, ptr_t value)
{
    ListIterator p = listBegin(queue);
    if(p != nullptr)
    {
        listGetValue(p,value);
        return true;
    }
    else
    {
        return false;
    } 
}



/* USE    : Set Front rather than push
 *
 * PARAM  : queue - Queue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t queueSetFront(Queue queue, ptr_t value)
{
    ListIterator p = listBegin(queue);
    if(p != nullptr)
    {
        listSetValue(p,value);
        return true;
    }
    else
    {
        return false;
    } 
}



/* USE    : Get Back but not remove it
 *
 * PARAM  : queue - Queue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t queueGetBack(Queue queue, ptr_t value)
{
    ListIterator p = listEnd(queue);
    if(p != nullptr)
    {
        listGetValue(p,value);
        return true;
    }
    else
    {
        return false;
    }
}



/* USE    : Set Back rather than push
 *
 * PARAM  : queue - Queue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t queueSetBack(Queue queue, ptr_t value)
{
    ListIterator p = listEnd(queue);
    if(p != nullptr)
    {
        listSetValue(p,value);
        return true;
    }
    else
    {
        return false;
    }
}


/* USE    : Count
 *
 * PARAM  : queue - Queue to get count
 *
 * RETURN : count of queue
 */
size_t queueCount(Queue queue)
{
    return listCount(queue);
}