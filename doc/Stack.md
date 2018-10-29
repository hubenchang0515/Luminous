# Stack
Stack is a stack made by Vector.

## Types
```C
typedef Vector Stack;
```

## APIs index

### Macro Difinitions
* [stackCreate](#stackcreate)

### Functions
* [stackCreateBySize](#stackcreatebysize)
* [stackDelete](#stackdelete)
* [stackClear](#stackclear)
* [stackIsEmpty](#stackisempty)
* [stackPush](#stackpush)
* [stackPop](#stackpop)
* [stackGetTop](#stackgettop)
* [stackSetTop](#stacksettop)
* [stackCount](#stackcount)

## Demo
```C
#include <stdio.h>
#include <string.h>
#include "stack.h"

int main()
{
	Stack stack = stackCreate(char[64]);
	char str[64] = "Luminous";
	stackPush(stack,str);
	strncpy(str,"hubenchang0515",64);
	stackPush(stack,str);
	strncpy(str,"com",64);
	stackPush(stack,str);
	strncpy(str,"github",64);
	stackPush(stack,str);
	
	printf("%lu\n",stackCount(stack));
	
	while(stackPop(stack,str))
	{
		printf("%s\n",str);
	}
	
	printf("%lu\n",stackCount(stack));

    stackDelete(stack);

    return 0;
}
```

## APIs
**WARNING** : Following content has name error  , because of refactoring

### stackCreateBySize
```C
/* USE    : Create a stack by size of stack frame
 *
 * PARAM  : size - size of stack frame
 *
 * RETURN : new stack or nullptr
 */
stack stackCreateBySize(size_t size);
```

### stackCreate
```C
/*
 * USE    : Create stack
 *
 * PARAM  : T - type of data
 *
 * RETURN : stack or nullptr
 */
#define stackCreate(T) stackCreateBySize(sizeof(T))
```

### stackDelete
```C
/* USE    : Delete stack
 *
 * PARAM  : stack - stack to delete
 *
 * RETURN : void
 */
void stackDelete(stack stack);
```

### stackClear
```C
/* USE    : Clear all data
 * 
 * PARAM  : stack - stack to clear
 *
 * RETURN : void
 */
void stackClear(stack stack);
```

### stackIsEmpty
```C
/* USE    : Check if empty
 *
 * PARAM  : stack - stack to check
 *
 * RETURN : true or false
 */
bool_t stackIsEmpty(stack stack);
```

### stackPush
```C
/* USE    : Push a stack frame into stack
 *
 * PARAM  : stack - stack to push
 *          value - value to push
 *
 * return : true or false
 */
bool_t stackPush(stack stack, ptr_t value);
```

### stackPop
```C
/* USE    : Pop a frame from stack
 *
 * PARAM  : stack - stack to pop
 *          value - store the return value
 *
 * return : true or false
 */
bool_t stackPop(stack stack, ptr_t value);
```

### stackGetTop
```C
/* USE    : Get value of top but not remove it
 *
 * PARAM  : stack - stack to pop
 *          value - store the return value
 *
 * return : true or false
 */
bool_t stackGetTop(stack stack, ptr_t value);
```

### stackSetTop
```C
/* USE    : Set value of top rather than push
 * PARAM  : stack - stack to pop
 *          value - store the return value
 *
 * return : true or false
 */
bool_t stackSetTop(stack stack, ptr_t value);
```

### stackCount
```C
/* USE    : Return stack frame count of stack
 *
 * PARAM  : stack - stack to get count
 *
 * RETURN : stack frame count of stack
 */
size_t stackCount(stack stack);
```