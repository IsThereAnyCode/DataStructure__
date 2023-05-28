#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 20

typedef struct {
	int row;
	int column;
	int value;
} Term;		// 행렬의 원소

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
    Smatrix* S3 = createSmatrixInstance(); // 결과를 저장할 희소 행렬 S3 생성
    int i = 0, j = 0; // S1과 S2의 인덱스


    // S1과 S2의 모든 원소를 비교하며 S3에 추가
    while (i < S1->size && j < S2->size)
    {
        // S1의 현재 원소가 S2의 현재 원소보다 작은 경우
        if (S1->sm_term[i].row < S2->sm_term[j].row ||
            (S1->sm_term[i].row == S2->sm_term[j].row && S1->sm_term[i].column < S2->sm_term[j].column))
        {
            appendSterm(S3, S1->sm_term[i].row, S1->sm_term[i].column, S1->sm_term[i].value);
            i++;
        }
        // S1의 현재 원소가 S2의 현재 원소보다 큰 경우
        else if (S1->sm_term[i].row > S2->sm_term[j].row ||
            (S1->sm_term[i].row == S2->sm_term[j].row && S1->sm_term[i].column > S2->sm_term[j].column))
        {
            appendSterm(S3, S2->sm_term[j].row, S2->sm_term[j].column, S2->sm_term[j].value);
            j++;
        }
        // S1과 S2의 행과 열이 같은 경우
        else
        {
            int sum = S1->sm_term[i].value + S2->sm_term[j].value; // 두 원소 값을 더함
            if (sum != 0) // 더한 값이 0이 아닌 경우만 S3에 추가
                appendSterm(S3, S1->sm_term[i].row, S1->sm_term[i].column, sum);
            else
                return 0;
            i++;
            j++;
        }
    }
    // S1의 남은 원소를 S3에 추가
    while (i < S1->size)
    {
        appendSterm(S3, S1->sm_term[i].row, S1->sm_term[i].column, S1->sm_term[i].value);
        i++;
    }
    // S2의 남은 원소를 S3에 추가
    while (j < S2->size)
    {
        appendSterm(S3, S2->sm_term[j].row, S2->sm_term[j].column, S2->sm_term[j].value);
        j++;
    }
    printf("S3의 0이 아닌 항의 수: %d\n", S3->size);
    return S3; // 더한 희소 행렬을 반환
}
int main(void)
{
	Smatrix* S1 = createSmatrixInstance();	// 0이 아닌 값을 저장할 행렬 생성
    Smatrix* S2 = createSmatrixInstance();	// 0이 아닌 값을 저장할 행렬 생성

	appendSterm(S1, 0, 2, 2);				// 행, 열, 0이 아닌 값
	appendSterm(S1, 0, 6, 12);
	appendSterm(S1, 1, 4, 7);
	appendSterm(S1, 2, 0, 23);
	appendSterm(S1, 3, 3, 31);
	appendSterm(S1, 4, 1, 14);              // 행, 열, 값이 다른 항
	appendSterm(S1, 4, 5, 25);
	appendSterm(S1, 5, 6, 6);
	appendSterm(S1, 6, 0, 52);
	appendSterm(S1, 7, 4, 11);


   // printf("영이 아닌 항의 수: %d\n", S1->size);

    appendSterm(S2, 0, 3, 78);				// 행, 열, 0이 아닌 값
    appendSterm(S2, 0, 6, 12);              
    appendSterm(S2, 1, 4, 7);               
    appendSterm(S2, 2, 0, 23);             
    appendSterm(S2, 3, 3, 31);              
    appendSterm(S2, 4, 2, 99);              // 행, 열, 값이 다른 항
    appendSterm(S2, 4, 5, 25);              
    appendSterm(S2, 5, 6, 6);               
    appendSterm(S2, 6, 0, 52);              
    appendSterm(S2, 7, 4, 11);              
    appendSterm(S2, 7, 5, 65);              // 행, 열, 값이 다른 항
    appendSterm(S2, 7, 6, 84);              // 행, 열, 값이 다른 항
    
	printf("S1의 영이 아닌 항의 수: %d\n", S1->size);
    printf("S2의 영이 아닌 항의 수: %d\n\n", S2->size);

    printf("S1과 S2의 행렬 합 후의 행렬 S3\n");
    printSmatrix(addSmatrix(S1, S2));

	getchar();

	return 0;
}