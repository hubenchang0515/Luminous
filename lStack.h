/* lStack.h - stack
** https://github.com/hubenchang0515/Luminous
**
** Copyright (C) 2017 hubenchang0515
** Date    : 2017-8-29
** E-mail  : hubenchang0515@outlook.com
** Blog    : blog.kurukurumi.com
** LISENCE : LGPL v3.0
*/

#ifndef LUMINOUS_STACK_H
#define LUMINOUS_STACK_H

#include "lCore.h"
#include "lVector.h"

#ifdef __cplusplus 
	extern "C" {
#endif

typedef lVector lStack;

/* Create lStack */
lStack lStackCreateBySize(size_t size);
#ifndef lStackCreate
#   define lStackCreate(T) lStackCreateBySize(sizeof(T))
#endif //lStackCreate

/* Delete lStack */
void lStackDelete(lStack stack);

/* Push a frame into stack */
bool_t lStackPush(lStack stack, ptr_t value);

/* Pop a frame from stack */
bool_t lStackPop(lStack stack, ptr_t value);

/* Get value of top but not remove it */
bool_t lStackGetTop(lStack stack, ptr_t value);

/* Set value of top */
bool_t lStackSetTop(lStack stack, ptr_t value);

/* stack frame count of stack */
size_t lStackCount(lStack stack);

#ifdef __cplusplus
    }
#endif

#endif