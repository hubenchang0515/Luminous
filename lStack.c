/* lStack.c - stack
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
#include "lVector.h"
#include "lStack.h"


/* USE    : Create a lStack by size of stack frame
 *
 * PARAM  : size - size of stack frame
 *
 * RETURN : new lStack or nullptr
 */
lStack lStackCreateBySize(size_t size)
{
    return lVectorCreateBySize(size);
}



/* USE    : Delete stack
 *
 * PARAM  : stack - lStack to delete
 *
 * RETURN : void
 */
void lStackDelete(lStack stack)
{
    lVectorDelete(stack);
}



/* USE    : Push a stack frame into stack
 *
 * PARAM  : stack - lStack to push
 *          value - value to push
 *
 * return : true or false
 */
bool_t lStackPush(lStack stack, ptr_t value)
{
    return lVectorPushBack(stack, value);
}



/* USE    : Pop a frame from stack
 *
 * PARAM  : stack - lStack to pop
 *          value - store the return value
 *
 * return : true or false
 */
bool_t lStackPop(lStack stack, ptr_t value)
{
    return lVectorGetValue(stack, lVectorLength(stack) - 1, value) &&
            lVectorPopBack(stack);
}



/* USE    : Return stack frame count of stack
 *
 * PARAM  : stack - stack to get count
 *
 * RETURN : stack frame count of stack
 */
size_t lStackCount(lStack stack)
{
    return lVectorLength(stack);
}
