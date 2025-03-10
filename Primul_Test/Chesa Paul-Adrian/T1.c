#include<stdio.h>
#include<stdlib.h>

unsigned short int stack[11];
unsigned short int SP;
unsigned short int Value;

void Push(unsigned short int* Stack, unsigned short int* SP, unsigned short int Value);
void CreateStack(unsigned short int * Stack, unsigned short int * SP);
unsigned short int Pop(unsigned short int * Stack, unsigned short int *SP);
unsigned char IsStackFull(unsigned short int *SP);
unsigned char IsStackEmpty(unsigned short int *SP);

int main()
{
	CreateStack(&stack[0], &SP);
	Push(stack, &SP, 12);
	Push(stack, &SP, 2);
	Push(stack, &SP, 2500);
	Push(stack, &SP, 7);
	Push(stack, &SP, 8000);
	Push(stack, &SP, 500);
	printf("Am scos elementul %hu\n", Pop(stack, &SP));
	//printf("Numarul dupa mascare este %hu", masca(stack, &SP));
	system("pause");
	return 0;
}



void Push(unsigned short int* Stack, unsigned short int* SP, unsigned short int Value) {
	
	if (IsStackFull(&SP) == 0) {
		(*SP)++;
		*(Stack + *SP) = Value;
	}
	else
		printf("Stiva este plina!\n");
}

unsigned short int Pop(unsigned short int * Stack, unsigned short int *SP)
{
	if (IsStackEmpty(&SP) == 0)
		(*SP)--;
	else
		printf("Stiva este goala!\n");
}

unsigned char IsStackFull(unsigned short int *SP)
{
	if (*SP == 10)
		return 1;
	else
		return 0;

}

unsigned char IsStackEmpty(unsigned short int *SP)
{
	if (*SP == 0)
		return 1;
	else
		return 0;
}

void CreateStack(unsigned short int * Stack, unsigned short int * SP) {
	*SP = 0;
	for (unsigned char Index = 0; Index < 11; Index++) {
		Stack[Index] = 0;
	}
}
unsigned short int masca(unsigned short int *Stack, unsigned short int* SP)
{
	Stack[*SP] = Stack[*SP] & ~(1 << 6);
	return Stack[*SP];
}