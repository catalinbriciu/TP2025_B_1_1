#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)


unsigned short int Stiva[10];
unsigned char VarfStiva;

void Push(unsigned short int* Stiva, unsigned char* VarfStiva, unsigned short int Value);
unsigned short int Pop(unsigned short int* Stiva, unsigned char* VarfStiva);

int main() {
	InitStack(Stiva, &VarfStiva);
	system("pause");
	return 0;
}

void InitStiva(unsigned short int* Stiva, unsigned char* VarfStiva) {
	Push(Stiva, VarfStiva, 52);
	Push(Stiva, VarfStiva, 636);
	Push(Stiva, VarfStiva, 777);
	Push(Stiva, VarfStiva, 1000);
	Push(Stiva, VarfStiva, 3);
	Push(Stiva, VarfStiva, 12);
	Push(Stiva, VarfStiva, 782);
}
unsigned char Pop(unsigned char * Stiva, unsigned char *VarfStiva)
{
		return Stiva[(*VarfStiva)--];

}

void Push(unsigned short int* Stiva, unsigned char* VarfStiva, unsigned short int Value) {
	Stiva[++(*VarfStiva)] = Value;
}


//e)
unsigned char NumarareBiti(unsigned char Number) {
	unsigned char NumarareDe1 = 0;
	for (unsigned char Index = 0; Index < 16; Index++) {
		if (Number & (1 << Index)) {
			NumarareDe1++;
		}
	}
	return NumarareDe1;
}
