#include <stdio.h>
#include <stdlib.h>

#define MaxTerm 10

typedef struct {
	int expon;		// 지수 exponent
	double coeff;	// 계수 coefficient
} Sterm;

typedef struct {
	int Nterm;				// 항의 개수
	Sterm term[MaxTerm];	// 항을 저장하는 배열
} Spolynomial;

Spolynomial* createSpolynomial()
{
	Spolynomial* S = (Spolynomial*)malloc(sizeof(Spolynomial));
	if (S == NULL) return (Spolynomial*)NULL;
	S->Nterm = 0;
	return S;
}
void appendSterm(Spolynomial* Sp1, int expo, double coef)
{
	Sp1->Nterm++;
	Sterm St1;
	St1.expon = expo;
	St1.coeff = coef;
	Sp1->term[Sp1->Nterm - 1] = St1;
}

void printSpolynomial(Spolynomial* S)
{
	if (S->Nterm == 0)
		return;
	for (int i = 0; i < S->Nterm; i++)
		printf("%lfx^%d\n", S->term[i].coeff, S->term[i].expon);
	printf("\n\n\n");
}

Spolynomial* addSpolynomial(Spolynomial* S1, Spolynomial* S2)
{	
	int Nterm = 0, pos1 = 0, pos2 = 0, pos3 = 0;
	Spolynomial* S3 = createSpolynomial();

	Sterm* ptr1 = S1->term + pos1;
	Sterm* ptr2 = S2->term + pos2;
	Sterm* ptr3 = S3->term + pos3;

	while (pos1 != S1->Nterm || pos2 != S2->Nterm)
	{
		if (ptr1->expon > ptr2->expon || pos1 == S1->Nterm)
		{
			S3->term[pos3].expon = S1->term[pos1].expon;
			S3->term[pos3].coeff = S1->term[pos1].coeff;
			ptr3++, pos3++;
			ptr1++, pos1++;
		}
		else if (ptr1->expon < ptr2->expon || pos2 == S2->Nterm)
		{
			S3->term[pos3].expon = S2->term[pos2].expon;
			S3->term[pos3].coeff = S2->term[pos2].coeff;
			ptr3++, pos3++;
			ptr2++, pos2++;
		}
		else
		{
			S3->term[pos3].expon = S2->term[pos2].expon;
			S3->term[pos3].coeff = S1->term[pos1].coeff + S2->term[pos2].coeff;
			ptr3++, pos3++;
			ptr1++, pos1++;
			ptr2++, pos2++;
		}
		Nterm++;
	}

	S3->Nterm = Nterm;
	return S3;
}

int main()
{
	Spolynomial* Sp1 = createSpolynomial();
	appendSterm(Sp1, 1000, 0.1);
	appendSterm(Sp1, 10, 0.2);
	appendSterm(Sp1, 0, 0.3);
	printf("다항식1: \n");
	printSpolynomial(Sp1);

	Spolynomial* Sp2 = createSpolynomial();
	appendSterm(Sp2, 1000, 0.1);
	appendSterm(Sp2, 10, -0.2);
	appendSterm(Sp2, 1, 0.3);
	printf("다항식2: \n");
	printSpolynomial(Sp2);

	
	Spolynomial* Sp3 = addSpolynomial(Sp1, Sp2);
	printf("다항식1 + 다항식2: \n");
	printSpolynomial(Sp3);
	

	return 0;
}