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
	
	int x = 12;
	//cout << x << endl;
	////fun1(x);
	//fun2(x);
	//cout << x << endl;

	//Referencja - przezwisko
	int &y=x;
	cout << x << endl;
	y++;
	cout << x << endl;

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