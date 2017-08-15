# lLisk
lList is a double-linked list.

## APIs Index
* [lListCreateBySize](#llistcreatebysize)  
* [lListDelete](#llistdelete)  
* [lListSetValue](#llistsetvalue)  
* [lListGetValue](#llistgetvalue)  
* [lListAfter](#llistafter)  
* [lListBefore](#llistbefore)  
* [lListInsertAfter](#llistinsertafter)  
* [lListInsertBefore](#llistinsertbefore)  
* [lListRemove](#llistremove)  
* [lListHead](#llisthead)
* [lListTail](#llisttail)
* [lListFindAfter](#llistfindafter)
* [lListFindBefore](#llistfindbefore)
* [lListCount](#llistcount)

## APIs
### lListCreateBySize
```C
/*
 * USE    : Create linked list
 *
 * PARAM  : datasize - size of node's data
 *
 * RETURN : head lListNode of list or nullptr
 */
lListNode* lListCreateBySize(size_t datasize);
```

### lListDelete
```C
/*
 * USE    : Delete linked list
 *
 * PARAM  : list - any lListNode of list
 *
 * RETURN : void
 */
void lListDelete(lListNode* list);
```

### lListSetValue
```C
/*
 * USE    : Set value of node
 *
 * PARAM  : node  - lListNode to set
 *          value - pointer to value to set
 *
 * RETURN : void
 */
void lListSetValue(lListNode* node, ptr_t value);
```

### lListGetValue
```C
/*
 * USE    : Get value of node
 *
 * PARAM  : node  - lListNode to get
 *          value - pointer to return value
 *
 * RETURN : void
 */
void lListGetValue(lListNode* node, ptr_t value);
```

### lListAfter
```C
/*
 * USE    : Get a lListNode after node
 *
 * PARAM  : node     - after this lListNode
 *          distance - distance to node
 *
 * RETURN : lListNode we want or nullptr
 */
lListNode* lListAfter(lListNode* node, size_t distance);
```

### lListBefore
```C
/*
 * USE    : Get a lListNode before node
 *
 * PARAM  : node     - before lListNode
 *          distance - distance to node
 *
 * RETURN : lListNode we want or nullptr
 */
lListNode* lListBefore(lListNode* node, size_t distance);
```

### lListInsertAfter
```C
/* USE    : Insert a lListNode after node 
 *
 * PARAM  : node - after this lListNode
 *
 * RETURN : lListNode inserted or nullptr
 */
lListNode* lListInsertAfter(lListNode* node);
```

### lListInsertBefore
```C
/* USE    : Insert a lListNode before node 
 *
 * PARAM  : node - before this lListNode
 *
 * RETURN : lListNode inserted or nullptr
 */
lListNode* lListInsertBefore(lListNode* node);
```

### lListRemove
```C
/* USE    : Remove node 
 *
 * PARAM  : node - lListNode to remove
 *
 * RETURN : void
 */
void lListRemove(lListNode* node);
```

### lListHead
```C
/* USE    : Head of list 
 *
 * PARAM  : node - any lListNode of list
 *
 * RETURN : Head lListNode of list
 */
lListNode* lListHead(lListNode* node);
```

### lListTail
```C
/* USE    : Tail of list
 *
 * PARAM  : node - any lListNode of list
 *
 * RETURN : Tail lListNode of list
 */
lListNode* lListTail(lListNode* node);
```

### lListFindAfter
```C
/* USE    : Find a lListNode after node
 * 
 * PARAM  : node   - after this lListNode
 *          value  - pointer to value
 *          ordinal - ordinal number 
 *
 * RETURN : number ordinal lListNode, whose data equals to value, 
 *          after node(inclusive) , or nullptr 
 */

lListNode* lListFindAfter(lListNode* node, ptr_t value, size_t ordinal);
```

### lListFindBefore
```C
/* USE    : Find a lListNode before node
 * 
 * PARAM  : node   - before this lListNode
 *          value  - pointer to value
 *          ordinal - ordinal number 
 *
 * RETURN : number ordinal lListNode, whose data equals to value, 
 *          before node(inclusive) , or nullptr 
 */
lListNode* lListFindBefore(lListNode* node, ptr_t value, size_t ordinal);
```

### lListCount
```C
/* USE    : lListNode number of list
 *
 * PARAM  : any lListNode of list
 *
 * RETURN : lListNode number of list
 */
size_t lListCount(lListNode* node);
```
