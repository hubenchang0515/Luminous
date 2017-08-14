#include "LinkedList.h"

#include <malloc.h>
#include <string.h>
//#include <stddef.h>

unsigned int Luminous_LinkedList_Length(Luminous_LinkedList *linkedList)
{
	Luminous_LinkedList_Node *node = linkedList->firstNode;

	unsigned int length = 0;

	while(node!=NULL)
	{
		length++;

		node = node->nextNode;
	}

	return length;
}

Luminous_LinkedList_Node *Luminous_LinkedList_EndNode(Luminous_LinkedList *linkedList)
{
	Luminous_LinkedList_Node *node = linkedList->firstNode;

	Luminous_LinkedList_Node *endNode = NULL;
	while (node != NULL)
	{
		endNode = node;
		node = node->nextNode;
	}

	return endNode;
}

void Luminous_LinkedList_ForEach(Luminous_LinkedList *linkedList, void(function)(Luminous_LinkedList_Node*))
{
	Luminous_LinkedList_Node *node = linkedList->firstNode;

	while (node != NULL)
	{

		function(node);

		node = node->nextNode;
	}

}

void Luminous_LinkedList_PushFront(Luminous_LinkedList *linkedList, void *addValue)
{
	Luminous_LinkedList_Node *node = malloc(sizeof(Luminous_LinkedList_Node));
	node->value = malloc(linkedList->nodeValueTypeSize);
	memcpy(node->value, addValue, linkedList->nodeValueTypeSize);

	node->nextNode = linkedList->firstNode;
	linkedList->firstNode = node;

}

void *Luminous_LinkedList_PopFront(Luminous_LinkedList *linkedList)
{
	void *returnvalue= malloc(linkedList->nodeValueTypeSize);
	memcpy(returnvalue, linkedList->firstNode->value, linkedList->nodeValueTypeSize);

	free(linkedList->firstNode->value);
	linkedList->firstNode->value = NULL;
	Luminous_LinkedList_Node *newFirstNode=linkedList->firstNode->nextNode;
	free(linkedList->firstNode);
	linkedList->firstNode = NULL;
	linkedList->firstNode = newFirstNode;

	return returnvalue;
}

void Luminous_LinkedList_PushBack(Luminous_LinkedList *linkedList, void *addValue)
{
	Luminous_LinkedList_Node *node = linkedList->firstNode;

	Luminous_LinkedList_Node *endNode = node;
	while (node != NULL)
	{
		endNode = node;
		node = node->nextNode;
	}

	Luminous_LinkedList_Node *addNode = malloc(sizeof(Luminous_LinkedList_Node));
	addNode->value = malloc(linkedList->nodeValueTypeSize);
	memcpy(addNode->value, addValue, linkedList->nodeValueTypeSize);

	addNode->nextNode = NULL;
	if (endNode == NULL)
	{
		linkedList->firstNode = addNode;
	}
	else
	{
		endNode->nextNode = addNode;
	}
	

}

void *Luminous_LinkedList_PopBack(Luminous_LinkedList *linkedList)
{
	Luminous_LinkedList_Node *node = linkedList->firstNode;
	Luminous_LinkedList_Node *newEndNode = NULL;
	Luminous_LinkedList_Node *endNode = NULL;
	while (node != NULL)
	{
		newEndNode = endNode;
		endNode = node;
		node = node->nextNode;
	}

	void *returnvalue = malloc(linkedList->nodeValueTypeSize);
	memcpy(returnvalue, endNode->value, linkedList->nodeValueTypeSize);

	free(endNode->value);
	endNode->value = NULL;
	free(endNode);
	endNode = NULL;
	newEndNode->nextNode = NULL;

	return returnvalue;
}

void Luminous_LinkedList_Clear(Luminous_LinkedList *linkedList)
{
	Luminous_LinkedList_Node *node = linkedList->firstNode;
	Luminous_LinkedList_Node *newFirstNode = NULL;
	while (node != NULL)
	{
		free(node->value);
		node->value = NULL;
		newFirstNode = node->nextNode;
		free(node);
		node = NULL;
		node = newFirstNode;
	}

}

void Luminous_LinkedList_BackwardSequence(Luminous_LinkedList *linkedList)
{
	Luminous_LinkedList_Node *node = linkedList->firstNode;
	Luminous_LinkedList_Node *oldNode = NULL;
	Luminous_LinkedList_Node *newNode = NULL;
	while (node != NULL)
	{
		newNode = node->nextNode;
		node->nextNode=oldNode;
		oldNode = node;

		node = newNode;
	}

	linkedList->firstNode = node;
}

void Luminous_LinkedList_LinkFront(Luminous_LinkedList *linkedList, Luminous_LinkedList *front)
{
	Luminous_LinkedList *result = malloc(sizeof(Luminous_LinkedList));
	result->nodeValueTypeSize = linkedList->nodeValueTypeSize;
	result->firstNode = NULL;

	Luminous_LinkedList_Node *sourceNode = linkedList->firstNode;

	Luminous_LinkedList_Node *newNode = NULL;
	Luminous_LinkedList_Node *endNode = NULL;
	while (sourceNode != NULL)
	{
		newNode = malloc(sizeof(Luminous_LinkedList_Node));
		newNode->value = malloc(linkedList->nodeValueTypeSize);
		memcpy(newNode->value, sourceNode->value, linkedList->nodeValueTypeSize);
		newNode->nextNode = NULL;

		if (result->firstNode == NULL)
		{
			result->firstNode = newNode;
		}
		else
		{
			endNode->nextNode = newNode;
		}
		endNode = newNode;

		sourceNode = sourceNode->nextNode;
	}

	endNode->nextNode = linkedList->firstNode;
	linkedList->firstNode = result->firstNode;

}

void Luminous_LinkedList_LinkBack(Luminous_LinkedList *linkedList, Luminous_LinkedList *back)
{
	Luminous_LinkedList_Node *node = linkedList->firstNode;
	
	Luminous_LinkedList_Node *endNode = NULL;
	while (node != NULL)
	{
		endNode = node;
		node = node->nextNode;
	}

	Luminous_LinkedList_Node *pushNode = back->firstNode;

	Luminous_LinkedList_Node *addNode;
	while (pushNode != NULL)
	{
		addNode = malloc(sizeof(Luminous_LinkedList_Node));
		addNode->value = malloc(linkedList->nodeValueTypeSize);
		memcpy(addNode->value, pushNode->value, linkedList->nodeValueTypeSize);
		addNode->nextNode = NULL;
		endNode->nextNode = addNode;

		endNode = addNode;
		pushNode = pushNode->nextNode;
	}

	
	

	addNode->nextNode = NULL;
	endNode->nextNode = addNode;

	endNode->nextNode = back->firstNode;
}

Luminous_LinkedList *Luminous_LinkedList_Copy(Luminous_LinkedList *linkedList)
{
	Luminous_LinkedList *result = malloc(sizeof(Luminous_LinkedList));
	result->nodeValueTypeSize = linkedList->nodeValueTypeSize;
	result->firstNode = NULL;

	Luminous_LinkedList_Node *sourceNode = linkedList->firstNode;
	
	Luminous_LinkedList_Node *newNode = NULL;
	Luminous_LinkedList_Node *endNode = NULL;
	while (sourceNode != NULL)
	{
		newNode = malloc(sizeof(Luminous_LinkedList_Node));
		newNode->value = malloc(linkedList->nodeValueTypeSize);
		memcpy(newNode->value, sourceNode->value, linkedList->nodeValueTypeSize);
		newNode->nextNode = NULL;

		if (result->firstNode == NULL)
		{
			result->firstNode = newNode;		
		}
		else
		{
			endNode->nextNode = newNode;
		}
		endNode = newNode;

		sourceNode = sourceNode->nextNode;
	}

	return result;
}