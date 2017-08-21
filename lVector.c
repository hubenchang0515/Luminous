/* lVector.h - Vector.
** https://github.com/hubenchang0515/Luminous
**
** Copyright (C) 2017 hubenchang0515
** Date    : 2017-8-17
** E-mail  : hubenchang0515@outlook.com
** Blog    : blog.kurukurumi.com
** LISENCE : LGPL v3.0
*/

#include <stdlib.h>
#include <string.h>
#include "lVector.h"

/*
 * USE    : Create lVector by size of data
 *
 * PARAM  : size - size of data
 *
 * RETURN : lVector or nullptr
 */
lVector lVectorCreateBySize(size_t size)
{
    lVector vector = (lVector)malloc(sizeof(lVectorInfo));
    if(vector == nullptr)
    {
        return nullptr;
    }

    vector->space = 0;
    vector->used = 0;
    vector->size = size;
    vector->data = nullptr;

    return vector;
}



/*
 * USE    : Delete Vector
 *
 * PARAM  : vector - lVector to delete
 *
 * RETURN : void
 */
void lVectorDelete(lVector vector)
{
    free(vector->data);
    free(vector);
}



/*
 * USE    : Increase space of vector
 *
 * PARAM  : vector - lVector you want to increase
 *
 * RETURN : true or false
 */
bool_t lVectorIncrease(lVector vector)
{
    size_t space = vector->space;

#ifndef LVECTOR_ORIGINAL_SPACE  
#   define LVECTOR_ORIGINAL_SPACE 16
    if(space == 0) // vector has no memory
    {
        space = LVECTOR_ORIGINAL_SPACE;
    }
#   undef LVECTOR_ORIGINAL_SPACE
#endif
    else
    {
        /* Let space double while space < 1024 or let it increase 1024 */
        space = space < 1024 ? 2 * space : space + 1024;
    }
    
    /* Reallocate memory of vector->data */
    ptr_t data = realloc(vector->data ,space * vector->size);
    if(data == nullptr)
    {
        return false;
    }
	vector->data = data;
    vector->space = space;
    return true;
}



/*
 * USE    : Reduce space of vector to used
 *
 * PARAM  : vector - lVector you want to reduce
 *
 * RETURN : void
 */
void lVectorReduce(lVector vector)
{
    vector->data = realloc(vector->data,vector->used);
    // I think it's impossible to failed while reduce memory by realloc
    vector->space = vector->used;
} 



/*
 * USE    : Return length of vector
 *
 * PARAM  : vector - whose length you want 
 *
 * RETURN : length of vector
 */
size_t lVectorLength(lVector vector)
{
    return vector->used;
}



/*
 * USE    : Return space of vector
 *
 * PARAM  : vector - whose space you want
 *
 * RETURN : space of vector
 */
size_t lVectorSpace(lVector vector)
{
    return vector->space;
}



/*
 * USE    : Insert data after end
 *
 * PARAM  : vector - lVector to insert
 *          value  - value to insert
 *
 * RETURN : true of false
 */
bool_t lVectorPushBack(lVector vector, ptr_t value)
{
    if(vector->used < vector->space || lVectorIncrease(vector))
    {
        ptr_t site = vector->data + vector->used * vector->size;
        memcpy(site,value,vector->size);
        vector->used += 1;
        return true;
    }
    else
    {
        /* memory allocate faled */
        return false;
    }
}

 

/*
 * USE    : Remove the last data
 *
 * PARAM  : vector - lVector to remove data
 *
 * RETURN : true or false
 */
bool_t lVectorPopBack(lVector vector)
{
    if(vector->used > 0)
    {
        vector->used -= 1;
        return true;
    }
    else
    {
        /* vector is empty */
        return false;
    }

}



/* USE    : Insert data
 *
 * PARAM  : vector - lVector to insert
 *          site   - site of data , interval [0 , vector->used]
 *          value  - value of data
 *
 * RETURN : ture or false
 */
bool_t lVectorInsert(lVector vector, size_t site, ptr_t value)
{
    if(site > vector->used)
    {
        return false;
    }
    else if(vector->used < vector->space || lVectorIncrease(vector))
    {
        size_t size = (vector->used - site) * vector->size;
        ptr_t  src = vector->data + site * vector->size;
        ptr_t  dst = vector->data + (site + 1) * vector->size;
        memmove(dst,src,size);
        memcpy(src,value,vector->size);
        vector->used += 1;
        return true;
    }
    else
    {
        return false;
    }
}



/* USE    : Remove data
 *
 * PARAM  : vector - lVector to remove
 *          site   - site of data , interval [0 , vector->used)
 *
 * RETURN : true or false
 */
bool_t lVectorRemove(lVector vector, size_t site)
{
    if(site < vector->used)
    {
        size_t size = (vector->used - site) * vector->size;
        ptr_t  src = vector->data + (site + 1) * vector->size;
        ptr_t  dst = vector->data + site * vector->size;
        memmove(dst,src,size);
        vector->used -= 1;

        return true;
    }
    else
    {
        return false;
    }
}



/* USE    : Set value
 *
 * PARAM  : vector - lVector to set value
 *          site   - site of data , interval [0 , vector->used)
 *          value  - value of data
 *
 * RETURN : true or false
 */
bool_t lVectorSetValue(lVector vector, size_t site, ptr_t value)
{
    if(site >= vector->used)
    {
        return false;
    }
    else
    {
        ptr_t node = vector->data + vector->size * site;
        memcpy(node,value,vector->size);
        return true;
    }
}

/* USE    : Get value
 *
 * PARAM  : vector - lVector to get value
 *          site   - site of data , interval [0 , vector->used)
 *          value  - value of data
 *
 * RETURN : true or false
 */
bool_t lVectorGetValue(lVector vector, size_t site, ptr_t value)
{
    if(site >= vector->used)
    {
        return false;
    }
    else
    {
        ptr_t node = vector->data + vector->size * site;
        memcpy(value,node,vector->size);
        return true;
    }
}



/* USE    : Get pointer to a data
 *
 * PARAM  : vector - lVector to get
 *          site   - site of data , interval [0 , vector->used)
 */
ptr_t lVectorGetDataPointer(lVector vector,size_t site)
{
    if(site >= vector->used)
    {
        return false;
    }
    else
    {
        ptr_t node = vector->data + vector->size * site;
        return node;
    }
}