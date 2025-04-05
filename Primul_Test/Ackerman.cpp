// Ackerman.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

#define MAX_STACK_SIZE 12u

typedef struct AckermanStack
{
	unsigned char X;
	unsigned char Y;
};

void Push(AckermanStack* Stack, unsigned char * SP, unsigned char ValueToAdd);
AckermanStack Pop(AckermanStack* Stack, unsigned char *SP);
unsigned char IsStackFull(unsigned char *SP);
unsigned char IsStackEmpty(unsigned char *SP);
void CreateStack(AckermanStack * Stack, unsigned char * SP);
unsigned char Ackerman(AckermanStack Val);
AckermanStack MyStack[MAX_STACK_SIZE];
unsigned char StackPointer;


int main(void)
{
	unsigned char Val;
	AckermanStack Values;
	Values.X = 2;
	Values.Y = 1;
	CreateStack(&MyStack[0u], &StackPointer);
	Val = Ackerman(Values);
	printf("%d", Val);
	_getch();
	return 0;
}

void CreateStack(AckermanStack * Stack, unsigned char * SP)
{
	unsigned char count;
	*SP = 0u;
	for (count = 0; count < MAX_STACK_SIZE; count++)
	{
		Stack[count].X = 0x00;
		Stack[count].Y = 0x00;
	}
}

unsigned char IsStackEmpty(unsigned char *SP)
{
	return ((*(SP)) == 0x00u);
}
unsigned char IsStackFull(unsigned char *SP)
{
	return ((*SP) == (MAX_STACK_SIZE - 1u));
}
void Push(AckermanStack* Stack, unsigned char * SP, unsigned char ValueToAddOnX, unsigned char ValueToAddOnY)
{
	if (!IsStackFull(SP))
	{
		Stack[*SP].X = ValueToAddOnX;
		Stack[*SP].Y = ValueToAddOnY;
		*SP = *SP + 1u;
	}
	else
	{
		/*stack is full*/
	}
}

AckermanStack Pop(AckermanStack * Stack, unsigned char *SP)
{
	AckermanStack ValToReturn;
	ValToReturn.X = 0xFF;
	ValToReturn.Y = 0xFF;
	if (!IsStackEmpty(SP))
	{
		*SP = *SP - 1;
		ValToReturn.X = Stack[*SP].X;
		ValToReturn.Y = Stack[*SP].Y;
		return ValToReturn;
	}
	else
	{
		return ValToReturn;
	}
}
unsigned char Ackerman(AckermanStack Val)
{
	unsigned char ManaPnuelliStop = 0;
	AckermanStack PopVal_1;
	AckermanStack PopVal_2;
	Push(&MyStack[0], &StackPointer, Val.X, Val.Y);
	while (1)
	{
		PopVal_1 = Pop(&MyStack[0u], &StackPointer);
		if (PopVal_1.X != 0x00 && PopVal_1.Y != 0x00)
		{
			Push(&MyStack[0], &StackPointer, PopVal_1.X, PopVal_1.Y);
			//fill in the gaps; one line is missing
		}
		else
		{
			if (PopVal_1.Y == 0)
			{
				Push(&MyStack[0], &StackPointer, PopVal_1.X - 1, 1u);
			}
			else
			{
				if (PopVal_1.X == 0)
				{
					if (IsStackEmpty(&StackPointer))
					{
						return PopVal_1.Y + 1u;
					}
					else
					{
						//fill in the gaps; two lines are missing
					}
				}
			}
		}
	}
}