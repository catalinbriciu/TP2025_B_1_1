#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int Stack[MAX];
int vf = -1;

void push(int x)
{
	if (vf == MAX - 1)
		printf("Memorie insuficienta");
	else
		Stack[++vf] = x;
}

void pop()
{
	if (vf == -1)
		printf("stiva este goala");
	else vf--;
}


void print()
{
	int i;
	for (i = 0; i <= vf; i++)
		printf("%d ", Stack[i]);
}

int Empty()
{
	if (vf == -1)
		return 1;
	else return 0;
}
int main()
{
	int nr, i, k, ok, nr2, nr3;
	for (i = 0; i < 7; i++)
	{
		scanf("%d", &nr);
		push(nr);
	}
	while (!Empty())
	{ 
		ok = 0;
		for (i = 31; i >= 0; i--)
		{
			k = Stack[vf] >> i;
			if (k & 1)
				ok++;
		}
		if (Stack[vf] >> 2 & 1)
			nr2 = Stack[vf] - 4;
		else
			nr2 = Stack[vf];
		
		if (Stack[vf] >> 5 & 1)
			nr3 = Stack[vf] - 32;
		else
			nr3 = Stack[vf];
		printf("Numarul de biti de 1 este:%d, Nr-ul dupa mascarea bitului 2 este:%d, Nr-ul dupa ce bitul 6 devine 0 este:%d\n", ok, nr2, nr3);

			pop();
	}
	system("pause");
	return 0;
}