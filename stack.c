/* Stack.c - stack
** https://github.com/hubenchang0515/Luminous
**
** Copyright (C) 2017 hubenchang0515
** Date    : 2017-8-29
** E-mail  : hubenchang0515@outlook.com
** Blog    : blog.kurukurumi.com
** LISENCE : LGPL v3.0
*/

#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "stack.h"


/* USE    : Create a Stack by size of stack frame
 *
 * PARAM  : size - size of stack frame
 *
 * RETURN : new Stack or nullptr
 */
Stack stackCreateBySize(size_t size)
{
    return vectorCreateBySize(size);
}



/* USE    : Delete stack
 *
 * PARAM  : stack - Stack to delete
 *
 * RETURN : void
 */
void stackDelete(Stack stack)
{
    vectorDelete(stack);
}



/* USE    : Clear all data
 * 
 * PARAM  : stack - Stack to clear
 *
 * RETURN : void
 */
void stackClear(Stack stack)
{
    vectorClear(stack);
}



/* USE    : Check if empty
 *
 * PARAM  : stack - Stack to check
 *
 * RETURN : true or false
 */
bool_t stackIsEmpty(Stack stack)
{
    return vectorIsEmpty(stack);
}



/* USE    : Push a stack frame into stack
 *
 * PARAM  : stack - Stack to push
 *          value - value to push
 *
 * return : true or false
 */
bool_t stackPush(Stack stack, ptr_t value)
{
    return vectorPushBack(stack, value);
}



/* USE    : Pop a frame from stack
 *
 * PARAM  : stack - Stack to pop
 *          value - store the return value
 *
 * return : true or false
 */
bool_t stackPop(Stack stack, ptr_t value)
{
    return vectorGetValue(stack, vectorLength(stack) - 1, value) &&
            vectorPopBack(stack);
}



/* USE    : Get value of top but not remove it
 *
 * PARAM  : stack - Stack to pop
 *          value - store the return value
 *
 * return : true or false
 */
bool_t stackGetTop(Stack stack, ptr_t value)
{
    return vectorGetValue(stack,vectorLength(stack) - 1, value);
}



/* USE    : Set value of top rather than push
 * PARAM  : stack - Stack to pop
 *          value - store the return value
 *
 * return : true or false
 */
bool_t stackSetTop(Stack stack, ptr_t value)
{
    return vectorSetValue(stack, vectorLength(stack) - 1, value);
}



/* USE    : Return stack frame count of stack
 *
 * PARAM  : stack - stack to get count
 *
 * RETURN : stack frame count of stack
 */
size_t stackCount(Stack stack)
{
    return vectorLength(stack);
}
