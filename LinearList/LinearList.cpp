#pragma once
#include <stdio.h>
#define MAX 10

int insertElement(int L[], int n, int x)
{
	int i, k = 0, move = 0;
	for (i = 0; i < n; i++)
	{
		if (L[i] <= x && x <= L[i + 1])
		{
			k = i + 1;
			break;
		}
	}
	if (i == n) k = n;
	for (i = n; i > k; i--)
	{
		L[i] = L[i - 1];
		move++;
	}
	L[k] = x;
	return move;
}

int deleteElement(int L[], int n, int x)				// 배열 list의 시작주소, size = 6, 배열에 삽입할 30을 인수로 받는다.
{
	int i, k = 0, move = 0;
	for (i = 0; i < n; i++)
	{
		if (L[i] == x)
		{
			k = i;
			break;
		}
	}
	if (i == n) move = n;
	for (i = k; i < n - 1; i++)
	{
		L[i] = L[i + 1];
		move++;
	}
	return move;
}

int First(int L[], int n)
{
	if (n == 0)
	{
		printf("리스트가 비어있습니다.\n");
		return -1;
	}
	return L[0];
}

int Last(int L[], int n)
{
	if (n == 0)
	{
		printf("리스트가 비어있습니다.\n");
		return -1;
	}
	return L[n - 1];
}

int Next(int L[], int n, int x)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (L[i] == x)
		{
			return L[i + 1];
		}
	}
	printf("원소 %d의 다음 원소를 찾을 수 없습니다.\n", x);
	return -1;
}

// 마지막 원소이면 1을 반환 아니면 0을 반환 그 값이 원소에 없으면 -1반환
int hasMoreElement(int L[], int n, int x)		
{
	for (int i = 0; i < n - 1; i++)
	{
		if (L[i] == x)
		{
			return 1;
		}
	}
	if (L[n - 1] == x)
	{
		return 0;
	}
	printf("원소 %d를 찾을 수 없습니다.\n", x);
	return -1;
}

int main(void)
{
	int list[MAX] = { 10,20,40,50,60,70 };				// 크기가 10인 배열을 만들고 그 안의 배열을 초기화 
	int i, move, size = 6;								
	printf("삽입연산 전 선형리스트: ");
	for (i = 0; i < size; i++) printf("%3d\t", list[i]);
	printf("\n");
	printf("원소의 갯수: %d\n", size);
	getchar();

	move = insertElement(list, size, 30);				// 삽입 연산
	printf("삽입연산 후 선형리스트: ");
	for (i = 0; i < size + 1; i++) printf("%3d\t", list[i]);
	printf("\n");
	printf("원소의 갯수: %d \n", ++size);
	printf("자리 이동 횟수: %d\n", move);
	getchar();

	move = deleteElement(list, size, 30);				// 삭제 연산
	if (move == size) printf("선형리스트에 원소가 없어 삭제 불가!\n");
	else
	{
		printf("삭제연산 후 선형리스트: ");
		for (i = 0; i < size; i++) printf("%3d\t", list[i]);
		printf("\n");
		printf("원소의 갯수: %d \n", --size);
		printf("자리이동 횟수: %d\n", move);
	}
	getchar();

	printf("선형리스트의 첫 번째 원소: %d\n", First(list, size));
	printf("선형리스트의 마지막 원소: %d\n", Last(list, size));
	printf("원소 %d의 다음 원소: %d\n", 40, Next(list, size, 40));
	printf("원소 %d는(은) 마지막 원소가 아닙니다: %d\n", 70, hasMoreElement(list, size, 70));

	return 0;
}