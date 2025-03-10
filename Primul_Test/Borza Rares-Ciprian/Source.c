#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int stiva[10];
int count = 0;

int IfEmpty(){
	if (count == 0)
		return 1;
	else
		return 0;
}

int IfFull(){
	if (count == 10)
		return 1;
	else
		return 0;
}

void push(int x){
	if (!IfFull())
	{
		stiva[count] = x;
		count++;
	}
	else printf("stiva este plina");
}

int pop(){
	if (!IfEmpty())
	{
		NrDeBitiDeUnu(stiva, count);
		int res;
		res = stiva[count - 1];
		count--;
		return res;

	}
	else printf("stiva este goala");
}
unsigned int NrDeBitiDeUnu(int* stiva, unsigned char count){
	int i, j;
	unsigned char NrBitiUnu = 0;
	//i-elemente; j-index pe bit;
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < 32; j++)
		{
			if (stiva[i] & (1 << j))
			{
				NrBitiUnu++;
			}
			
		}
		
	}
	
	printf("\nNumarul de biti de 1 este: %d\n", NrBitiUnu);
}

void main(){
	int i;
	push(69);
	push(420);
	push(42069);
	push(1308);
	push(2001);
	push(1234);
	push(11);
	for (i = 0; i < 7; i++)
	{
		
		printf("\n%u", pop());
	}
}

