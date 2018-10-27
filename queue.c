/* lQueue.c - deque
** https://github.com/hubenchang0515/Luminous
**
** Copyright (C) 2017 hubenchang0515
** Date    : 2017-8-30
** E-mail  : hubenchang0515@outlook.com
** Blog    : blog.kurukurumi.com
** LISENCE : LGPL v3.0
*/

#include "lQueue.h"

/* USE    : Create a lQueue
 *
 * PARAM  : size - size of one data
 *
 * RETURN : new lQueue or nullptr
 */
lQueue lQueueCreateBySize(size_t size)
{
    return lListCreateBySize(size);
}



/* USE    : Delete queue
 *
 * PARAM  : queue - lQueue to delete
 *
 * RETURN : void
 */
void lQueueDelete(lQueue queue)
{
    lListDelete(queue);
}



/* USE    : Remove all data
 *
 * PARAM  : queue - lQeueu to clear
 *
 * RETURN : void
 */
void lQueueClear(lQueue queue)
{
    lListClear(queue);
}



/* USE    : Check Empty
 *
 * PARAM  : queue - lQueue to check
 *
 * RETURN : true or false
 */
bool_t lQueueIsEmpty(lQueue queue)
{
    return lListIsEmpty(queue);
}



/* USE    : Push Back 
 *
 * PARAM  : queue - lQueue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */
bool_t lQueuePush(lQueue queue, ptr_t value)
{
    return lListPushBack(queue,value) != nullptr;
}

/* USE    : Pop front
 *
 * PARAM  : queue - lQueue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */
bool_t lQueuePop(lQueue queue, ptr_t value)
{
    lListIterator p = lListBegin(queue);
    if(p != nullptr)
    {
        lListGetValue(p,value);
        lListPopFront(queue); 
        return true;
    }
    else
    {
        return false;
    } 
}



/* USR    : Push Back
 *
 * PARAM  : queue - lQueue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t lQueuePushBack(lQueue queue, ptr_t value)
{
    return lListPushBack(queue,value) != nullptr;
}

/* USE    : Pop Back
 *
 * PARAM  : queue - lQueue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t lQueuePopBack(lQueue queue, ptr_t value)
{
    lListIterator p = lListEnd(queue);
    if(p != nullptr)
    {
        lListGetValue(p,value);
        lListPopBack(queue);
        return true;
    }
    else
    {
        return false;
    }
}

/* USE    : Push Front
 *
 * PARAM  : queue - lQueue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t lQueuePushFront(lQueue queue, ptr_t value)
{
    return lListPushFront(queue,value) != nullptr;
}

/* USE    : Pop Front
 *
 * PARAM  : queue - lQueue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t lQueuePopFront(lQueue queue, ptr_t value)
{
    lListIterator p = lListBegin(queue);
    if(p != nullptr)
    {
        lListGetValue(p,value);
        lListPopFront(queue); 
        return true;
    }
    else
    {
        return false;
    } 
}

/* USE    : Get Front but not remove it
 *
 * PARAM  : queue - lQueue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t lQueueGetFront(lQueue queue, ptr_t value)
{
    lListIterator p = lListBegin(queue);
    if(p != nullptr)
    {
        lListGetValue(p,value);
        return true;
    }
    else
    {
        return false;
    } 
}



/* USE    : Set Front rather than push
 *
 * PARAM  : queue - lQueue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t lQueueSetFront(lQueue queue, ptr_t value)
{
    lListIterator p = lListBegin(queue);
    if(p != nullptr)
    {
        lListSetValue(p,value);
        return true;
    }
    else
    {
        return false;
    } 
}



/* USE    : Get Back but not remove it
 *
 * PARAM  : queue - lQueue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t lQueueGetBack(lQueue queue, ptr_t value)
{
    lListIterator p = lListEnd(queue);
    if(p != nullptr)
    {
        lListGetValue(p,value);
        return true;
    }
    else
    {
        return false;
    }
}



/* USE    : Set Back rather than push
 *
 * PARAM  : queue - lQueue to add node
 *          value - value of new node
 *
 * RETURN : true or false
 */ 
bool_t lQueueSetBack(lQueue queue, ptr_t value)
{
    lListIterator p = lListEnd(queue);
    if(p != nullptr)
    {
        lListSetValue(p,value);
        return true;
    }
    else
    {
        return false;
    }
}


/* USE    : Count
 *
 * PARAM  : queue - lQueue to get count
 *
 * RETURN : count of queue
 */
size_t lQueueCount(lQueue queue)
{
    return lListCount(queue);
}