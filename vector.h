/* Vector.h - Vector.
** https://github.com/hubenchang0515/Luminous
**
** Copyright (C) 2017 hubenchang0515
** Date    : 2017-8-17
** E-mail  : hubenchang0515@outlook.com
** Blog    : blog.kurukurumi.com
** LISENCE : LGPL v3.0
*/

#ifndef LUMINOUS_VECTOR_H
#define LUMINOUS_VECTOR_H

#include "core.h"

#ifdef __cplusplus 
	extern "C" {
#endif

typedef struct VectorInfo* Vector;
typedef struct VectorInfo VectorInfo;

struct VectorInfo
{
    size_t itemsize;  // size of one item
    size_t space;     // space of vector
    size_t used;      // length of used elements
    ptr_t  data;      // pointer to first data
};


/* for-each */
#ifndef VectorForEach
#   define VectorForEach(iter,vector) \
        for(ptr_t iter =  vector->data ; \
             iter < vector->data + vector->itemsize * vector->used; \
             iter += vector->itemsize)
#endif // lVectorForEach

/* Create vector */
Vector vectorCreateBySize(size_t size);
#ifndef vectorCreate
#   define vectorCreate(T) vectorCreateBySize(sizeof(T))
#endif //vectorCreate

/* Delete vector */
void vectorDelete(Vector vector);

/* Increase vector space */
bool_t vectorIncrease(Vector vector);

/* Reduce vector space */
void vectorReduce(Vector vector);

/* Length of vector */
size_t vectorLength(Vector vector);

/* Check if empty */
bool_t vectorIsEmpty(Vector vector);

/* Space of vector */
size_t vectorSpace(Vector vector);

/* Resize the space of vector */
bool_t vectorResize(Vector vector, size_t space);

/* Insert data at end */
bool_t vectorPushBack(Vector vector, ptr_t value);

/* Remove the last data */
bool_t vectorPopBack(Vector vector);

/* Insert data */
bool_t vectorInsert(Vector vector, size_t site, ptr_t value);

/* Remove data */
bool_t vectorRemove(Vector vector, size_t site);

/* Remove all data */
void vectorClear(Vector vector);

/* Set value */
bool_t vectorSetValue(Vector vector, size_t site, ptr_t value);

/* Get value */
bool_t vectorGetValue(Vector vector, size_t site, ptr_t value);

/* Get pointer to a data */
ptr_t vectorGetDataPointer(Vector vector,size_t site);

#ifdef __cplusplus
    }
#endif

#endif // LUMINOUS_VECTOR_H