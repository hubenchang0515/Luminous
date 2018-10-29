/* Stack.h - stack
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

#include "core.h"
#include "vector.h"

#ifdef __cplusplus 
	extern "C" {
#endif

typedef Vector Stack;

/* Create Stack */
Stack stackCreateBySize(size_t size);
#ifndef stackCreate
#   define stackCreate(T) stackCreateBySize(sizeof(T))
#endif //stackCreate

/* Delete Stack */
void stackDelete(Stack stack);

/* Clear all data */
void stackClear(Stack stack);

/* Check if empty */
bool_t stackIsEmpty(Stack stack);

/* Push a frame into stack */
bool_t stackPush(Stack stack, ptr_t value);

/* Pop a frame from stack */
bool_t stackPop(Stack stack, ptr_t value);

/* Get value of top but not remove it */
bool_t stackGetTop(Stack stack, ptr_t value);

/* Set value of top */
bool_t stackSetTop(Stack stack, ptr_t value);

/* stack frame count of stack */
size_t stackCount(Stack stack);

#ifdef __cplusplus
    }
#endif

#endif