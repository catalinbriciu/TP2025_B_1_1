// FormaPolonezaPostfixata_1.cpp : Defines the entry point for the console application.
//

#include "conio.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define MAX_STACK_SIZE 25u
#define TRUE 1
#define FALSE 0

typedef enum E_PRECEDENCE
{
	E_PRIO_1 = 0x00,
	E_PRIO_2 = 0x01,
	E_PRIO_3 = 0x02,
	E_MAX_PRIO = 0x03,
	E_INVALID_PRIO
};
typedef enum E_TYPE
{
	E_OPERAND,
	E_LEFT_PARANTHESIS,
	E_OPERATOR,
	E_RIGHT_PARANTHESIS,
	E_INVALID_TYPE
};

typedef struct S_MAP
{
	unsigned char identifier;
	E_PRECEDENCE precedence;
	E_TYPE type;
};

E_TYPE GetElementType(unsigned char element);
void Push(unsigned char* Stack, unsigned char * SP, unsigned char ValueToAdd);
unsigned char Pop(unsigned char * Stack, unsigned char *SP);
unsigned char IsStackFull(unsigned char *SP);
unsigned char IsStackEmpty(unsigned char *SP);
void CreateStack(unsigned char * Stack, unsigned char * SP);
void AddElementInFP(unsigned char Elem);
S_MAP GetOperatorElementInfo(unsigned char element);
void Compute_PolishForm();
int GetResultFromPolishForm();

/*-----------------------------------------------------------*/
unsigned char MyStack[MAX_STACK_SIZE];
unsigned char StackPointer;
//unsigned char Tablou[] = { 1, '-', 7, '*', 2, '/','(', 3, '+', 5, ')', '^', 2 , '^', 5};
unsigned char Tablou[] = { 5, '+', '(', 1, '+', 4, ')' };
unsigned char ProcessedElements = 0;
unsigned char FormaPoloneza[MAX_STACK_SIZE];
unsigned char NbOfElements = 0;
const S_MAP  MyHashMap[] = { { '(', E_MAX_PRIO, E_LEFT_PARANTHESIS },
{ ')', E_MAX_PRIO, E_RIGHT_PARANTHESIS },
{ '+', E_PRIO_1, E_OPERATOR },
{ '-', E_PRIO_1, E_OPERATOR },
{ '*', E_PRIO_2, E_OPERATOR },
{ '/', E_PRIO_2, E_OPERATOR },
{ '^', E_PRIO_3, E_OPERATOR },
};


int tmain(void)
{
	clock_t start, end;
	int lub_Result;
	start = clock();
	Compute_PolishForm();
	end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	lub_Result = GetResultFromPolishForm();
	_getch();
	return 0;
}
unsigned char GetFromFP(int position)
{
	return FormaPoloneza[position];

}
unsigned char GetResult(unsigned char Operand_1, unsigned char Operand_2, unsigned char Operator)
{
	unsigned char T_Operand_1, T_Operand_2;
	/*it is needed that operands to be converted to numbers from ASCII*/
	T_Operand_1 = Operand_1;// -48;
	T_Operand_2 = Operand_2;// -48;
	switch (Operator)
	{
	case '-':
		return (T_Operand_1 - T_Operand_2);
		break;
	case '+':
		return (T_Operand_1 + T_Operand_2);
		break;
	case '*':
		return (T_Operand_1 * T_Operand_2);
		break;
	case '/':
		return (T_Operand_1 / T_Operand_2);
		break;
	case '^':
		return T_Operand_1 ^ T_Operand_2;
		break;
	default:
		return 0;
	}
}
int GetResultFromPolishForm()
{
	unsigned char lub_Element;
	unsigned char lub_Result;
	unsigned char lub_Operand_1;
	unsigned char lub_Operand_2;
	int nbOfProcessedElements = 0;
	S_MAP elementInfo;
	int result = 0;
	/*init the stack*/
	CreateStack(MyStack, &StackPointer);
	/**/
	do
	{
		lub_Element = GetFromFP(nbOfProcessedElements);
		elementInfo = GetOperatorElementInfo(lub_Element);
		if (elementInfo.type == E_OPERATOR)
		{
			lub_Operand_1 = Pop(MyStack, &StackPointer);
			lub_Operand_2 = Pop(MyStack, &StackPointer);
			lub_Result = GetResult(lub_Operand_1, lub_Operand_2, lub_Element);
			Push(MyStack, &StackPointer, lub_Result);
		}
		else
		{
			if (elementInfo.type == E_OPERAND)
			{
				Push(MyStack, &StackPointer, lub_Element);
			}
			else
			{
				/*in this point, polish form is not complete*/
			}
		}
		nbOfProcessedElements++;
	} while (NbOfElements != nbOfProcessedElements);
	return Pop(MyStack, &StackPointer);
}
void Compute_PolishForm()
{
	S_MAP elementInfo;
	unsigned char ShouldStop = FALSE;
	unsigned char PoppedValue;
	unsigned char ElementToCheck;
	S_MAP elementInfoTemp;
	do
	{
		ElementToCheck = Tablou[ProcessedElements];
		elementInfo = GetOperatorElementInfo(ElementToCheck);
		/*check the element type*/
		if (E_OPERAND == elementInfo.type)
		{
			AddElementInFP(ElementToCheck);
		}
		else
		{
			/*check if the element is a left paranthesis*/
			if (E_LEFT_PARANTHESIS == elementInfo.type)
			{
				//fill in the gaps; should we push or pop the element?
			}
			else
			{
				/*check if the element is a right paranthesis*/
				if (E_RIGHT_PARANTHESIS == elementInfo.type)
				{
					ShouldStop = FALSE;
					do{
						PoppedValue = Pop(MyStack, &StackPointer);
						elementInfo = GetOperatorElementInfo(PoppedValue);
						if (E_LEFT_PARANTHESIS == elementInfo.type)
						{
							//fill in the gap; should stop or not??!?!
							
						}
						else
						{
							AddElementInFP(PoppedValue);
						}
					} while (ShouldStop == FALSE);
				}
				else
				{
					/*type is an operator*/
					ShouldStop = FALSE;
					do
					{
						elementInfo = GetOperatorElementInfo(ElementToCheck);
						if (IsStackEmpty(&StackPointer))
						{
							ShouldStop = TRUE;
						}
						else
						{
							elementInfoTemp.identifier = Pop(MyStack, &StackPointer);
							//fill in the gaps; here a get operator call is missing;
							//error is due to missing line:)
							if (elementInfoTemp.type == E_LEFT_PARANTHESIS)
							{
								ShouldStop = TRUE;
							}
							else
							{

							}
							if ((elementInfoTemp.precedence >= elementInfo.precedence) && (elementInfoTemp.identifier != elementInfo.identifier) && (ShouldStop == FALSE))
							{
								AddElementInFP(elementInfoTemp.identifier);
							}
							else
							{
								Push(MyStack, &StackPointer, elementInfoTemp.identifier);
								ShouldStop = TRUE;
							}
						}
					} while (ShouldStop == FALSE);
					//fill in the gaps here a push is missing
				}
			}
		}
		ProcessedElements++;
	} while (ProcessedElements < sizeof(Tablou));
	while (!IsStackEmpty(&StackPointer))
	{
		AddElementInFP(Pop(MyStack, &StackPointer));
	}
}
S_MAP GetOperatorElementInfo(unsigned char element)
{
	unsigned char Size;
	unsigned char count;
	S_MAP ElemInfo;
	ElemInfo.identifier = element;
	ElemInfo.type = E_OPERAND;
	ElemInfo.precedence = E_INVALID_PRIO;
	Size = sizeof(MyHashMap) / sizeof(S_MAP);
	for (count = 0; count < Size; count++)
	{
		if (MyHashMap[count].identifier == element)
		{
			ElemInfo.type = MyHashMap[count].type;
			ElemInfo.precedence = MyHashMap[count].precedence;
			return ElemInfo;
		}
	}
	return ElemInfo;
}
void AddElementInFP(unsigned char Elem)
{
	FormaPoloneza[NbOfElements] = Elem;
	NbOfElements++;
}
void CreateStack(unsigned char * Stack, unsigned char * SP)
{
	unsigned char count;
	*SP = 0u;
	for (count = 0; count < MAX_STACK_SIZE; count++)
	{
		Stack[count] = 0x00;
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
void Push(unsigned char* Stack, unsigned char * SP, unsigned char ValueToAdd)
{
	if (!IsStackFull(SP))
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
	if (!IsStackEmpty(SP))
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
