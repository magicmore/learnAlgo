
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *left;
	struct _node *right;
	struct _node *parent;
}node;

typedef struct _tree
{
	int count;
	node *root;
}tree;

void insertToTree(tree *pTree, int data);
void printTree(node *pNode);
node* findNode(tree *pTree, int value);
node* getSuccessor(tree *pTree, int data);
node* getMinimum(node *currentNode);


int main(int argc, char const *argv[])
{
	tree myTree;
	node * tmpNode;
	memset(&myTree, 0, sizeof(tree));
	insertToTree(&myTree, 20);
	insertToTree(&myTree, 18);
	insertToTree(&myTree, 25);
	insertToTree(&myTree, 2);
	insertToTree(&myTree, 13);
	insertToTree(&myTree, 6);
	insertToTree(&myTree, 1);
	insertToTree(&myTree, 19);
	insertToTree(&myTree, 21);
	//printTree(myTree.root);
	tmpNode = getSuccessor(&myTree, 25);

	if (NULL != tmpNode)
	{
		printf("data: %d\n", tmpNode->data);
	}
	else
	{
		printf("Null Node.\n");
	}
	//printTree(myTree.root);
	return 0;
}

void printTree(node *pNode)
{
	if (pNode != NULL)
	{
		printTree(pNode->left);
		printf("%d, ", pNode->data);
		printTree(pNode->right);
	}
}

void insertToTree(tree *pTree, int data)
{
	node *nodeToAppend = (node *)malloc(sizeof(node));
	nodeToAppend->parent = NULL;
	nodeToAppend->left = NULL;
	nodeToAppend->right = NULL;
	nodeToAppend->data = data;
	node *pCurrentNode = pTree->root;
	node *pHighNode = NULL;

	while(NULL != pCurrentNode)
	{
	 	pHighNode = pCurrentNode;
	 	if (data < pCurrentNode->data)
	 	{
	 		pCurrentNode = pCurrentNode->left;
	 		//printf("add to left.\n");
	 	}
	 	else
	 	{
	 		pCurrentNode = pCurrentNode->right;
	 	}
	}
	nodeToAppend->parent = pHighNode;
	if (NULL == pHighNode)
	{
		pTree->root = nodeToAppend;
	}
	else
	{
		 if (data < pHighNode->data)
		 {
		 	pHighNode->left = nodeToAppend;
		 }
		 else
		 {
		 	pHighNode->right = nodeToAppend;
		 }
	}	
	pTree->count ++; 	
}

node* findNode(tree *pTree, int data)
{
	node *currentNode = pTree->root;
	while(NULL != currentNode && currentNode->data != data)
	{
		if (data < currentNode->data)
		{
			currentNode = currentNode->left;
		}
		else
		{
			currentNode = currentNode->right;
		}
	}
	return currentNode;
}


node* getMinimum(node *currentNode)
{
	node *pNodeTmp = NULL;
	while(NULL != currentNode)
	{
		pNodeTmp = currentNode;
		currentNode = currentNode->left;
	}
	return pNodeTmp;
}

node* getSuccessor(tree *pTree, int data)
{
	node *currentNode = findNode(pTree, data);
	node *pTmp = NULL;
	if (NULL != currentNode->right)
	{
		pTmp = getMinimum(currentNode->right);
	}
	else
	{
		pTmp = currentNode;
		currentNode = currentNode->parent;
		printf("currentNode: %d\n", currentNode->data);
		while(currentNode != NULL && pTmp == currentNode->right)
		{
			pTmp = currentNode;
			currentNode = currentNode->parent;
			//printf("currentNode: %d\n", currentNode->data);
		}
		pTmp = currentNode;
	}
	return pTmp;
}

void deleteNode(tree *pTree, int data)
{
	node *currentNode = findNode(pTree, data);
	if (NULL == currentNode->left)
	{
		/* code */
	}
}
