
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 10

int stiva[max];
int count = 0;

int isEmpty()
{
	if (count == 0)
		return 1;
	else
		return 0;
}

int isFull()
{
	if (count == max)
		return 1;
	else
		return 0;
}


void push(int x)
{
	if (!isFull())
	{
		stiva[count] = x;
		count++;
	}
	else printf("stiva este plina");
}

int pop()
{
	if (!isEmpty())
	{
		int res;
		res = stiva[count - 1];
		count--;
		return res;
	}
	else printf("stiva este goala");
}



unsigned int numarare_biti_1(int n)
{
	unsigned int k = 0;
	while (n) {
		k += n & 1;
		n >>= 1;
	}
	return k;
}

int main()
{
	unsigned int b,x;
	int i;
	push(1);
	push(5);
	push(3);
	push(8);
	push(9);
	push(6);
	push(4);
	for (i = 0; i < 7; i++)
	{
		printf("\n%u", pop());
	}

		while (count != 0)
		{
			x = pop();
			printf("%d", numarare_biti_1(x));
		}
		return 0;
}