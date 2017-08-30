# lStack
lStack is a stack made by lVector.

## Types
```C
typedef lVector lStack;
```

## APIs index

### Macro Difinitions
* [lStackCreate](#lstackcreate)

### Functions
* [lStackCreateBySize](#lstackcreatebysize)
* [lStackDelete](#lstackdelete)
* [lStackPush](#lstackpush)
* [lStackPop](#lstackpop)
* [lStackGetTop](#lstackgettop)
* [lStackSetTop](#lstacksettop)
* [lStackCount](#lstackcount)

## Demo
```C
#include <stdio.h>
#include <string.h>
#include "lStack.h"

int main()
{
	lStack stack = lStackCreate(char[64]);
	char str[64] = "Luminous";
	lStackPush(stack,str);
	strncpy(str,"hubenchang0515",64);
	lStackPush(stack,str);
	strncpy(str,"com",64);
	lStackPush(stack,str);
	strncpy(str,"github",64);
	lStackPush(stack,str);
	
	printf("%lu\n",lStackCount(stack));
	
	while(lStackPop(stack,str))
	{
		printf("%s\n",str);
	}
	
	printf("%lu\n",lStackCount(stack));

    lStackDelete(stack);

    return 0;
}
```

## APIs

### lStackCreateBySize
```C
/* USE    : Create a lStack by size of stack frame
 *
 * PARAM  : size - size of stack frame
 *
 * RETURN : new lStack or nullptr
 */
lStack lStackCreateBySize(size_t size);
```

### lStackCreate
```C
/*
 * USE    : Create lStack
 *
 * PARAM  : T - type of data
 *
 * RETURN : lStack or nullptr
 */
#define lStackCreate(T) lStackCreateBySize(sizeof(T))
```

### lStackDelete
```C
/* USE    : Delete stack
 *
 * PARAM  : stack - lStack to delete
 *
 * RETURN : void
 */
void lStackDelete(lStack stack);
```

### lStackPush
```C
/* USE    : Push a stack frame into stack
 *
 * PARAM  : stack - lStack to push
 *          value - value to push
 *
 * return : true or false
 */
bool_t lStackPush(lStack stack, ptr_t value);
```

### lStackPop
```C
/* USE    : Pop a frame from stack
 *
 * PARAM  : stack - lStack to pop
 *          value - store the return value
 *
 * return : true or false
 */
bool_t lStackPop(lStack stack, ptr_t value);
```

### lStackGetTop
```C
/* USE    : Get value of top but not remove it
 *
 * PARAM  : stack - lStack to pop
 *          value - store the return value
 *
 * return : true or false
 */
bool_t lStackGetTop(lStack stack, ptr_t value);
```

### lStackSetTop
```C
/* USE    : Set value of top rather than push
 * PARAM  : stack - lStack to pop
 *          value - store the return value
 *
 * return : true or false
 */
bool_t lStackSetTop(lStack stack, ptr_t value);
```

### lStackCount
```C
/* USE    : Return stack frame count of stack
 *
 * PARAM  : stack - stack to get count
 *
 * RETURN : stack frame count of stack
 */
size_t lStackCount(lStack stack);
```