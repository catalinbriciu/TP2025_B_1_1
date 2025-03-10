#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

//a)  o stiva de maximum 10 elemente care contine numere intre 0 si 65000 (2.5 p)
unsigned short Stiva[10];


int isEmpty(int i)
{
	if (i == 0)
		return 1;
	else
		return 0;
}

int isFull(int i)
{
	if (i == 10)
		return 1;
	else
		return 0;
}


void push(int x,int i)
{
	if (!isFull(i))
	{
		Stiva[i] = x;
		i++;
	}
	else printf("stiva este plina");
}

int pop(int i)
{
	while (!isEmpty(i))
	{
		int res;
		res = Stiva[i - 1];
		i--;
		cout << res;
	}
	printf("stiva este goala");
}

void biti(int x) {
	int i;
	for (i = 0;i < 16;i++) {
		if ((x & 1) == 1)
			cout << 1;
		x = x >> 1;
	}

}

void mascare(int i) {
	Stiva[i] = Stiva[i] & ~(1 << 2);
	cout << Stiva[i];
}

void bitul6(int i) {
	Stiva[i] = Stiva[i] & ~(1 << 6);
	cout << Stiva[i];
}
void main()
{
   
	int x,i,j,nr;
	//c) se introduc in stiva 7 numere (1p)
	for (i = 0; i < 7; i++) {
		    fin >> x;
			push(x,i);
	}
	//d) pt fiecare numar scos din stiva sa se afiseze (0.5 p)
	pop(i);
	//e) numarul de biti de 1 (2)
	
	cout << "introduceti cate numere citi:";
	cin >> nr;
	for (j = 0; j< nr; j++) {

		push(x, i);
		biti(Stiva[j]);
	}

	pop(i);
	for (i = 0; i < 7; i++) {
		fin >> x;
		push(x, i);
	}
	//f) numarul dupa mascarea bit-ului 2 (1 p)
	for (i = 0; i < 7; i++) {
		mascare(i);
	}

	//g) numarul dupa ce bitul 6 devine 0. (1p)
	for (j = 0; j < i; j++) {

		
		bitul6(j);
	}

}

