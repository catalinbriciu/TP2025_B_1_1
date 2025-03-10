#include<stdio.h>
#include<stdlib>
#define MAX_STACK_SIZE 12u

void Push(unsigned char* Stack, unsigned char * SP, unsigned char ValueToAdd);
unsigned char Pop(unsigned char * Stack, unsigned char *SP);
unsigned char IsStackFull(unsigned char *SP);
unsigned char IsStackEmpty(unsigned char *SP);
void CreateStack(unsigned char * Stack, unsigned char * SP);
unsigned char ManaPnuelli(unsigned char Val);
unsigned char MyStack[MAX_STACK_SIZE];
unsigned char StackPointer;




int _tmain(int argc, _TCHAR* argv[])
{
	unsigned char Val;
	/*Mana Pnuelli*/
	/*f(6)*/
	CreateStack(&MyStack[0u], &StackPointer);
	Val =  ManaPnuelli(6);
	printf("%d", Val);
	_getch();
	return 0;
}