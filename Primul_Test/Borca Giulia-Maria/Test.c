#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define max 10

int Stack[max];
unsigned char SP = 0;

//functie pentru adaugarea unui element in stiva
void Push(unsigned char *Stack, unsigned char *SP, unsigned char Value)
{
	if (IsStackFull(&SP) == 0)
	{
		(*SP)++;
		*(Stack + *SP) = Value;
	}
	else
		printf("Stiva este plina.\n");
}

//functie pentru scoaterea elementelor din stiva
unsigned char Pop(unsigned char *Stack, unsigned char *SP)
{
	while (IsStackEmpty(*SP) != 0)
	{
		int nr;
		nr = Stack[*SP];
		*(SP)--;
		printf("%d\n", &nr);
	}
	printf("\nStiva este goala.\n");

}

//verificam daca stiva este plina
unsigned char IsStackFull(unsigned char *SP)
{
	if (*SP == max)
		return 1;
	else
		return 0;
}

//verificam daca stiva este goala
unsigned char IsStackEmpty(unsigned char *SP)
{
	if (*SP == 0)
		return 1;
	else
		return 0;
}

void main()
{
	int i;
	push(&Stack,&SP,5);
	push(&Stack,&SP,10);
	push(&Stack,&SP,47);
	push(&Stack,&SP,59);
	push(&Stack,&SP,23);
	push(&Stack,&SP,90);
	push(&Stack,&SP,76);
	push(&Stack,&SP,100);
	for (i = 0; i < 7; i++)
	{
		printf("%u\n", Pop(&Stack, &SP));
	}
}