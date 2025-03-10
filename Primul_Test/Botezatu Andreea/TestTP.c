/*Sa se implementeze urmatoarea problema :
a)  o stiva de maximum 10 elemente care contine numere intre 0 si 65000 (2.5 p)
b) stiva trebuie implementata cel mai optim prin prisma consumului de memorie(1 p)
c) se introduc in stiva 7 numere(1p)
d) pt fiecare numar scos din stiva sa se afiseze(0.5 p)
e) numarul de biti de 1 (2)
f) numarul dupa mascarea bit - ului 2 (1 p)
g) numarul dupa ce bitul 6 devine 0. (1p)*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 10
unsigned short stack[MAX];
int top = -1;

int isEmpty() {

	if (top == -1)
		return 1;
	else
		return 0;
}

int isFull() {

	if (top == MAX)
		return 1;
	else
		return 0;
}


int pop() {
	unsigned short data;
	if (!isEmpty()) {
		data = stack[top];
		top = top - 1;
		return data;
	}
	else {
		printf("Stiva goala.\n");
	}
}

int push(unsigned short data) {

	if (!isFull()) {
		top = top + 1;
		stack[top] = data;
	}
	else {
		printf("Stiva plina.\n");
	}
}

int bit_1(unsigned short Number)
{
	int i, k = 0;
	for (i = 15; i >= 0; i--)
	{
		if (Number >> i & 1) k++;
	}
	return k;
}

unsigned int ClearFlag(unsigned short Number, unsigned short Position)
{
	Number = Number & ~(1 << Position);
	return Number;
}

unsigned char GetFlag(unsigned short Number, unsigned short Position)
{
	Number = 1 & (Number >> Position);
	return Number;
}




void main()
{
	int n, Biti1,Masc2,NrClear6, aux;
	printf("Dati numerele ce urmeaza sa fie introduse in stiva:\n");
	while (top < 6) {
			scanf("%d", &n);
			push(n);
		}
	
	printf("\n");
	while (top != -1)
	{
		unsigned short x = pop();
		printf("Pentru %d\n", x);
		Biti1 = bit_1(x);
		printf("Nr biti 1: %d\n", Biti1);
		Masc2 = ClearFlag(x, 2);
		printf("Dupa mascarea bitul 2: %d\n", Masc2);
		aux = GetFlag(x, 6);
		if (aux == 1) {
			x = ClearFlag(x, 6);
		}
		printf("Dupa ce bitul 6 devine 0: %d\n", x);
		printf("\n");
	}
}