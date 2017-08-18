# lVector
lVector is an array can be changed length.

## Types
```C
typedef struct lVectorInfo* lVector;

struct lVectorInfo
{
    size_t datasize;  // size of one data
    size_t length;    // length of vector
    size_t used;      // length of used elements
    ptr_t  data;      // pointer to first data
};
```

## APIs index

### Macro Difinitions
* [lVectorForEach](#lvectorforeach)
* [lVectorCreate](#lvectorcreatebysize)

### Functions
* [lVectorCreateBySize](#lvectorcreatebysize)
* [lVectorDelete](#lvectordelete)
* [lVectorIncrease](#lvectorincrease)

## Demo

## APIs

#### lVectorCreateBySize
```C
/*
 * USE    : Create lVector by size of data
 *
 * PARAM  : size - size of data
 *
 * RETURN : lVector or nullptr
 */
lVector lVectorCreateBySize(size_t size);
```

#### lVectorDelete
```C
/*
 * USE    : Delete Vector
 *
 * PARAM  : vector - lVector to delete
 *
 * RETURN : void
 */
void lVectorDelete(lVector vector);
```


#### lVectorIncrease
```C
/*
 * USE    : Increase length of vector
 *
 * PARAM  : vector - lVector you want to increase
 *
 * RETURN : true or false
 */
bool_t lVectorIncrease(lVector vector);
```