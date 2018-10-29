/* Vector.h - Vector.
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
#include "vector.h"

/*
 * USE    : Create Vector by size of data
 *
 * PARAM  : size - size of data
 *
 * RETURN : Vector or nullptr
 */
Vector vectorCreateBySize(size_t size)
{
    Vector vector = (Vector)malloc(sizeof(VectorInfo));
    if(vector == nullptr)
    {
        return nullptr;
    }

    vector->space = 0;
    vector->used = 0;
    vector->itemsize = size;
    vector->data = nullptr;

    return vector;
}



/*
 * USE    : Delete Vector
 *
 * PARAM  : vector - Vector to delete
 *
 * RETURN : void
 */
void vectorDelete(Vector vector)
{
    free(vector->data);
    free(vector);
}



/*
 * USE    : Increase space of vector
 *
 * PARAM  : vector - Vector you want to increase
 *
 * RETURN : true or false
 */
bool_t vectorIncrease(Vector vector)
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
    ptr_t data = realloc(vector->data ,space * vector->itemsize);
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
 * PARAM  : vector - Vector you want to reduce
 *
 * RETURN : void
 */
void vectorReduce(Vector vector)
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
size_t vectorLength(Vector vector)
{
    return vector->used;
}



/* USE    : Check if empty
 *
 * PARAM  : vector - Vector to check if empty
 *
 * RETURN : true or false
 */
bool_t vectorIsEmpty(Vector vector)
{
    return vector->used == 0;
}



/*
 * USE    : Return space of vector
 *
 * PARAM  : vector - whose space you want
 *
 * RETURN : space of vector
 */
size_t vectorSpace(Vector vector)
{
    return vector->space;
}



/* 
 * USE    : Resize the space of vector
 *
 * PARAM  : vector - Vector to resize space
 *          space  - the new space
 *
 * RETURN : true or false
 */
bool_t vectorResize(Vector vector, size_t space)
{
    ptr_t data = realloc(vector->data ,space * vector->itemsize);
    if(data == nullptr)
    {
        return false;
    }
    if(space < vector->used)
    {
        vector->used = space;
    }
	vector->data = data;
    vector->space = space;
    return true;
}



/*
 * USE    : Insert data after end
 *
 * PARAM  : vector - Vector to insert
 *          value  - value to insert
 *
 * RETURN : true of false
 */
bool_t vectorPushBack(Vector vector, ptr_t value)
{
    if(vector->used < vector->space || vectorIncrease(vector))
    {
        ptr_t site = vector->data + vector->used * vector->itemsize;
        memcpy(site,value,vector->itemsize);
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
 * PARAM  : vector - Vector to remove data
 *
 * RETURN : true or false
 */
bool_t vectorPopBack(Vector vector)
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
 * PARAM  : vector - Vector to insert
 *          site   - site of data , interval [0 , vector->used]
 *          value  - value of data
 *
 * RETURN : ture or false
 */
bool_t vectorInsert(Vector vector, size_t site, ptr_t value)
{
    if(site > vector->used)
    {
        return false;
    }
    else if(vector->used < vector->space || vectorIncrease(vector))
    {
        size_t size = (vector->used - site) * vector->itemsize;
        ptr_t  src = vector->data + site * vector->itemsize;
        ptr_t  dst = vector->data + (site + 1) * vector->itemsize;
        memmove(dst,src,size);
        memcpy(src,value,vector->itemsize);
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
 * PARAM  : vector - Vector to remove
 *          site   - site of data , interval [0 , vector->used)
 *
 * RETURN : true or false
 */
bool_t vectorRemove(Vector vector, size_t site)
{
    if(site < vector->used)
    {
        size_t size = (vector->used - site) * vector->itemsize;
        ptr_t  src = vector->data + (site + 1) * vector->itemsize;
        ptr_t  dst = vector->data + site * vector->itemsize;
        memmove(dst,src,size);
        vector->used -= 1;

        return true;
    }
    else
    {
        return false;
    }
}



/* USE    : Remove all data
 *
 * PARAM  : vector - Vector to clear
 *
 * RETURN : void
 */
void vectorClear(Vector vector)
{
    vector->used = 0;
}



/* USE    : Set value
 *
 * PARAM  : vector - Vector to set value
 *          site   - site of data , interval [0 , vector->used)
 *          value  - value of data
 *
 * RETURN : true or false
 */
bool_t vectorSetValue(Vector vector, size_t site, ptr_t value)
{
    if(site >= vector->used)
    {
        return false;
    }
    else
    {
        ptr_t node = vector->data + vector->itemsize * site;
        memcpy(node,value,vector->itemsize);
        return true;
    }
}

/* USE    : Get value
 *
 * PARAM  : vector - Vector to get value
 *          site   - site of data , interval [0 , vector->used)
 *          value  - value of data
 *
 * RETURN : true or false
 */
bool_t vectorGetValue(Vector vector, size_t site, ptr_t value)
{
    if(site >= vector->used)
    {
        return false;
    }
    else
    {
        ptr_t node = vector->data + vector->itemsize * site;
        memcpy(value,node,vector->itemsize);
        return true;
    }
}



/* USE    : Get pointer to a data
 *
 * PARAM  : vector - Vector to get
 *          site   - site of data , interval [0 , vector->used)
 *
 * RETURN : ptr_t to a data or nullptr
 */
ptr_t vectorGetDataPointer(Vector vector,size_t site)
{
    if(site >= vector->used)
    {
        return nullptr;
    }
    else
    {
        ptr_t node = vector->data + vector->itemsize * site;
        return node;
    }
}