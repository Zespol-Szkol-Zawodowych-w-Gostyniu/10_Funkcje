// Funkcje
//

#include <iostream>
using namespace std;

int zmiennaglobalna = 3;

//typ_zwracany nazwa(parametry) {
//
//}
int dodawanie(int a, int b) {
    return a + b;
}

void fun1(int x, int y) {
    cout << dodawanie(x, y) << endl;
}
bool testPrime(int n) {
		bool p = true;
		if (n < 2) p = false;
		if ((n != 2) && (n % 2 == 0)) p = false;
		if (n != 2) {//wszystkie i>2
			for (int dzielnik=3; dzielnik< ceil(sqrt(n)); dzielnik+=2){
				if (n % dzielnik == 0) {
					p = false;
					break;
				}
			}
		}
		if (p) return true;
		else false;
}

int NWD(int, int); //prototyp funkcji - zapowiedz funkcji

void zasieg(int a) {
	int b = 2; //zmienna b ma zasięg lokalny
	cout << b << endl;
	cout << "zmienna globalna: " << zmiennaglobalna << endl;
}

void fun1(int a) {//przekazywanie parametru przez wartosc - tworzona jest kopia parametru
	a++;
	cout << a << endl;
}
void fun2(int &a) {//przekazywanie parametru przez referencję
	a++;
	cout << a << endl;
}
int powerModulo(int, int, int);
int testFermata(int, int);
int silnia(int);
int silniaIter(int);
int fibo(int);
void ciagFibo(int);
//Parametry domyslne muszą byc na końcu listy!
int fun3(int, int=10);

//Przeładowanie funkcji-użycie wielokrotnie tej samej nazwy do "różnych" funkcji.
//wiecej niż jedna funkcja o takiej samej nazwie
int fun3(long a) {
	return a  * 10;
}
//Takie coś zgłosi błąd kompilacji, bo typ zwracany przez funkcje nie ma znaczenia
//long fun3(long a) {
//	return a * 10;
//}
//Przy przeładowaniu (przeciążeniu) ma znaczenie:
//1. ilość parametrów
//2. typy parametrów
int fun3(int a, int b, int c) {
	return a + b + c;
}

int main()
{
    //cout << dodawanie(2, 3) << endl;
    //int w = 2, z = 3;
    //fun1(w, z);

	//int x = 102;
	//cout << testPrime(x) << endl;
	//x = 1011;
	//cout << testPrime(x) << endl;

	//for (int i = 1001; i < 2000; i += 2) {
	//	if (testPrime(i)) cout << i << " ";
	//}
	//cout << endl;

	/*int wynik = NWD(24, 122);
	cout << wynik << endl;*/

	//zasieg(2);
	//cout << b << endl; BŁĄD! bo b jest zmienną lokalną funkcji "zasieg"
	
	int x = 3631;
	//cout << x << endl;
	////fun1(x);
	//fun2(x);
	//cout << x << endl;

	//Referencja - przezwisko
	//int &y=x;
	//cout << x << endl;
	//y++;
	//cout << x << endl;
	//cout << powerModulo(12, 53, 7) << endl;
	
	//cout << time(NULL) << endl;
	// 
	//if (testFermata(x, 40) == 1) {
	//	cout << "Liczba "<<x<<" jest prawdopodobnie pierwsza" << endl;
	//}
	//else {
	//	cout << "Liczba " << x << " nie jest pierwsza!" << endl;
	//}

	//Rekurencja - silnia
	//cout << silnia(8) << endl;
	//cout << silniaIter(8) << endl;
	//Rekurencja - ciag Fibonacciego
	//cout << fibo(10) << endl;
	/*ciagFibo(20);*/

	//Parametry domyślne
	cout << fun3(1, 2) << endl;
	cout << fun3(1) << endl;
	long u = 3;
	cout << fun3(u) << endl;
	cout << fun3(2,4,5) << endl;
	return 0;
}

int NWD(int a, int b) {
	int i = 0;
	int w;
	while (b != 0) {
		w = b;
		b = a % b;
		a = w;
		i++;
	}
	return a;
}

//Test pierwszości - test Fermata
/*to probabilistyczny test umożliwiający sprawdzenie czy dana liczba jest złożona 
czy prawdopodobnie pierwsza
Twierdzenie
Jeśli liczba p jest liczbą pierwszą to dla każdego a takiego, że 1<=a<p  a należy do [1,p)
a^(p-1) mod p = 1
Problem: jak szybko podnosić liczbę a do potęgi i wykonać operację modulo?
Odpowiedź: algorytm szybkiego potęgowania modularnego
a^b mod n  dla a>=n
a^b mod n = (a mod n)^b
założenie: b=(bm,..b1,b0) w zapisie binarnym
a^b mod n = (a^(b0*2^0) mod n * ... * (a^(bm*2^m) mod n)
wiadomo również, że: a^2^m mod n = (a^2^(m-1)*a^2^(m-1)) mod n
oraz a mod n = (x mod n)(y mod n), gdzie a = xy
a^b mod n =(((a·a mod n)·a mod n) ... )·a mod n
Wynika z tego, że musimy przemnożyć tylko te bity, których wartość wynosi 1
Przykład:
12^53 mod 7
53=(110101)
a=12 mod 7 = 5
res=1
x=a
b0=1 -> res = 1 * 5 mod 7 = 5, x = 5 * 5 mod 7 = 4
b1=0 -> x = 4 * 4 mod 7 = 2
b2=1 -> res = 5 * 2 mod 7 = 3, x = 2 * 2 mod 7 = 4
b3=0 -> x = 4 * 4 mod 7 = 2
b4=1 -> res = 3 * 2 mod 7 = 6, x = 2 * 2 mod 7 = 4
b5=1 -> res = 6 * 4 mod 7 = 3, x = 4 * 4 mod 7 = 2
*/
//a^b mod n
int powerModulo(int a, int b, int n) {
	int res = 1;
	int x = a % n;
	for (int i = 1; i <= b; i <<= 1) {//i*=2
		x = x % n; //x%=n;
		if ((b & i) != 0) {//sprawdze czy na i-tej pozycji jest 0 czy 1 w zapisie binarnym liczby b
			res *= x;
			res %= n;//res=res%n
		}
		x *= x;
	}
	return res;
}
//a^(p-1) mod p = 1
//jeżeli return 1 to prawdopodobnie p jest pierwsze
//jeżeli return 0 to p nie jest pierwsza
int testFermata(int p, int k) {
	int a, i;
	//losowanie liczby a
	srand(time(NULL));//inicjalizacja generatora liczb pseudolosowych
	if (p <= 1) return 0;//p nie jest pierwsza
	if (p < 4) {
		return 1;//p jest pierwsza
	}
	//k - oznacza ilość losowań liczby a
	for (i = 0; i < k; i++) {
		a=(rand() % (p-1))+1; // rand()%100 -> 0-99
		cout << a << endl;
		if (powerModulo(a,p-1,p) != 1) {
			return 0;
		}
	}
	return 1;
}



//Rekurencja
//zdolność funkcji do wywoływania samej siebie
/*
Przykład - silnia
n!=(n-1)!*n
0!=1
te 2 równania stanowią definicję rekurencyjną silni
Wersja iteracyjna silni:
n!=1*2*...*n
*/
//3!=2!*3=1!*2*3=0!*1*2*3=1*2*3=6
int silnia(int n) {
	if (n == 0) return 1;
	return silnia(n - 1) * n;
}

//Ciąg liczb Fibonacciego
/*
f(n)=f(n-1)+f(n-2) dla n>2
f(1)=1
f(1)=1
lub:
f(n)=f(n-1)+f(n-2) dla n>1
f(0)=0
f(1)=1
*/

int fibo(int n) {
	if ((n == 1)||(n==2)) return 1;
	return fibo(n - 1) + fibo(n - 2);
}

//zadanie 1: Napisz funkcję która wyznaczy silnie iteracyjnie
//zadanie 2: Napisz kod który wyznaczy pierwszych 20 wyrazów ciągu Fibonacciego

int silniaIter(int n) {
	int sil = 1;
	for (int i = 1; i <= n; i++) {
		sil *= i;
	}
	return sil;
}

void ciagFibo(int x) {
	//x wyrazów ciągu Fibonacciego
	for (int i = 1; i <= x; i++) {
		cout << fibo(i) << ",";
	}
	cout << endl;
}


int fun3(int a, int b) {
	return a + b;
}
