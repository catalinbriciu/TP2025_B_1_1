#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)

unsigned short int Stack[10];
unsigned char StackPeak;

void Push(unsigned short int* Stack, unsigned char *StackPeak, unsigned short int Value);
unsigned short int Pop(unsigned short int* Stack, unsigned char* StackPeak);
void InitStack(unsigned short int* Stack, unsigned char* StackPeak);
void ComputeStack(unsigned short int* Stack, unsigned char* StackPeak);
unsigned char isStackEmpty(unsigned short int* Stack, unsigned char StackPeak);
unsigned char NumberOfOneBites(unsigned short int Value);
unsigned short int UnsetFlag(unsigned short int Value, unsigned char BitPozition);

int main() {
	InitStack(Stack, &StackPeak);
	ComputeStack(Stack, &StackPeak);
	system("pause");
	return 0;
}

void Push(unsigned short int* Stack, unsigned char* StackPeak, unsigned short int Value) {
	Stack[++(*StackPeak)] = Value;
}

unsigned short int Pop(unsigned short int* Stack, unsigned char* StackPeak) {
	return Stack[(*StackPeak)--];
}

void InitStack(unsigned short int* Stack, unsigned char* StackPeak) {
	Push(Stack, StackPeak, 7);
	Push(Stack, StackPeak, 10000);
	Push(Stack, StackPeak, 23456);
	Push(Stack, StackPeak, 123);
	Push(Stack, StackPeak, 4561);
	Push(Stack, StackPeak, 88);
	Push(Stack, StackPeak, 102);
}

void ComputeStack(unsigned short int* Stack, unsigned char* StackPeak) {
	unsigned short int Value;
	while (isStackEmpty(Stack, *StackPeak) == 0) {
		Value = Pop(Stack, StackPeak);
		printf("Numarul %hu: \n", Value);
		printf("1) Numarul de biti de 1: %hhu\n", NumberOfOneBites(Value));
		printf("2) Numarul dupa mascarea bitului 2 este: %hu\n", UnsetFlag(Value, 2));
		printf("3) Numarul dupa ce bitul 6 devine 0: %hu\n", UnsetFlag(Value, 6));
		printf("\n");
	}
}

unsigned char isStackEmpty(unsigned short int* Stack, unsigned char StackPeak) {
	if (StackPeak == 0) {
		return 1;
	} else {
		return 0;
	}
}

unsigned char NumberOfOneBites(unsigned short int Value) {
	unsigned char NumberOfOnes = 0;
	for (unsigned char Index = 0; Index < 16; Index++) {
		if ((Value >> Index) & 1) {
			NumberOfOnes++;
		}
	}
	return NumberOfOnes;
}

unsigned short int UnsetFlag(unsigned short int Value, unsigned char BitPozition) {
	Value &= ~(1 << BitPozition);
	return Value;
}

