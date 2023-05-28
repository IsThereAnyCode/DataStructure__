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
	printf("결과: %d 여러 수의 합 Iteration 방식으로 구현\n", sum_iteration(score, size));
	printf("결과: %d 여러 수의 합 Recursion 방식으로 구현\n", sum_recursion(score, size));

	return 0;
}
