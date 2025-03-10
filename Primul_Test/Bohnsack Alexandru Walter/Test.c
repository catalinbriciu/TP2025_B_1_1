#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#pragma warning(disable:4996)

#define NrMAX 10

int Stiva[NrMAX];
int nr = 0;

int IfEmpty()
{
	if (nr == 0)
		return 1;
	else
		return 0;
}

int IfFull()
{
	if (nr == NrMAX)
		return 1;
	else
		return 0;
}


void push(int x)
{
	if (!IfFull())
	{
		Stiva[nr] = x;
		nr++;
	}
	else printf("stiva este plina");
}

int pop()
{
	if (!IfEmpty())
	{
		int nr_res;
		nr_res = Stiva[nr - 1];
		nr--;
		return nr_res;

	}
	else printf("stiva este goala");

}



void main()
{
	int i;
	push(3);
	push(4);
	push(1);
	push(6);
	push(2);
	push(7);
	push(11);

	for (i = 0; i < 7; i++)
	{
		printf("\n%u\n", pop());
	}

	NrDeBitiDeUnu(Stiva, nr);
}

unsigned int NrDeBitiDeUnu(int *Stiva, unsigned char nr)
{
	int i, j;
	unsigned char NrBitiUnu = 0;
	//i-elemente; j-index pe bit;
	for (i = 0; i < nr; i++)
	{
		for (j = 0; j < 32; j++)
		{
			if (Stiva[i] & (1 << j))
			{
				NrBitiUnu++;
			}
		}
	}
}
