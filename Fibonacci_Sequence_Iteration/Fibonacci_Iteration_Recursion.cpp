#include <stdio.h>

// Iteration
/*
int main() {
    int n, first = 0, second = 1, next;

    printf("�� ���� ���� ����ұ��? ");
    scanf_s("%d", &n);

    printf("�Ǻ���ġ ����: ");

    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        }
        else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }

    return 0;
}
*/

// Recursion
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    printf("�� ���� ���� ����ұ��? ");
    scanf_s("%d", &n);

    printf("�Ǻ���ġ ����: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}
