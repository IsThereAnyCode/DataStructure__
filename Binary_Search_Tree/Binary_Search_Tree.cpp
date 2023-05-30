#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct BSTNode {
	ElementType data;
	struct BSTNode* left;
	struct BSTNode* right;
} Node;
 
// 노드 생성
Node* BST_CreateNode(ElementType newData) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return NULL;
	else {
		newNode->data = newData;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
}

// 동적할당 해제
void BST_DestroyNode(Node* node) {
	free(node);
}

// 트리 삭제
void BST_DestroyTree(Node* tree) {
	if (tree->right != NULL) BST_DestroyNode(tree->right);
	if (tree->left != NULL) BST_DestroyNode(tree->left);
	tree->left = NULL;
	tree->right = NULL;
	BST_DestroyNode(tree);
}

// 이진 탐색
Node* BST_SearchNode(Node* tree, ElementType searchData)
{
	if (tree == NULL) return NULL;
	if (tree->data < searchData) return BST_SearchNode(tree->left, searchData);
	else if (tree->data > searchData) return BST_SearchNode(tree->right, searchData);
	else return tree;
}

// 최소값 이진 탐색
Node* BST_SearchMinNode(Node* tree)	// BST의 조건은 왼쪽에 있는 수가 오른쪽에 있는 수보다 작다는 조건이 있다.
{
	if (tree == NULL) return NULL;
	if (tree->left == NULL)  return tree;
	else return BST_SearchMinNode(tree->left);
}

// 노드 삽입
void BST_InsertNode(Node* tree, Node* childNode)
{
	if (tree->data < childNode->data)
	{
		if (tree->right == NULL)
			tree->right = childNode;
		else
			BST_InsertNode(tree->right, childNode);
	}
	else if (tree->data > childNode->data)
	{
		if (tree->left == NULL)
			tree->left = childNode;
		else
			BST_InsertNode(tree->left, childNode);
	}
}

// 노드 삭제
Node* BST_DeleteNode(Node* tree, Node* parent, ElementType targetData)
{
	Node* removedNode = NULL;
	if (tree == NULL) return NULL;
	if (tree->data > targetData)
		removedNode = BST_DeleteNode(tree->left, tree, targetData);
	else if (tree->data < targetData)
		removedNode = BST_DeleteNode(tree->right, tree, targetData);
	else
	{
		removedNode = tree;
		if (tree->left == NULL && tree->right == NULL)	// Case1 : 자식노드가 하나도 없는 경우
		{
			if (parent->left == tree)
				parent->left = NULL;					// Case1-1
			else
				parent->right = NULL;					// Case1-2
		}
		else
		{
			if (tree->left != NULL && tree->right != NULL) // Case2 : 자식노드가 둘 다 있는 경우
			{
				Node* minNode = BST_SearchMinNode(tree->right);
				minNode = BST_DeleteNode(tree, NULL, minNode->data);
				tree->data = minNode->data;
			}
			else										// Case3 : 자식노드가 왼쪽 또는 오른쪽 하나만 있는 경우
			{
				Node* temp = NULL;
				if (tree->left != NULL)
					temp = tree->left;
				else
					temp = tree->right;

				if (parent->left == tree)
					parent->left = temp;
				else
					parent->right = temp;
			}
		}
	}
	return removedNode;
}

// 중위 순회
void BST_InorderPrintTree(Node* node)
{
	if (node == NULL)
		return;
	BST_InorderPrintTree(node->left);
	printf("%d ", node->data);
	BST_InorderPrintTree(node->right);
}

int main(void)
{
	Node* T = BST_CreateNode(123);
	Node* N = NULL;

	BST_InsertNode(T, BST_CreateNode(22));
	BST_InsertNode(T, BST_CreateNode(99));
	BST_InsertNode(T, BST_CreateNode(42));
	BST_InsertNode(T, BST_CreateNode(17));
	BST_InsertNode(T, BST_CreateNode(3));
	BST_InsertNode(T, BST_CreateNode(98));
	BST_InsertNode(T, BST_CreateNode(34));
	BST_InsertNode(T, BST_CreateNode(76));
	BST_InsertNode(T, BST_CreateNode(31));
	BST_InsertNode(T, BST_CreateNode(1));
	BST_InorderPrintTree(T);
	printf("\n"); getchar();

	printf("Removing 98...\n");
	N = BST_DeleteNode(T, NULL, 98);
	BST_InorderPrintTree(T);
	printf("\n"); getchar();

	BST_DestroyTree(T);
	return 0;
}