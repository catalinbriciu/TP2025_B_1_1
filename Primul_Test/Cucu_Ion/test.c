#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10

int stiva[MAX];
int count = 0;

int Gol() {
	if (count == 0)
		return 1;
	else
		return 0;
}

int Plin() {
	if (count == MAX)
		return 1;
	else
		return 0;
}


void push(int x) {
	if (!Plin()) {
		stiva[count] = x;
		count++;
	}
	else printf("stiva e plina");
}

int pop() {
	if (!Gol()) {
		int res;
		res = stiva[count - 1];
		count--;
		return res;
	}
	else printf("stiva e goala");
}



int main() {
	int i,index;
	push(1); push(2); push(3); push(4); push(5); push(6); push(1000);
	for (i = 0; i < 7; i++) {
		printf("\n%u", pop());
	}
	system("pause");
	return 0;
}

unsigned char BitiDeUnu(int *stiva, unsigned char numar) {

	unsigned char BitdeUnu = 0;
	short int i, index;
	for (i = 0; i < numar; i++) {
		for (index = 0; index < 32; index++); {
			if (stiva[i] & (1 << index)) {
				BitdeUnu++;
			}
		}
	}
}