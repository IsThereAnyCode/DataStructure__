#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct BtreeNode {
	element data;
	struct BtreeNode* leftchild;
	struct BtreeNode* rightchild;
} Node;
typedef struct Btree {
	struct BtreeNode* root;
} Btree;

Node* createNode(element data)
{
	Node* N = (Node*)malloc(sizeof(Node));
	if (N == NULL) return NULL;
	N->data = data;
	N->leftchild = NULL;
	N->rightchild = NULL;
	return N;
}

Btree* createBtree()
{
	Btree* Bt = (Btree*)malloc(sizeof(Btree));
	if (Bt == NULL) return NULL;
	Bt->root = NULL;
	return Bt;
}

Btree* makeBtree(Btree* Bt, Node* N, Node* left, Node* right)
{
	Bt->root = N;
	Bt->root->leftchild = left;
	Bt->root->rightchild = right;
	return Bt;
}

void printBtree_preordertraversal(BtreeNode* root)
{
	if (root == NULL) return;
	else {
		printf("%c", root->data);
		printBtree_preordertraversal(root->leftchild);
		printBtree_preordertraversal(root->rightchild);
	}
}
void printBtree_inordertraversal(BtreeNode* root)
{
	if (root == NULL) return;
	else {
		printBtree_inordertraversal(root->leftchild);
		printf("%c", root->data);
		printBtree_inordertraversal(root->rightchild);
	}
}
void printBtree_postordertraversal(BtreeNode* root)
{
	if (root == NULL) return;
	else {
		printBtree_postordertraversal(root->leftchild);
		printBtree_postordertraversal(root->rightchild);
		printf("%c", root->data);
	}
}

int main(void)
{
	Node* N7 = createNode('D');
	Node* N6 = createNode('C');
	Node* N5 = createNode('B');
	Node* N4 = createNode('A');
	Node* N3 = createNode('/');
	Node* N2 = createNode('*');
	Node* N1 = createNode('-');

	Btree* Bt = createBtree();
	if (Bt == NULL) return (int)NULL;
	makeBtree(Bt, N2, N4, N5);
	makeBtree(Bt, N3, N6, N7);
	makeBtree(Bt, N1, N2, N3);

	printBtree_preordertraversal(Bt->root);	printf("\n");
	printBtree_inordertraversal(Bt->root); printf("\n");
	printBtree_postordertraversal(Bt->root); printf("\n");

	return 0;
}