#include<stdio.h>
#include<stdlib.h>
typedef struct stiva {
	unsigned short int nr;
	struct stiva *urm;
}nod;
nod *adaugare(nod *prim, unsigned short int numar)
{
	nod *p, *q;
	p = (nod*)malloc(sizeof(nod));
	p->nr = numar;
	p->urm = NULL;
	if (prim == NULL)
		prim = p;
	else
	{
		q = prim;
		while (q->urm != NULL)
			q = q->urm;
		p->urm = q->urm;
		q->urm = p;
	}
	return prim;
}
nod *stergere(nod *prim)
{
	nod *q;
	if (prim != NULL)
	{
		q = prim;
		prim = prim->urm;
		free(q);
		return prim;
	}
	else
		return prim;
}
int biti_1(unsigned short int numar)
{
	int nr_biti = 0, k, contor;
	for (contor = 16; contor >= 0; contor--)
	{
		k = (numar >> contor) & 1;
		if (k)
			nr_biti++;
	}
	return nr_biti;
}
unsigned short UnsetFlag(unsigned short int number, unsigned char position)
{
	number = number & ~(1 << position);
	return number;
}
void main()
{
	nod *prim = NULL, *q = NULL;
	int contor;
	prim = adaugare(prim, 5);
	prim = adaugare(prim, 6);
	prim = adaugare(prim, 7);
	prim = adaugare(prim, 57);
	prim = adaugare(prim, 1001);
	prim = adaugare(prim, 99);
	prim = adaugare(prim, 22);
	q = prim;
	while (q != NULL) {
		printf("\nNumarul %hu, %d biti de 1, %hu dupa mascarea bitului 2, %hu dupa ce bitul 6 devine 0\n", q->nr, biti_1(q->nr), UnsetFlag(q->nr, 2), UnsetFlag(q->nr, 6));
		q = q->urm;
	}
	for (contor = 1; contor <= 7; contor++)
		prim = stergere(prim);
}