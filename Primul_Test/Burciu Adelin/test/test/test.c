#include<stdio.h>
#include<stdlib.h>
/*Sa se implementeze urmatoarea problema:
a)  o stiva de maximum 10 elemente care contine numere intre 0 si 65000 (2.5 p)
b) stiva trebuie implementata cel mai optim prin prisma consumului de memorie (1 p)
c) se introduc in stiva 7 numere (1p)
d) pt fiecare numar scos din stiva sa se afiseze (0.5 p)
e) numarul de biti de 1 (2)
f) numarul dupa mascarea bit-ului 2 (1 p)
g) numarul dupa ce bitul 6 devine 0. (1p)
*/
void push(int stiva[], int varf, int numar) {
	varf = varf + 1;
	stiva[varf] = numar;
}

int peek(int stiva[], int varf) {
	return stiva[varf];
}
int pop(int stiva[], int varf) {
	 int i;
	for (i = varf; i >= 0; i--) {
		return stiva[varf];
	}
}

int numar_biti1(int stiva[],int varf) {
	
	short int index=0;//nr biti de 1
	while (stiva[varf] != 0) {
		if (stiva[varf] & 1 == 1)
			index++;
		stiva[varf] << 1;
	}
	return index;
}
int mascare_bit(int stiva[], int varf) {
	stiva[varf] = stiva[varf] & ~(1 << 2);
	return stiva[varf];

}

int schimbare_bit6(int stiva[], int varf) {
	stiva[varf] = stiva[varf] & ~(1 << 6);
	return stiva[varf];
}

int main() {

	unsigned int numar;
	int stiva[10];
	int varf = 0;
	 int optiune;
	do {
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.peek\n");
		printf("4.nr de biti de 1\n");
		printf("5.mascare bit 2\n");
		printf("6.Schimbare bit 6\n");
		printf("7.EXIT");
		printf("Dati optiunea:");
		scanf("%d", &optiune);
		
	} while (1);
	switch (optiune) {
	case 1:printf("dati valoare numarului:");
		scanf("%u", &numar);
		push(stiva, varf, numar);
		break;
	case 2:pop(stiva, varf);
		break;
	case 3:peek(stiva, varf);
		break;
	case 4:printf("Numarul de biti de 1 este %d", numar_biti1(stiva,varf));
		break;
	case 5:printf("Numarul dupa mascare este %d", mascare_bit(stiva, varf));
		break;
	case 6:
		break;
	case 7:exit(0);
		break;
	}
}