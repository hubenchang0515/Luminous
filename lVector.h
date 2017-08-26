/* lVector.h - Vector.
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

#include "lCore.h"

#ifdef __cplusplus 
	extern "C" {
#endif

typedef struct lVectorInfo* lVector;
typedef struct lVectorInfo lVectorInfo;

struct lVectorInfo
{
    size_t itemsize;  // size of one item
    size_t space;     // space of vector
    size_t used;      // length of used elements
    ptr_t  data;      // pointer to first data
};


/* for-each */
#ifndef lVectorForEach
#   define lVectorForEach(iter,vector) \
        for(ptr_t iter =  vector->data ; \
             iter < vector->data + vector->itemsize * vector->used; \
             iter += vector->itemsize)
#endif // lVectorForEach

/* Create vector */
lVector lVectorCreateBySize(size_t size);
#ifndef lVectorCreate
#   define lVectorCreate(T) lVectorCreateBySize(sizeof(T))
#endif //lVectorCreate

/* Delete vector */
void lVectorDelete(lVector vector);

/* Increase vector space */
bool_t lVectorIncrease(lVector vector);

/* Reduce vector space */
void lVectorReduce(lVector vector);

/* Length of vector */
size_t lVectorLength(lVector vector);

/* Space of vector */
size_t lVectorSpace(lVector vector);

/* Resize the space of vector */
bool_t lVectorResize(lVector vector, size_t space);

/* Insert data at end */
bool_t lVectorPushBack(lVector vector, ptr_t value);

/* Remove the last data */
bool_t lVectorPopBack(lVector vector);

/* Insert data */
bool_t lVectorInsert(lVector vector, size_t site, ptr_t value);

/* Remove data */
bool_t lVectorRemove(lVector vector, size_t site);

/* Set value */
bool_t lVectorSetValue(lVector vector, size_t site, ptr_t value);

/* Get value */
bool_t lVectorGetValue(lVector vector, size_t site, ptr_t value);

/* Get pointer to a data */
ptr_t lVectorGetDataPointer(lVector vector,size_t site);

#ifdef __cplusplus
    }
#endif

#endif // LUMINOUS_VECTOR_H