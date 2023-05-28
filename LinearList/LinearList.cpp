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

int deleteElement(int L[], int n, int x)				// �迭 list�� �����ּ�, size = 6, �迭�� ������ 30�� �μ��� �޴´�.
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
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
		return -1;
	}
	return L[0];
}

int Last(int L[], int n)
{
	if (n == 0)
	{
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
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
	printf("���� %d�� ���� ���Ҹ� ã�� �� �����ϴ�.\n", x);
	return -1;
}

// ������ �����̸� 1�� ��ȯ �ƴϸ� 0�� ��ȯ �� ���� ���ҿ� ������ -1��ȯ
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
	printf("���� %d�� ã�� �� �����ϴ�.\n", x);
	return -1;
}

int main(void)
{
	int list[MAX] = { 10,20,40,50,60,70 };				// ũ�Ⱑ 10�� �迭�� ����� �� ���� �迭�� �ʱ�ȭ 
	int i, move, size = 6;								
	printf("���Կ��� �� ��������Ʈ: ");
	for (i = 0; i < size; i++) printf("%3d\t", list[i]);
	printf("\n");
	printf("������ ����: %d\n", size);
	getchar();

	move = insertElement(list, size, 30);				// ���� ����
	printf("���Կ��� �� ��������Ʈ: ");
	for (i = 0; i < size + 1; i++) printf("%3d\t", list[i]);
	printf("\n");
	printf("������ ����: %d \n", ++size);
	printf("�ڸ� �̵� Ƚ��: %d\n", move);
	getchar();

	move = deleteElement(list, size, 30);				// ���� ����
	if (move == size) printf("��������Ʈ�� ���Ұ� ���� ���� �Ұ�!\n");
	else
	{
		printf("�������� �� ��������Ʈ: ");
		for (i = 0; i < size; i++) printf("%3d\t", list[i]);
		printf("\n");
		printf("������ ����: %d \n", --size);
		printf("�ڸ��̵� Ƚ��: %d\n", move);
	}
	getchar();

	printf("��������Ʈ�� ù ��° ����: %d\n", First(list, size));
	printf("��������Ʈ�� ������ ����: %d\n", Last(list, size));
	printf("���� %d�� ���� ����: %d\n", 40, Next(list, size, 40));
	printf("���� %d��(��) ������ ���Ұ� �ƴմϴ�: %d\n", 70, hasMoreElement(list, size, 70));

	return 0;
}