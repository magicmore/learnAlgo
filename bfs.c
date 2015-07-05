#include "bfs.h"

#define NODE_SUM 8
LIST pic[NODE_SUM];
PIC_NODE picture[NODE_SUM];

void appendToAList(LIST *vetexList, int data)
{
	LIST_NODE *pTemp = vetexList->root;
	LIST_NODE *newNode = (LIST_NODE*) malloc(sizeof(LIST_NODE));
	newNode->value = data;
	newNode->next = NULL;
	if(NULL == pTemp)
	{
		vetexList->root = newNode;
	}
	else
	{
		LIST_NODE* pTempNext = pTemp->next;
		while(NULL != pTempNext)
		{
			pTemp = pTempNext;
			pTempNext = pTempNext->next;
		}	
		pTemp->next = newNode;
	}
}

void printList(LIST *vetexList)
{
	LIST_NODE *pTemp = vetexList->root;
	while(NULL != pTemp)
	{
		printf("%d, ", pTemp->value);
		pTemp = pTemp->next;
	}
}

void initArray(LIST *tree, int *data, int len)
{
	memset(tree, 0, sizeof(LIST));
	for (int i = 0; i < len; ++i)
	{
		appendToAList(tree, *(data + i));
	}
}
void initPic()
{
	int array0[] = {5, 3, 20};
	int array1[] = {3, 5, 9};
	int array2[] = {20, 5, 1, 8};
	int array3[] = {9, 3, 11, 8};
	int array4[] = {1, 20, 6};
	int array5[] = {6, 1, 8};
	int array6[] = {8, 6, 20, 9, 11};
	int array7[] = {11, 8, 9};
	int *picArray [] = {array0, array1, array2, array3, array4, array5, array6, array7};
	initArray(&pic[0], picArray[0], 3);
	initArray(&pic[1], picArray[1], 3);
	initArray(&pic[2], picArray[2], 4);
	initArray(&pic[3], picArray[3], 4);
	initArray(&pic[4], picArray[4], 3);
	initArray(&pic[5], picArray[5], 3);
	initArray(&pic[6], picArray[6], 5);
	initArray(&pic[7], picArray[7], 3);
}

void initPicture(PIC_NODE *pNode, int *data)
{
	for (int i = 0; i < NODE_SUM; ++i)
	{
		pNode[i].value = *(data + i);
		pNode[i].nodeColor = WHITE;
		pNode[i].pParent = NULL;
		pNode[i].distance = 0;
		pNode[i].pPicInfo = &pic[i];
	}
}

void Enqueue(QUEUE *pQueue, PIC_NODE *data)
{
	if (QUEUE_LEN > pQueue->count)
	{
		*(pQueue->pHead) = *data;
		pQueue->pHead++;
		pQueue->count++;
		if ((pQueue->pHead - pQueue->data) >= QUEUE_LEN)
		{
			pQueue->pHead = pQueue->data;
		}
	}
	else
	{
		printf("FIFO overflow");
	}

}

void Dequeue(QUEUE *pQueue, PIC_NODE *data)
{
	if (0 <= pQueue->count)
	{
		*data = *(pQueue->pTail);
		pQueue->pTail++;
		pQueue->count--;
		if ((pQueue->pTail - pQueue->data )>= QUEUE_LEN)
		{
			pQueue->pTail = pQueue->data;
		}
	}
	else
	{
		printf("FIFO overflow");
	}
}


void InitQueue(QUEUE* pQueue)
{
	pQueue->count = 0;
	pQueue->pHead = pQueue->data;
	pQueue->pTail = pQueue->data;
}

bool IsQueueEmpty(QUEUE *pQueue)
{
	bool result = false;
	if (0 == pQueue->count)
	{
		result = true;
	}
	else
	{
		result = false;
	}
	return result;
}

int getSeq(int data, int *pData)
{
	int pos = 0;
	for (int i = 0; i < NODE_SUM; ++i)
	{
		if (data == *(pData + i))
		{
			pos = i;
			break;
		}
	}
	return pos;
}


void BFS(PIC_NODE *pPicture)
{
	int data[] = {5, 3, 20, 9, 1, 6, 8, 11};
	initPicture(pPicture, data);
	pPicture[0].nodeColor = GRAY;
	QUEUE queue;
	InitQueue(&queue);
	Enqueue(&queue, pPicture);
	while(!IsQueueEmpty(&queue))
	{
		PIC_NODE rootNode;
		Dequeue(&queue, &rootNode);
		LIST_NODE* tempListNode = rootNode.pPicInfo->root->next;
		while(tempListNode != NULL)
		{
			int value = tempListNode->value;
			int pos = getSeq(value, data);
			PIC_NODE *tmpNode = pPicture + pos; 
			if (WHITE == tmpNode->nodeColor)
			{
				tmpNode->nodeColor = GRAY;
				tmpNode->distance += 1;
				tmpNode->pParent = &rootNode;
				Enqueue(&queue, tmpNode);
				printf("Add value: %d\n", tmpNode->value);
			}
			tempListNode = tempListNode->next;
		}
		rootNode.nodeColor = BLACK;
	}

}

int main(int argc, char const *argv[])
{
	initPic();
	BFS(picture);

	return 0;
}