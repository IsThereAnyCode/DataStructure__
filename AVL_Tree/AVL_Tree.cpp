#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct AVLNode {
	ElementType data;
	struct AVLNode* left;
	struct AVLNode* right;
	int height;
} Node;

int max(int a, int b) {
	return (a > b) ? a : b;
}

int height(Node* N) {
	if (N == NULL)
		return 0;
	return N->height;
}

Node* createNode(ElementType data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->height = 1;
	return newNode;
}

Node* rotateRight(Node* y) {
	Node* x = y->left;
	Node* T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

Node* rotateLeft(Node* x) {
	Node* y = x->right;
	Node* T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;
}

int getBalance(Node* N) {
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

Node* insertNode(Node* node, ElementType data) {
	if (node == NULL)
		return createNode(data);

	if (data < node->data)
		node->left = insertNode(node->left, data);
	else if (data > node->data)
		node->right = insertNode(node->right, data);
	else
		return node;

	node->height = 1 + max(height(node->left), height(node->right));

	int balance = getBalance(node);

	if (balance > 1 && data < node->left->data)
		return rotateRight(node);

	if (balance < -1 && data > node->right->data)
		return rotateLeft(node);

	if (balance > 1 && data > node->left->data) {
		node->left = rotateLeft(node->left);
		return rotateRight(node);
	}

	if (balance < -1 && data < node->right->data) {
		node->right = rotateRight(node->right);
		return rotateLeft(node);
	}

	return node;
}

void preOrder(Node* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main() {
	Node* root = NULL;

	root = insertNode(root, 10);
	root = insertNode(root, 20);
	root = insertNode(root, 30);
	root = insertNode(root, 40);
	root = insertNode(root, 50);
	root = insertNode(root, 25);

	printf("Preorder traversal of the AVL tree is \n");
	preOrder(root);

	return 0;
}
