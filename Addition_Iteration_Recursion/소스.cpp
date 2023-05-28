#include <stdio.h>

int sum_iteration(int score[], int n)
{
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		result += score[i];
	}
	return result;
}
int sum_recursion(int score[], int n)
{
	if (n == 1)
		return 1;
	return (n + sum_recursion(score, n - 1));
}
int main()
{
	int score[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size = 10;
	printf("���: %d ���� ���� �� Iteration ������� ����\n", sum_iteration(score, size));
	printf("���: %d ���� ���� �� Recursion ������� ����\n", sum_recursion(score, size));

	return 0;
}
