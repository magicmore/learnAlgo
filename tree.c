
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

int main(int argc, char const *argv[])
{
	tree myTree;
	node * tmpNode;
	memset(&myTree, 0, sizeof(tree));
	insertToTree(&myTree, 20);
	insertToTree(&myTree, 18);
	insertToTree(&myTree, 21);
	insertToTree(&myTree, 2);
	tmpNode = findNode(&myTree, 3);
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

node* getSuccessor(tree *pTree, int data)
{
	node *currentNode = findNode(data);
}

void deleteNode(tree *pTree, int data)
{

}
