#pragma once

#define CreateLinkedList(TypeName,linkedList) Luminous_LinkedList linkedList; linkedList.nodeValueTypeSize=sizeof(TypeName);

struct Luminous_LinkedList_Node {
	void* value;
	struct Luminous_LinkedList_Node* nextNode;
} ;

struct Luminous_LinkedList {
	unsigned int nodeValueTypeSize;
	struct Luminous_LinkedList_Node* firstNode;
} ;


typedef struct Luminous_LinkedList_Node Luminous_LinkedList_Node;
typedef struct Luminous_LinkedList Luminous_LinkedList;


unsigned int Luminous_LinkedList_Length(Luminous_LinkedList *linkedList);
Luminous_LinkedList_Node *Luminous_LinkedList_EndNode(Luminous_LinkedList *linkedList);
void Luminous_LinkedList_ForEach(Luminous_LinkedList *linkedList, void(function)(Luminous_LinkedList_Node*));
void Luminous_LinkedList_PushFront(Luminous_LinkedList *linkedList, void *addValue);
void *Luminous_LinkedList_PopFront(Luminous_LinkedList *linkedList);
void Luminous_LinkedList_PushBack(Luminous_LinkedList *linkedList, void *addValue);
void *Luminous_LinkedList_PopBack(Luminous_LinkedList *linkedList);
void Luminous_LinkedList_Clear(Luminous_LinkedList *linkedList);
void Luminous_LinkedList_BackwardSequence(Luminous_LinkedList *linkedList);
void Luminous_LinkedList_LinkFront(Luminous_LinkedList *linkedList, Luminous_LinkedList *front);
void Luminous_LinkedList_LinkBack(Luminous_LinkedList *linkedList, Luminous_LinkedList *back);
Luminous_LinkedList *Luminous_LinkedList_Copy(Luminous_LinkedList *linkedList);