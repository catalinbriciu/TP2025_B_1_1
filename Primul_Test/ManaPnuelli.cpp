// ManaPunelli_Stiva.cpp : Defines the entry point for the console application.
//

#include "conio.h"
#include "stdio.h"
#include "stdlib.h"

#define MAX_STACK_SIZE 12u

#define no_DEBUG_MODE

void Push(unsigned char* Stack, unsigned char * SP, unsigned char ValueToAdd);
unsigned char Pop(unsigned char * Stack, unsigned char *SP);
unsigned char IsStackFull(unsigned char *SP);
unsigned char IsStackEmpty(unsigned char *SP);
void CreateStack(unsigned char * Stack, unsigned char * SP);
unsigned char ManaPnuelli(unsigned char Val);
unsigned char MyStack[MAX_STACK_SIZE];
unsigned char StackPointer;


int main()
{
	CreateStack(&MyStack[0u], &StackPointer);
	//fill here the gaps to call the function and display the value
	_getch();
	return 0;
}

void CreateStack(unsigned char * Stack, unsigned char * SP)
{
	unsigned char count;
	*SP = 0u;
	for (count = 0; count < MAX_STACK_SIZE; count++)
	{
		Stack[count] = 0xFF;
	}
}

unsigned char IsStackEmpty(unsigned char *SP)
{
	//if((*(SP)) == 0x00u) {
	//	return 1;
	//}
	//else {
	//	return 0;
	//}
	return ((*(SP)) == 0x00u);
}
unsigned char IsStackFull(unsigned char *SP)
{
#ifdef DEBUG_MODE
	if ((*SP) == (MAX_STACK_SIZE - 1u)) {
		return 1u;
	}
	else {
		return 0u; 
	}
#else
	return ((*SP) == (MAX_STACK_SIZE - 1u));
#endif
}
void Push(unsigned char* Stack, unsigned char * SP, unsigned char ValueToAdd)
{
	if (IsStackFull(SP) != 0u)
	{
		Stack[*SP] = ValueToAdd;
		*SP = *SP + 1u;
	}
	else
	{
		/*stack is full*/
	}
}

unsigned char Pop(unsigned char * Stack, unsigned char *SP)
{
	unsigned char ValToReturn = 0xFF;
	if (IsStackEmpty(SP) != 0u)
	{
		*SP = *SP - 1;
		ValToReturn = Stack[*SP];
		return ValToReturn;
	}
	else
	{
		return ValToReturn;
	}
}
unsigned char ManaPnuelli(unsigned char Val)
{
	//fill here the content of the function
	Push(&MyStack[0u], &StackPointer, Val);
	while (IsStackEmpty(&StackPointer) != 0u) {
		unsigned char myVal;
	}
	return 0; //fill here also
}



