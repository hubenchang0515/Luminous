# lLisk
lList is a double-linked list.

## APIs
```C
/*
 * USE    : Create linked list
 *
 * PARAM  : datasize - size of node's data
 *
 * RETURN : pointer to header of linked list or nullptr
 */
lListNode* lListCreateBySize(size_t datasize);



/*
 * USE    : Delete linked list
 *
 * PARAM  : list - any node of linked list
 *
 * RETURN : void
 */
void lListDelete(lListNode* list);



/*
 * USE    : Set value of node
 *
 * PARAM  : node  - node to set
 *          value - pointer to value to set
 *
 * RETURN : void
 */
void lListSetValue(lListNode* node, ptr_t value);



/*
 * USE    : Get value of node
 *
 * PARAM  : node  - node to get
 *          value - pointer to return value
 *
 * RETURN : void
 */
void lListGetValue(lListNode* node, ptr_t value);



/*
 * USE    : Get a lListNode after node
 *
 * PARAM  : node     - current node
 *          distance - distance to current node
 *
 * RETURN : lListNode we want or nullptr
 */
lListNode* lListAfter(lListNode* node, size_t distance);



/*
 * USE    : Get a lListNode before node
 *
 * PARAM  : node     - current node
 *          distance - distance to current node
 *
 * RETURN : lListNode we want or nullptr
 */
lListNode* lListBefore(lListNode* node, size_t distance);



/* USE    : Insert a lListNode after node 
 *
 * PARAM  : node - current node
 *
 * RETURN : lListNode inserted or nullptr
 */
lListNode* lListInsterAfter(lListNode* node);



/* USE    : Insert a lListNode before node 
 *
 * PARAM  : node - current node
 *
 * RETURN : lListNode inserted or nullptr
 */
lListNode* lListInsterBefore(lListNode* node);



/* USE    : Remove node 
 *
 * PARAM  : node - lListNode to remove
 *
 * RETURN : void
 */
void lListRemove(lListNode* node);
```
