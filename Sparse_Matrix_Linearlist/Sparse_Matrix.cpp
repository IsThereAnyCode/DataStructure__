#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 20

typedef struct {
	int row;
	int column;
	int value;
} Term;		// ����� ����

typedef struct {
	int size;
	Term sm_term[MaxSize];
} Smatrix;

Smatrix* createSmatrixInstance()
{
	Smatrix* sm1 = (Smatrix*)malloc(sizeof(Smatrix));
	if (sm1 == NULL) return NULL;
	sm1->size = 0;

	return sm1;
}

void appendSterm(Smatrix* S, int row, int column, int value)
{
	int size = S->size++;
	S->sm_term[size].row = row;
	S->sm_term[size].column = column;
	S->sm_term[size].value = value;
}

void printSmatrix(Smatrix* S)
{
	for (int i = 0; i < S->size; i++)
		printf("%d %d %d \n", S->sm_term[i].row, S->sm_term[i].column, S->sm_term[i].value);
}

Smatrix* addSmatrix(Smatrix* S1, Smatrix* S2)
{
    Smatrix* S3 = createSmatrixInstance(); // ����� ������ ��� ��� S3 ����
    int i = 0, j = 0; // S1�� S2�� �ε���


    // S1�� S2�� ��� ���Ҹ� ���ϸ� S3�� �߰�
    while (i < S1->size && j < S2->size)
    {
        // S1�� ���� ���Ұ� S2�� ���� ���Һ��� ���� ���
        if (S1->sm_term[i].row < S2->sm_term[j].row ||
            (S1->sm_term[i].row == S2->sm_term[j].row && S1->sm_term[i].column < S2->sm_term[j].column))
        {
            appendSterm(S3, S1->sm_term[i].row, S1->sm_term[i].column, S1->sm_term[i].value);
            i++;
        }
        // S1�� ���� ���Ұ� S2�� ���� ���Һ��� ū ���
        else if (S1->sm_term[i].row > S2->sm_term[j].row ||
            (S1->sm_term[i].row == S2->sm_term[j].row && S1->sm_term[i].column > S2->sm_term[j].column))
        {
            appendSterm(S3, S2->sm_term[j].row, S2->sm_term[j].column, S2->sm_term[j].value);
            j++;
        }
        // S1�� S2�� ��� ���� ���� ���
        else
        {
            int sum = S1->sm_term[i].value + S2->sm_term[j].value; // �� ���� ���� ����
            if (sum != 0) // ���� ���� 0�� �ƴ� ��츸 S3�� �߰�
                appendSterm(S3, S1->sm_term[i].row, S1->sm_term[i].column, sum);
            else
                return 0;
            i++;
            j++;
        }
    }
    // S1�� ���� ���Ҹ� S3�� �߰�
    while (i < S1->size)
    {
        appendSterm(S3, S1->sm_term[i].row, S1->sm_term[i].column, S1->sm_term[i].value);
        i++;
    }
    // S2�� ���� ���Ҹ� S3�� �߰�
    while (j < S2->size)
    {
        appendSterm(S3, S2->sm_term[j].row, S2->sm_term[j].column, S2->sm_term[j].value);
        j++;
    }
    printf("S3�� 0�� �ƴ� ���� ��: %d\n", S3->size);
    return S3; // ���� ��� ����� ��ȯ
}
int main(void)
{
	Smatrix* S1 = createSmatrixInstance();	// 0�� �ƴ� ���� ������ ��� ����
    Smatrix* S2 = createSmatrixInstance();	// 0�� �ƴ� ���� ������ ��� ����

	appendSterm(S1, 0, 2, 2);				// ��, ��, 0�� �ƴ� ��
	appendSterm(S1, 0, 6, 12);
	appendSterm(S1, 1, 4, 7);
	appendSterm(S1, 2, 0, 23);
	appendSterm(S1, 3, 3, 31);
	appendSterm(S1, 4, 1, 14);              // ��, ��, ���� �ٸ� ��
	appendSterm(S1, 4, 5, 25);
	appendSterm(S1, 5, 6, 6);
	appendSterm(S1, 6, 0, 52);
	appendSterm(S1, 7, 4, 11);


   // printf("���� �ƴ� ���� ��: %d\n", S1->size);

    appendSterm(S2, 0, 3, 78);				// ��, ��, 0�� �ƴ� ��
    appendSterm(S2, 0, 6, 12);              
    appendSterm(S2, 1, 4, 7);               
    appendSterm(S2, 2, 0, 23);             
    appendSterm(S2, 3, 3, 31);              
    appendSterm(S2, 4, 2, 99);              // ��, ��, ���� �ٸ� ��
    appendSterm(S2, 4, 5, 25);              
    appendSterm(S2, 5, 6, 6);               
    appendSterm(S2, 6, 0, 52);              
    appendSterm(S2, 7, 4, 11);              
    appendSterm(S2, 7, 5, 65);              // ��, ��, ���� �ٸ� ��
    appendSterm(S2, 7, 6, 84);              // ��, ��, ���� �ٸ� ��
    
	printf("S1�� ���� �ƴ� ���� ��: %d\n", S1->size);
    printf("S2�� ���� �ƴ� ���� ��: %d\n\n", S2->size);

    printf("S1�� S2�� ��� �� ���� ��� S3\n");
    printSmatrix(addSmatrix(S1, S2));

	getchar();

	return 0;
}