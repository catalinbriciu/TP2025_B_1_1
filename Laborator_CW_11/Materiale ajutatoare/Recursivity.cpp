// Recursivity.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"

int suma = 0;
int fact = 1;
int suma_cifrelor = 0;
int x;
//int Fibo() // can be found in courses
int cmmdc(int a, int b)
{
	if (b == 0) return a;
	else
		return cmmdc(b,a%b);
}
int InversareNumar(int n)
{
	if (n == 0) { return 0; }
	else
	{
		printf("%d", n % 10);
		return InversareNumar(n / 10);
	}
}
int ManaPnuelli(int n)
{
	if (n >= 12) return n - 1;
	else
		return ManaPnuelli(ManaPnuelli(n + 2));
}
int Suma_Cifrelor(int n)
{
	if (n < 10) {
		return n;
	}
	else {
		return n % 10 + Suma_Cifrelor(n / 10);
	}
}
int Sum( int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	else
		suma = n + Sum(n - 1);
	return suma;
}
int factorial(int n)
{
	if (n == 0) return 1;
	if (n == 1) return 1;
	else
		fact = n * factorial(n - 1);
	return fact;
}
int _tmain(int argc, _TCHAR* argv[])
{
	//printf("%d",Sum(4));
	//printf("%d", factorial(4));
	printf("%d", Suma_Cifrelor(84214));
	//printf("%d", ManaPnuelli(5));
	//printf("%l", InversareNumar(4230254));
	//printf("%d", cmmdc(15, 45));
	return 0;
}

#if 0
x = 67123567834
conditia de oprire : n < 10 --> return n;
formula de recurenta : return ((n % 10) + suma_nr(n / 10));
#endif

