#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode {
	double coef;			// 계수
	int expo;				// 지수
	struct LinkedNode* next;
}Term;

typedef struct LinkedList {
	Term* head;
}Polynomial;

Polynomial* createPolynomial()
{
	Polynomial* P = (Polynomial*)malloc(sizeof(Polynomial));
	if (P == NULL) return NULL;
	P->head = NULL;
	return P;
}

Term* createTerm(int expo, double coef)
{
	Term* N = (Term*)malloc(sizeof(Term));
	if (N == NULL)return NULL;
	N->expo = expo;
	N->coef = coef;
	N->next = NULL;
	return N;
}

void appendTerm(Polynomial* L, int E, double C)
{
	Term* N = createTerm(E, C);
	Term* p;
	if (L->head == NULL) {
		L->head = N; return;
	}
	else {
		p = L->head;
		while (p->next != NULL) p = p->next;
		p->next = N;
	}
}

void printPolynomial(Polynomial* L)
{
	if (L->head == NULL) return;
	Term* p = L->head;
	while (p != NULL) {
		printf("%lf^%d\n", p->coef, p->expo);
		p = p->next;
	}
}

Polynomial* addPolynomial(Polynomial* P1, Polynomial* P2)
{
	Polynomial* P3 = createPolynomial();
	Term* p1 = P1->head, * p2 = P2->head;

	while (p1 != NULL && p2 != NULL)
	{
		if (p1->expo > p2->expo)
		{
			appendTerm(P3, p1->expo, p1->coef);
			p1 = p1->next;
		}
		else if (p1->expo < p2->expo)
		{
			appendTerm(P3, p2->expo, p2->coef);
			p2 = p2->next;
		}
		else
		{
			double sum_coef = p1->coef + p2->coef;
			if (sum_coef != 0) {
				appendTerm(P3, p1->expo, sum_coef);
			}
			p1 = p1->next;
			p2 = p2->next;
		}
	}

	while (p1 != NULL)
	{
		appendTerm(P3, p1->expo, p1->coef);
		p1 = p1->next;
	}

	while (p2 != NULL)
	{
		appendTerm(P3, p2->expo, p2->coef);
		p2 = p2->next;
	}

	return P3;
}


int main()
{
	Polynomial* L1 = createPolynomial();
	appendTerm(L1, 100, 0.1);
	appendTerm(L1, 10, 0.2);
	appendTerm(L1, 1, 0.3);
	printPolynomial(L1); printf("\n\n\n");

	Polynomial* L2 = createPolynomial();
	appendTerm(L2, 1000, 0.1);
	appendTerm(L2, 10, 0.3);
	appendTerm(L2, 0, 0.5);
	printPolynomial(L2); printf("\n\n\n");

	Polynomial* L3 = createPolynomial();
	printPolynomial(L3); printf("\n\n\n");

	Polynomial* L4 = addPolynomial(L1, L2);
	printPolynomial(L4); printf("\n\n\n");
	return 0;
}
