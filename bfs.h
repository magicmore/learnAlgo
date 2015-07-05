#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define QUEUE_LEN 10

typedef struct _LIST_NODE
{
	int value;
	struct _LIST_NODE *next;
}LIST_NODE;

typedef struct _LIST
{
	int count;
	LIST_NODE *root;
}LIST;

enum color
{
	WHITE,
	GRAY,
	BLACK
};

typedef struct _PIC_NODE
{
	int value;
	enum color nodeColor;
	int distance;
	struct _PIC_NODE *pParent;
	LIST *pPicInfo;
}PIC_NODE;

typedef struct _QUEUE
{
	PIC_NODE data[QUEUE_LEN];
	unsigned int count;
	PIC_NODE* pHead;
	PIC_NODE* pTail;
}QUEUE;

void appendToAList(LIST *vetexList, int data);
void printList(LIST *vetexList);
void initArray(LIST *tree, int *data, int len);
void initPic();
void Enqueue(QUEUE *pQueue, PIC_NODE *data);
void Dequeue(QUEUE *pQueue, PIC_NODE *data);

void initPicture(PIC_NODE *pNode, int *data);
void BFS(PIC_NODE *pPicture);