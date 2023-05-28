#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int i;
	int n;
	int head = 0;
	int mid = 0;
	int rear = 1;

	printf("\n 피보나치 수 입력 : ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("%d ", head);
		mid = head + rear;
		head = rear;
		rear = mid;
	}

	printf("\n\n");
	system("pause");
	return 0;
}